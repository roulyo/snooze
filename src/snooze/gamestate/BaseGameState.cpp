#include <snooze/Precomp.h>
#include <snooze/gamestate/BaseGameState.h>

#include <forge/engine/game/Game.h>

//----------------------------------------------------------------------------
BaseGameState::BaseGameState(const forge::AbstractForgeGame& _game)
    : AbstractGameState(_game)
{
    AddSystem(&m_SnoozeSystem);
    AddSystem(&m_RenderingSystem);
}

//----------------------------------------------------------------------------
void BaseGameState::OnStart()
{
    SetInputMapping(m_InputMapping);
}

//----------------------------------------------------------------------------
void BaseGameState::OnStop()
{
    ResetInputMapping();
}
