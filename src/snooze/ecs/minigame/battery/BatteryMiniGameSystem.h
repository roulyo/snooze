#pragma once

#include <forge/engine/ecs/System.h>
#include <forge/engine/time/Chrono.h>

#include <forge/builtin/3Cs/events/MouseEvent.h>

#include <snooze/ecs/minigame/BaseMiniGame.h>
#include <snooze/ecs/minigame/battery/BatteryMiniGameComponent.h>

//----------------------------------------------------------------------------
class BatteryMiniGameSystem : public BaseMiniGame
                            , public forge::System<BatteryMiniGameComponent>
{
public:
    BatteryMiniGameSystem();

    void Execute(const u64& _dt, const forge::Entity::Ptr& _entity) override;

private:
    void Reset();

    void OnMiniGameStart() override;
    void OnMiniGameStop() override;

    void OnEntityClickedEvent(const forge::builtin::EntityClickedEvent& _event);

private:
    forge::Entity::Ptr m_OpenAlarm;
    forge::Entity::Ptr m_Screw;
    forge::Entity::Ptr m_Screwdriver;
    forge::Entity::Ptr m_Mouse;
    forge::Entity::Ptr m_Battery;
    forge::Entity::Ptr m_BatteryContainer;

    bool    m_gameSolved;
    bool    m_screwdriverPicked;
    bool    m_alarmOpened;
    bool    m_mouseIsAlive;
    bool    m_batteryCollected;

    forge::Chrono   m_EndGameTimer;

};
