#pragma once

#include <forge/engine/game/GameState.h>

#include <forge/builtin/rendering/SimpleRenderingSystem.h>
#include <forge/builtin/3Cs/ScreenMappingSystem.h>

#include <snooze/ecs/HoveringSystem.h>

#include <snooze/gamestate/BaseInputMapping.h>
#include <snooze/presentation/GameOverViewController.h>

//----------------------------------------------------------------------------
class GameOverState : public forge::AbstractGameState
{
    FRG__DECL_GAMESTATE(GameOverState);

public:
    GameOverState(const forge::AbstractForgeGame& _game);

    void OnStart() override;
    void OnStop() override;

private:
    forge::builtin::SimpleRenderingSystem   m_RenderingSystem;

    GameOverViewController                  m_ViewController;
    BaseInputMapping                        m_InputMapping;

};
