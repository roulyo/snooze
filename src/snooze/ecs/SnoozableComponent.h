#pragma once

#include <forge/engine/ecs/Component.h>

#include <forge/engine/time/Chrono.h>

//----------------------------------------------------------------------------
class SnoozableComponent : public forge::AbstractComponent
{
    FRG__DECL_COMPONENT(SnoozableComponent);

public:
    SnoozableComponent();

    bool IsClickable() const;
    void SetClickable(bool _b);

    bool IsPressed() const;
    void SetPressed(bool _b);

    const forge::Chrono& GetTimer() const;
    forge::Chrono& GetTimer();

private:
    bool            m_IsClickable;
    bool            m_IsPressed;
    forge::Chrono   m_Timer;
    
public:
    // don't do this at home kid
    forge::f32      ForceMiniGameAtRatio;

};
