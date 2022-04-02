#pragma once

#include <forge/engine/game/GameState.h>

#include <forge/builtin/rendering/SimpleRenderingSystem.h>

#include <snooze/ecs/SnoozeSystem.h>
#include <snooze/gamestate/BaseInputMapping.h>

//----------------------------------------------------------------------------
class BaseGameState : public forge::AbstractGameState
{
    FRG__DECL_GAMESTATE(SimpleGameState);

public:
    BaseGameState(const forge::AbstractForgeGame& _game);

    void OnStart() override;
    void OnStop() override;

private:
    SnoozeSystem                            m_SnoozeSystem;
    forge::builtin::SimpleRenderingSystem   m_RenderingSystem;

    BaseInputMapping                        m_InputMapping;

};
