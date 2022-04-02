#include <snooze/Precomp.h>
#include <snooze/ecs/minigame/BaseMiniGame.h>

#include <snooze/GameEvents.h>

//----------------------------------------------------------------------------
void BaseMiniGame::Update(BaseMiniGameComponent& _miniGameComp)
{
    if (!_miniGameComp.IsStarted())
    {
        OnMiniGameStart();
        _miniGameComp.SetStarted(true);
    }
}

//----------------------------------------------------------------------------
void BaseMiniGame::CompleteGame(BaseMiniGameComponent& _miniGameComp)
{
    MiniGameCompletedEvent::Broadcast();
    OnMiniGameStop();
    _miniGameComp.SetStarted(false);
}

//----------------------------------------------------------------------------
void BaseMiniGame::OnMiniGameStart()
{}

//----------------------------------------------------------------------------
void BaseMiniGame::OnMiniGameStop()
{}