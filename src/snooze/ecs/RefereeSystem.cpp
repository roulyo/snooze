#include <snooze/Precomp.h>
#include <snooze/ecs/RefereeSystem.h>

//----------------------------------------------------------------------------
void RefereeSystem::OnStart()
{
    m_MiniGameIsCompleted = false;

    MiniGameCompletedEvent::Handlers +=
        MiniGameCompletedEvent::Handler(this, &RefereeSystem::OnMiniGameCompletedEvent);
}

//----------------------------------------------------------------------------
void RefereeSystem::OnStop()
{
    MiniGameCompletedEvent::Handlers -=
        MiniGameCompletedEvent::Handler(this, &RefereeSystem::OnMiniGameCompletedEvent);
}

//----------------------------------------------------------------------------
void RefereeSystem::Execute(const u64& _dt, const forge::Entity::Ptr& _entity)
{
    SnoozableComponent& comp = _entity->GetComponent<SnoozableComponent>();

    if (comp.GetTimer().IsElapsed())
    {
        GameOverEvent::Broadcast();
    }
    else if (comp.GetTimer().GetElapsedRatio() > 0.75)
    {
        if (comp.IsClickable())
        {
            StartMiniGameRequestEvent::Broadcast();
            comp.SetClickable(false);
        }
    }

    if (m_MiniGameIsCompleted)
    {
        // TODO: Display narration here
        comp.SetClickable(false);
        m_MiniGameIsCompleted = false;
    }

}

//----------------------------------------------------------------------------
void RefereeSystem::OnMiniGameCompletedEvent(const MiniGameCompletedEvent& _event)
{
    StopMiniGameRequestEvent::Broadcast();
    m_MiniGameIsCompleted = true;
}
