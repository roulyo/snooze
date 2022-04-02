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
    void OnMiniGameStart() override;
    void OnMiniGameStop() override;

    void OnEntityClickedEvent(const forge::builtin::EntityClickedEvent& _event);

private:
    forge::Entity::Ptr m_Broom;
    forge::Entity::Ptr m_Web;

    bool    m_BroomAcquiered;
    u8      m_WebCleaning;

};
