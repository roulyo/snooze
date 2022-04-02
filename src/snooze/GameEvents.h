#pragma once

#include <forge/engine/event/Event.h>

//------------------------------------------------------------------------
typedef rtb::StringId   ComponentId;

//----------------------------------------------------------------------------
struct StartMiniGameRequestEvent : forge::Event<StartMiniGameRequestEvent>
{
    FRG__DECL_EVENT(StartMiniGameRequestEvent);
};

//----------------------------------------------------------------------------
struct StopMiniGameRequestEvent : forge::Event<StopMiniGameRequestEvent>
{
    FRG__DECL_EVENT(StopMiniGameRequestEvent);
};

//----------------------------------------------------------------------------
struct MiniGameCompletedEvent : forge::Event<MiniGameCompletedEvent>
{
    FRG__DECL_EVENT(MiniGameCompletedEvent);
};

//----------------------------------------------------------------------------
struct GameOverEvent : forge::Event<GameOverEvent>
{
    FRG__DECL_EVENT(GameOverEvent);
};
