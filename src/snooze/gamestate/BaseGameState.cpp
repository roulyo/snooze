#include <snooze/Precomp.h>
#include <snooze/gamestate/BaseGameState.h>

#include <forge/engine/game/Game.h>

//----------------------------------------------------------------------------
BaseGameState::BaseGameState(const forge::AbstractForgeGame& _game)
    : AbstractGameState(_game)
{
    AddSystem(&m_HoveringSystem);
    AddSystem(&m_SoundClickingSystem);
    AddSystem(&m_SampleMiniGameSystem);
    AddSystem(&m_PadlockMiniGameSystem);
    AddSystem(&m_MouseAttackMiniGameSystem);
    AddSystem(&m_BatteryMiniGameSystem);
    AddSystem(&m_VerminsMiniGameSystem);
    AddSystem(&m_SnoozeSystem);
    AddSystem(&m_RefereeSystem);
    AddSystem(&m_RenderingSystem);
    AddSystem(&m_ScreenMappingSystem);

    AddViewController(&m_ViewController);
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
