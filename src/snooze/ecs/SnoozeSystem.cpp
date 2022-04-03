#include <snooze/Precomp.h>
#include <snooze/ecs/SnoozeSystem.h>
#include <snooze/data/DataList.h>

#include <snooze/data/SpriteCatalog.h>
#include <forge/engine/data/api/DataAPI.h>
#include <forge/engine/camera/api/CameraAPI.h>
#include <forge/engine/math/Types.h>

#include <snooze/SnoozeConfig.h>

//----------------------------------------------------------------------------
static constexpr f32 INVALID_COORD = NAN;
static constexpr forge::Vector2f INVALID_CLICK_COORD { INVALID_COORD,
                                                       INVALID_COORD };

//----------------------------------------------------------------------------
void SnoozeSystem::OnStart()
{
    m_IsStarted = false;
    m_IsPostMiniGame = false;
    m_ClickData.IsPressed = false;
    m_ClickData.Entity = nullptr;

    forge::builtin::EntityClickedEvent::Handlers +=
        forge::builtin::EntityClickedEvent::Handler(this, &SnoozeSystem::OnEntityClickedEvent);

    MiniGameCompletedEvent::Handlers +=
        MiniGameCompletedEvent::Handler(this, &SnoozeSystem::OnMiniGameCompletedEvent);
}

//----------------------------------------------------------------------------
void SnoozeSystem::OnStop()
{
    MiniGameCompletedEvent::Handlers -=
        MiniGameCompletedEvent::Handler(this, &SnoozeSystem::OnMiniGameCompletedEvent);

    forge::builtin::EntityClickedEvent::Handlers -=
        forge::builtin::EntityClickedEvent::Handler(this, &SnoozeSystem::OnEntityClickedEvent);
}

//----------------------------------------------------------------------------
void SnoozeSystem::Execute(const u64& _dt, const forge::Entity::Ptr& _entity)
{
    // first start hack: x != nan but y == nan
    {
        if (!m_IsStarted)
        {
            SnoozableComponent& snoozeComp = _entity->GetComponent<SnoozableComponent>();
            snoozeComp.GetTimer().Start(SnoozeConfig::TimerMaxTimeMs);
            m_ClickData.Entity = nullptr;
            m_IsStarted = true;

            return;
        }
    }

    forge::FloatBox entityAABB({ _entity->GetPosition(), _entity->GetSize() });

    SnoozableComponent& snoozeComp = _entity->GetComponent<SnoozableComponent>();
    forge::builtin::RenderableComponent& renderComp =
        _entity->GetComponent<forge::builtin::RenderableComponent>();

    // click button
    if (   snoozeComp.IsClickable() && _entity == m_ClickData.Entity
        && m_ClickData.IsPressed && !snoozeComp.IsPressed())
    {
        renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::AlarmButtonPressedSprite));
        snoozeComp.SetPressed(true);
    }
    // release button
    else if (   snoozeComp.IsClickable() && _entity == m_ClickData.Entity
             && !m_ClickData.IsPressed && snoozeComp.IsPressed())
    {
        renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::AlarmButtonNeutralSprite));

        snoozeComp.GetTimer().Start(SnoozeConfig::TimerMaxTimeMs);
        snoozeComp.SetPressed(false);

        ButtonPushedEvent::Broadcast(m_IsPostMiniGame);
        m_IsPostMiniGame = false;
    }

    m_ClickData.Entity = nullptr;
}

bool SnoozeSystem::IsStandingBy() const
{
    return m_ClickData.Entity != nullptr && std::isnan(m_ClickData.Entity->GetPosition().x);
}

//----------------------------------------------------------------------------
void SnoozeSystem::OnEntityClickedEvent(const forge::builtin::EntityClickedEvent& _event)
{
    m_ClickData.IsPressed = _event.GetIsPressed();
    m_ClickData.Entity = _event.GetEntity();
}

//----------------------------------------------------------------------------
void SnoozeSystem::OnMiniGameCompletedEvent(const MiniGameCompletedEvent& _event)
{
    m_IsPostMiniGame = true;
}
