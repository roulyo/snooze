#pragma once

#include <forge/engine/ecs/Component.h>

//----------------------------------------------------------------------------
enum CursorType
{
    Arrow = 0,
    Hand,
    Cross,
};

//----------------------------------------------------------------------------
class HoverableComponent : public forge::AbstractComponent
{
    FRG__DECL_COMPONENT(HoverableComponent);

public:
    FRG__CLASS_ATTR_RW(CursorType, CursorType);

};
