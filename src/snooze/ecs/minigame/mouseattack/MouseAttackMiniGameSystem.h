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
    void OnMiniGameStart() override;
    void OnMiniGameStop() override;

    void OnEntityClickedEvent(const forge::builtin::EntityClickedEvent& _event);

private:
    forge::Entity::Ptr m_Key;
    forge::Entity::Ptr m_Lock;
    forge::Entity::Ptr m_ChainFront;
    forge::Entity::Ptr m_ChainBack;

    bool    m_KeyAcquired;
    bool    m_MouseAttackUnlocked;

};
