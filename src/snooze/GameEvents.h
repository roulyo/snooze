#pragma once

#include <forge/engine/event/Event.h>

#include <forge/engine/ecs/Entity.h>

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
struct ButtonPushedEvent : forge::Event<ButtonPushedEvent>
{
    FRG__DECL_EVENT(ButtonPushedEvent);

    ButtonPushedEvent(bool _b)
        : m_IsPostMiniGame(_b)
    {}

    FRG__CLASS_ATTR_R_(bool, IsPostMiniGame);

};

//----------------------------------------------------------------------------
struct ItemAcquieredEvent : forge::Event<ItemAcquieredEvent>
{
    FRG__DECL_EVENT(ItemAcquieredEvent);

    ItemAcquieredEvent(const forge::Entity::CPtr& _item)
        : m_Item(_item)
    {}

    FRG__CLASS_ATTR_R_(forge::Entity::CPtr, Item);

};

//----------------------------------------------------------------------------
struct ItemLostEvent : forge::Event<ItemLostEvent>
{
    FRG__DECL_EVENT(ItemLostEvent);
};

//----------------------------------------------------------------------------
struct GameOverRequestedEvent : forge::Event<GameOverRequestedEvent>
{
    FRG__DECL_EVENT(GameOverRequestedEvent);

    GameOverRequestedEvent(bool _b)
        : m_IsSuccessful(_b)
    {}

    FRG__CLASS_ATTR_R_(bool, IsSuccessful);
};

//----------------------------------------------------------------------------
struct GameOverEvent : forge::Event<GameOverEvent>
{
    FRG__DECL_EVENT(GameOverEvent);

    GameOverEvent(bool _b)
        : m_IsSuccessful(_b)
    {}

    FRG__CLASS_ATTR_R_(bool, IsSuccessful);
};

//----------------------------------------------------------------------------
struct RetryRequestedEvent : forge::Event<RetryRequestedEvent>
{
    FRG__DECL_EVENT(RetryRequestedEvent);
};

//----------------------------------------------------------------------------
struct QuitRequestedEvent : forge::Event<QuitRequestedEvent>
{
    FRG__DECL_EVENT(QuitRequestedEvent);
};
