#include <snooze/Precomp.h>
#include <snooze/ecs/SnoozeSystem.h>

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
    m_ClickData.Coord = { 0.0f, INVALID_COORD };

    forge::builtin::MouseClickEvent::Handlers +=
        forge::builtin::MouseClickEvent::Handler(this, &SnoozeSystem::OnMouseClickEvent);
}

//----------------------------------------------------------------------------
void SnoozeSystem::OnStop()
{
    forge::builtin::MouseClickEvent::Handlers -=
        forge::builtin::MouseClickEvent::Handler(this, &SnoozeSystem::OnMouseClickEvent);
}

//----------------------------------------------------------------------------
void SnoozeSystem::Execute(const u64& _dt, const forge::Entity::Ptr& _entity)
{
    // first start hack: x != nan but y == nan
    {
        if (std::isnan(m_ClickData.Coord.y))
        {
            SnoozableComponent& snoozeComp = _entity->GetComponent<SnoozableComponent>();
            snoozeComp.GetTimer().Start(FULL_TIMER_MS);
            m_ClickData.Coord = INVALID_CLICK_COORD;

            return;
        }
    }

    forge::FloatBox entityAABB({ _entity->GetPosition(), _entity->GetSize() });

    SnoozableComponent& snoozeComp = _entity->GetComponent<SnoozableComponent>();
    forge::builtin::RenderableComponent& renderComp =
        _entity->GetComponent<forge::builtin::RenderableComponent>();

    if (entityAABB.Contains(forge::CameraAPI::ScreenPointToWorld(m_ClickData.Coord)))
    {
        // click button
        if (m_ClickData.IsPressed && !snoozeComp.IsPressed())
        {
            renderComp.GetSprite()->SetOverlayColor({ 255, 255, 255, 100 });
            snoozeComp.SetPressed(true);
        }
        // release button
        else if (!m_ClickData.IsPressed && snoozeComp.IsPressed())
        {
            std::cout << "SNOOZE!" << std::endl;

            renderComp.GetSprite()->SetOverlayColor({ 255, 255, 255, 255 });

            snoozeComp.GetTimer().Start(FULL_TIMER_MS);
            snoozeComp.SetPressed(false);

        }
    }

    m_ClickData.Coord = INVALID_CLICK_COORD;
}

bool SnoozeSystem::IsStandingBy() const
{
    return std::isnan(m_ClickData.Coord.x);
}

//----------------------------------------------------------------------------
void SnoozeSystem::OnMouseClickEvent(const forge::builtin::MouseClickEvent& _event)
{
    m_ClickData.IsPressed = _event.GetIsPressed();
    m_ClickData.Coord = { static_cast<f32>(_event.GetX()),
                          static_cast<f32>(_event.GetY()) };
}
