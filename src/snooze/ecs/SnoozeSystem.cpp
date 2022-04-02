#include <snooze/Precomp.h>
#include <snooze/ecs/SnoozeSystem.h>
#include <snooze/data/DataList.h>

#include <snooze/data/SpriteCatalog.h>
#include <forge/engine/data/api/DataAPI.h>
#include <forge/engine/camera/api/CameraAPI.h>
#include <forge/engine/math/Types.h>


#include <iostream>

//----------------------------------------------------------------------------
static constexpr f32 INVALID_COORD = NAN;
static constexpr forge::Vector2f INVALID_CLICK_COORD { INVALID_COORD,
                                                       INVALID_COORD };

static constexpr u32 FULL_TIMER_MS = 10000;

//----------------------------------------------------------------------------
void SnoozeSystem::OnStart()
{
    m_ClickData.IsPressed = false;
    m_ClickData.Entity = NULL;

    forge::builtin::EntityClickedEvent::Handlers +=
        forge::builtin::EntityClickedEvent::Handler(this, &SnoozeSystem::OnEntityClickedEvent);
}

//----------------------------------------------------------------------------
void SnoozeSystem::OnStop()
{
    forge::builtin::EntityClickedEvent::Handlers -=
        forge::builtin::EntityClickedEvent::Handler(this, &SnoozeSystem::OnEntityClickedEvent);
}

//----------------------------------------------------------------------------
void SnoozeSystem::Execute(const u64& _dt, const forge::Entity::Ptr& _entity)
{
    // first start hack: x != nan but y == nan
    {
        if (m_ClickData.Entity && std::isnan(m_ClickData.Entity->GetPosition().y))
        {
            SnoozableComponent& snoozeComp = _entity->GetComponent<SnoozableComponent>();
            snoozeComp.GetTimer().Start(FULL_TIMER_MS);
            //m_ClickData.Coord = INVALID_CLICK_COORD;

            return;
        }
    }

    forge::FloatBox entityAABB({ _entity->GetPosition(), _entity->GetSize() });

    SnoozableComponent& snoozeComp = _entity->GetComponent<SnoozableComponent>();
    forge::builtin::RenderableComponent& renderComp =
        _entity->GetComponent<forge::builtin::RenderableComponent>();

    // click button
    if (_entity == m_ClickData.Entity && m_ClickData.IsPressed && !snoozeComp.IsPressed())
    {
        renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::AlarmButtonPressedSprite));
        snoozeComp.SetPressed(true);
    }
    // release button
    else if (_entity == m_ClickData.Entity && !m_ClickData.IsPressed && snoozeComp.IsPressed())
    {
        std::cout << "SNOOZE!" << std::endl;

        renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::AlarmButtonNeutralSprite));

        snoozeComp.GetTimer().Start(FULL_TIMER_MS);
        snoozeComp.SetPressed(false);
    }

    m_ClickData.Entity = NULL;
}

bool SnoozeSystem::IsStandingBy() const
{
    return m_ClickData.Entity && std::isnan(m_ClickData.Entity->GetPosition().x);
}

//----------------------------------------------------------------------------
void SnoozeSystem::OnEntityClickedEvent(const forge::builtin::EntityClickedEvent& _event)
{
    m_ClickData.IsPressed = _event.GetIsPressed();
    m_ClickData.Entity = _event.GetEntity();
}
