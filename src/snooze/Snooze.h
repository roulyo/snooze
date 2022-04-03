#pragma once

#include <forge/engine/game/Game.h>

#include <snooze/GameEvents.h>

//----------------------------------------------------------------------------
class Snooze : public forge::AbstractForgeGame
{
public:
    static bool IsGameCompleted();

public:
    Snooze();
    ~Snooze() override;

    void OnInit() override;
    void OnQuit() override;

private:
    void OnStartMiniGameRequestEvent(const StartMiniGameRequestEvent& _event);
    void OnStopMiniGameRequestEvent(const StopMiniGameRequestEvent& _event);
    void OnGameOverRequestedEvent(const GameOverRequestedEvent& _event);
    void OnGameOverEvent(const GameOverEvent& _event);
    void OnRetryRequestedEvent(const RetryRequestedEvent& _event);
    void OnQuitRequestedEvent(const QuitRequestedEvent& _event);

private:
    forge::Vector<ComponentId>  m_MiniGames;
    ComponentId                 m_CurrentGame;

};
