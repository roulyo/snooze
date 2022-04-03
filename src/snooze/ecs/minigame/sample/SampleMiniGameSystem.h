#pragma once

#include <forge/engine/ecs/System.h>
#include <forge/engine/time/Chrono.h>

#include <forge/builtin/3Cs/events/MouseEvent.h>

#include <snooze/ecs/minigame/BaseMiniGame.h>
#include <snooze/ecs/minigame/sample/SampleMiniGameComponent.h>

//----------------------------------------------------------------------------
class SampleMiniGameSystem : public BaseMiniGame
                           , public forge::System<SampleMiniGameComponent>
{
public:
    SampleMiniGameSystem();

    void Execute(const u64& _dt, const forge::Entity::Ptr& _entity) override;

private:
    void Reset();

    void OnMiniGameStart() override;
    void OnMiniGameStop() override;

    void OnEntityClickedEvent(const forge::builtin::EntityClickedEvent& _event);

    static const int numberOfVariants = 3;

private:
    forge::Entity::Ptr m_Tool;
    forge::Entity::Ptr m_Problem;

    bool      m_ToolAcquired;
    u8        m_Cleaning;
    forge::Pair<forge::Entity::Ptr, forge::Entity::Ptr> m_Variants[numberOfVariants];
};
