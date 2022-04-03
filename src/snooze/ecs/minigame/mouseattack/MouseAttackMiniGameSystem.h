#pragma once

#include <forge/engine/ecs/System.h>
#include <forge/engine/time/Chrono.h>

#include <forge/builtin/3Cs/events/MouseEvent.h>

#include <snooze/ecs/minigame/BaseMiniGame.h>
#include <snooze/ecs/minigame/mouseattack/MouseAttackMiniGameComponent.h>

//----------------------------------------------------------------------------
class MouseAttackMiniGameSystem : public BaseMiniGame
                                , public forge::System<MouseAttackMiniGameComponent>
{
public:
    MouseAttackMiniGameSystem();

    void Execute(const u64& _dt, const forge::Entity::Ptr& _entity) override;

private:
    void Reset();

    void OnMiniGameStart() override;
    void OnMiniGameStop() override;

    void OnEntityClickedEvent(const forge::builtin::EntityClickedEvent& _event);

private:
    forge::Entity::Ptr m_SnoozeButton;
    forge::Entity::Ptr m_Screw;
    forge::Entity::Ptr m_Smoke;
    forge::Entity::Ptr m_BbqMouse;
    forge::Entity::Ptr m_WetMouse;
    forge::Entity::Ptr m_OpenAlarm;
    forge::Entity::Ptr m_WaterGlass;

    bool    m_gameSolved;
    bool    m_alarmOpened;
    bool    m_fireStopped;
    bool    m_gotWater;

};
