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
    FRG__DECL_GAMESTATE(SimpleGameState);

public:
    GameOverState(const forge::AbstractForgeGame& _game);

    void OnStart() override;
    void OnStop() override;

private:
    HoveringSystem                          m_HoveringSystem;

    forge::builtin::SimpleRenderingSystem   m_RenderingSystem;
    forge::builtin::ScreenMappingSystem     m_ScreenMappingSystem;

    GameOverViewController                  m_ViewController;
    BaseInputMapping                        m_InputMapping;

};
