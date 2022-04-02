#pragma once

#include <forge/engine/ecs/System.h>
#include <forge/engine/time/Chrono.h>

#include <snooze/ecs/minigame/BaseMiniGame.h>
#include <snooze/ecs/minigame/padlock/PadlockMiniGameComponent.h>

//----------------------------------------------------------------------------
class PadlockMiniGameSystem : public BaseMiniGame
                            , public forge::System<PadlockMiniGameComponent>
{
public:
    void Execute(const u64& _dt, const forge::Entity::Ptr& _entity) override;

private:
    void OnMiniGameStart() override;
    void OnMiniGameStop() override;

private:
    forge::Chrono   m_Chrono;

};
