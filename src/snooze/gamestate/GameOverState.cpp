#include <snooze/Precomp.h>
#include <snooze/gamestate/GameOverState.h>

#include <forge/engine/game/Game.h>

//----------------------------------------------------------------------------
GameOverState::GameOverState(const forge::AbstractForgeGame& _game)
    : AbstractGameState(_game)
{
    AddSystem(&m_RenderingSystem);

    AddViewController(&m_ViewController);
}

//----------------------------------------------------------------------------
void GameOverState::OnStart()
{
    SetInputMapping(m_InputMapping);
}

//----------------------------------------------------------------------------
void GameOverState::OnStop()
{
    ResetInputMapping();
}
