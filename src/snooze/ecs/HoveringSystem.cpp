#include <snooze/Precomp.h>
#include <snooze/ecs/HoveringSystem.h>

#include <forge/engine/presentation/api/PresentationAPI.h>
#include <forge/engine/window/Cursor.h>

#include <snooze/SnoozeConfig.h>

static forge::Cursor::CPtr s_Cursors[3];

//----------------------------------------------------------------------------
void HoveringSystem::OnStart()
{
    s_Cursors[0] = forge::Cursor::Arrow;
    s_Cursors[1] = forge::Cursor::Hand;
    s_Cursors[2] = forge::Cursor::Cross;

    forge::builtin::EntityHoveredEnterEvent::Handlers +=
        forge::builtin::EntityHoveredEnterEvent::Handler(this, &HoveringSystem::OnEntityHoveredEnterEvent);
    forge::builtin::EntityHoveredExitEvent::Handlers +=
        forge::builtin::EntityHoveredExitEvent::Handler(this, &HoveringSystem::OnEntityHoveredExitEvent);
}

//----------------------------------------------------------------------------
void HoveringSystem::OnStop()
{
    forge::builtin::EntityHoveredEnterEvent::Handlers -=
        forge::builtin::EntityHoveredEnterEvent::Handler(this, &HoveringSystem::OnEntityHoveredEnterEvent);
    forge::builtin::EntityHoveredExitEvent::Handlers -=
        forge::builtin::EntityHoveredExitEvent::Handler(this, &HoveringSystem::OnEntityHoveredExitEvent);
}

//----------------------------------------------------------------------------
void HoveringSystem::Execute(const u64& _dt, const forge::Entity::Ptr& _entity)
{
    auto it = m_HoveringEvents.begin();

    while (it != m_HoveringEvents.end())
    {
        if (it->HoveredEntity == _entity)
        {
            if (it->Entered)
            {
                forge::PresentationAPI::SetCursor(s_Cursors[_entity->GetComponent<HoverableComponent>().GetCursorType()]);
            }
            else
            {
                forge::PresentationAPI::SetCursor(forge::Cursor::Arrow);
            }

            it = m_HoveringEvents.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

//----------------------------------------------------------------------------
void HoveringSystem::OnEntityHoveredEnterEvent(const forge::builtin::EntityHoveredEnterEvent& _event)
{
    HoveringEventData hoveringEvent;
    hoveringEvent.Entered = true;
    hoveringEvent.HoveredEntity = _event.GetEntity();

    m_HoveringEvents.push_back(hoveringEvent);
}

//----------------------------------------------------------------------------
void HoveringSystem::OnEntityHoveredExitEvent(const forge::builtin::EntityHoveredExitEvent& _event)
{
    HoveringEventData hoveringEvent;
    hoveringEvent.Entered = false;
    hoveringEvent.HoveredEntity = _event.GetEntity();

    m_HoveringEvents.push_back(hoveringEvent);
}
