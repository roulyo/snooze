#include <snooze/Precomp.h>
#include <snooze/ecs/RefereeSystem.h>

#include <math.h>

#include <snooze/SnoozeConfig.h>

//----------------------------------------------------------------------------
void RefereeSystem::OnStart()
{
    m_MiniGameSpawned = false;
    m_MiniGameIsCompleted = false;
    m_EndGameReached = false;

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

    if (m_EndGameReached)
    {
        if (comp.IsClickable())
        {
            comp.GetTimer().Start(SnoozeConfig::PostGameTimeMs);
            comp.SetClickable(false);
        }

        if (comp.GetTimer().IsElapsed())
        {
            comp.GetTimer().Stop();
            GameOverRequestedEvent::Broadcast(true);
        }

        return;
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
    m_EndGameReached = true;
}
