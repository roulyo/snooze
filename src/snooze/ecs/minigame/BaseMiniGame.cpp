#include <snooze/Precomp.h>
#include <snooze/ecs/minigame/BaseMiniGame.h>

#include <snooze/GameEvents.h>

//----------------------------------------------------------------------------
void BaseMiniGame::Update(BaseMiniGameComponent& _miniGameComp)
{
    if (!_miniGameComp.IsStarted())
    {
        GameOverRequestedEvent::Handlers +=
            GameOverRequestedEvent::Handler(this, &BaseMiniGame::OnGameOverRequestedEvent);
        OnMiniGameStart();
        _miniGameComp.SetStarted(true);
    }
    else if (m_ShutdownRequest.GameOver)
    {
        CompleteGame(_miniGameComp);
    }
}

//----------------------------------------------------------------------------
void BaseMiniGame::CompleteGame(BaseMiniGameComponent& _miniGameComp)
{
    MiniGameCompletedEvent::Broadcast();
    OnMiniGameStop();
    _miniGameComp.SetStarted(false);

    if (m_ShutdownRequest.GameOver)
    {
        GameOverEvent::Broadcast(m_ShutdownRequest.IsGameSuccessful);

        m_ShutdownRequest.IsGameSuccessful = false;
        m_ShutdownRequest.GameOver = false;
    }

    GameOverRequestedEvent::Handlers -=
        GameOverRequestedEvent::Handler(this, &BaseMiniGame::OnGameOverRequestedEvent);
}

//----------------------------------------------------------------------------
void BaseMiniGame::OnMiniGameStart()
{}

//----------------------------------------------------------------------------
void BaseMiniGame::OnMiniGameStop()
{}

//----------------------------------------------------------------------------
void BaseMiniGame::OnGameOverRequestedEvent(const GameOverRequestedEvent& _event)
{
    m_ShutdownRequest.IsGameSuccessful = _event.GetIsSuccessful();
    m_ShutdownRequest.GameOver = true;
}
