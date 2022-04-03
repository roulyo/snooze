#pragma once

#include <forge/engine/ecs/System.h>
#include <forge/engine/time/Chrono.h>

#include <forge/builtin/3Cs/events/MouseEvent.h>

#include <snooze/ecs/minigame/BaseMiniGame.h>
#include <snooze/ecs/minigame/vermins/VerminsMiniGameComponent.h>

//----------------------------------------------------------------------------
class VerminsMiniGameSystem : public BaseMiniGame
                            , public forge::System<VerminsMiniGameComponent>
{
public:
    VerminsMiniGameSystem();

    void Execute(const u64& _dt, const forge::Entity::Ptr& _entity) override;

private:
    void Reset();

    void OnMiniGameStart() override;
    void OnMiniGameStop() override;

    void OnEntityClickedEvent(const forge::builtin::EntityClickedEvent& _event);

private:
    const u32                                              m_TimeToVermin;
    u8                                                     m_MaxVermins;
    bool                                                   m_ToolAcquired;
    bool                                                   m_FirstRun;
    forge::Entity::Ptr                                     m_Tool;
    forge::Vector<forge::Pair<forge::Entity::Ptr, bool>>   m_Vermins;
    forge::Chrono                                          m_Timer;
};
