#include <snooze/Precomp.h>
#include <snooze/ecs/RefereeSystem.h>

#include <math.h>

#include <snooze/SnoozeConfig.h>

//----------------------------------------------------------------------------
void RefereeSystem::OnStart()
{
    m_MiniGameSpawned = false;
    m_MiniGameIsCompleted = false;

    MiniGameCompletedEvent::Handlers +=
        MiniGameCompletedEvent::Handler(this, &RefereeSystem::OnMiniGameCompletedEvent);
    StoryCompletedEvent::Handlers +=
        StoryCompletedEvent::Handler(this, &RefereeSystem::OnStoryCompletedEvent);
}

//----------------------------------------------------------------------------
void RefereeSystem::OnStop()
{
    MiniGameCompletedEvent::Handlers -=
        MiniGameCompletedEvent::Handler(this, &RefereeSystem::OnMiniGameCompletedEvent);
    StoryCompletedEvent::Handlers -=
        StoryCompletedEvent::Handler(this, &RefereeSystem::OnStoryCompletedEvent);
}

//----------------------------------------------------------------------------
void RefereeSystem::Execute(const u64& _dt, const forge::Entity::Ptr& _entity)
{
    SnoozableComponent& comp = _entity->GetComponent<SnoozableComponent>();

    if (!comp.GetTimer().IsStarted())
    {
        return;
    }

    if (m_EndGameTimer.IsStarted())
    {
        if (comp.IsClickable())
        {
            comp.SetClickable(false);
        }

        if (m_EndGameTimer.IsElapsed())
        {
            GameOverRequestedEvent::Broadcast(true);
            m_EndGameTimer.Stop();
        }
    }

    if (comp.GetTimer().IsElapsed())
    {
        comp.GetTimer().Stop();
        GameOverRequestedEvent::Broadcast(false);
    }
    else if (   (   !std::isnan(comp.ForceMiniGameAtRatio)
                 && comp.GetTimer().GetElapsedRatio() > comp.ForceMiniGameAtRatio)
             || comp.GetTimer().GetElapsedRatio() > SnoozeConfig::MiniGameTimeRatioToSpawn)
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

        comp.ForceMiniGameAtRatio = NAN;
    }
}

//----------------------------------------------------------------------------
void RefereeSystem::OnMiniGameCompletedEvent(const MiniGameCompletedEvent& _event)
{
    StopMiniGameRequestEvent::Broadcast();
    m_MiniGameIsCompleted = true;
}

//----------------------------------------------------------------------------
void RefereeSystem::OnStoryCompletedEvent(const StoryCompletedEvent& _event)
{
    m_EndGameTimer.Start(2000);
}
