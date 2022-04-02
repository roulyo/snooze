#pragma once

#include <forge/engine/ecs/Component.h>

//----------------------------------------------------------------------------
class BaseMiniGameComponent : public forge::AbstractComponent
{
public:
    bool IsStarted() const;
    void SetStarted(bool _b);

private:
    bool    m_IsStarted;

};
