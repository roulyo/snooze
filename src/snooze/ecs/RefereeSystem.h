#pragma once

#include <forge/engine/ecs/System.h>
#include <forge/engine/time/api/TimeAPI.h>

#include <snooze/ecs/SnoozableComponent.h>
#include <snooze/GameEvents.h>

//----------------------------------------------------------------------------
class RefereeSystem : public forge::System<SnoozableComponent>
{
public:
    void OnStart() override;
    void OnStop() override;

    void Execute(const u64& _dt, const forge::Entity::Ptr& _entity) override;

private:
    void OnMiniGameCompletedEvent(const MiniGameCompletedEvent& _event);
    void OnStoryCompletedEvent(const StoryCompletedEvent& _event);

private:
    bool            m_MiniGameSpawned;
    bool            m_MiniGameIsCompleted;

    bool            m_EndGameReached;

};
