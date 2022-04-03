#include <snooze/Precomp.h>
#include <snooze/gamestate/GameOverState.h>

#include <iostream>

#include <forge/engine/game/Game.h>

//----------------------------------------------------------------------------
GameOverState::GameOverState(const forge::AbstractForgeGame& _game)
    : AbstractGameState(_game)
{
    AddSystem(&m_HoveringSystem);
    AddSystem(&m_RenderingSystem);
    AddSystem(&m_ScreenMappingSystem);

    std::cout << "entered gameover state" << std::endl;
    AddViewController(&m_ViewController);
}

//----------------------------------------------------------------------------
void GameOverState::OnStart()
{
    std::cout << "gameoverstate onstart" << std::endl;
    SetInputMapping(m_InputMapping);
}

//----------------------------------------------------------------------------
void GameOverState::OnStop()
{
    ResetInputMapping();
}
