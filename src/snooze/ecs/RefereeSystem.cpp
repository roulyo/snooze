#include <snooze/Precomp.h>
#include <snooze/ecs/RefereeSystem.h>

#include <snooze/SnoozeConfig.h>

//----------------------------------------------------------------------------
void RefereeSystem::OnStart()
{
    m_MiniGameSpawned = false;
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

    if (comp.GetTimer().IsStarted() && comp.GetTimer().IsElapsed())
    {
        comp.GetTimer().Stop();
        GameOverEvent::Broadcast();
    }
    else if (comp.GetTimer().IsStarted() && comp.GetTimer().GetElapsedRatio() > SnoozeConfig::MiniGameTimeRatioToSpawn)
    {
        if (!m_MiniGameSpawned)
        {
            StartMiniGameRequestEvent::Broadcast();
            comp.SetClickable(false);
            m_MiniGameSpawned = true;
        }
    }
    else if (m_MiniGameSpawned)
    {
        m_MiniGameSpawned = false;
    }

    if (m_MiniGameIsCompleted)
    {
        // TODO: Display narration here
        comp.SetClickable(true);
        m_MiniGameIsCompleted = false;
    }
}

//----------------------------------------------------------------------------
void RefereeSystem::OnMiniGameCompletedEvent(const MiniGameCompletedEvent& _event)
{
    StopMiniGameRequestEvent::Broadcast();
    m_MiniGameIsCompleted = true;
}
