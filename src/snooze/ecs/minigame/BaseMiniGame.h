#pragma once

#include <forge/engine/world/EntityControlAgent.h>

#include <snooze/ecs/minigame/BaseMiniGameComponent.h>

//----------------------------------------------------------------------------
class BaseMiniGame : public forge::EntityControlAgent
{
protected:
    void Update(BaseMiniGameComponent& _miniGameComp);
    void CompleteGame(BaseMiniGameComponent& _miniGameComp);

    virtual void OnMiniGameStart();
    virtual void OnMiniGameStop();

};
