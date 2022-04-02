#include <snooze/Precomp.h>
#include <snooze/ecs/SnoozableComponent.h>

//----------------------------------------------------------------------------
FRG__IMPL_COMPONENT(SnoozableComponent);

//----------------------------------------------------------------------------
SnoozableComponent::SnoozableComponent()
    : m_IsClickable(true)
    , m_IsPressed(false)
{}

//----------------------------------------------------------------------------
bool SnoozableComponent::IsClickable() const
{
    return m_IsClickable;
}

//----------------------------------------------------------------------------
void SnoozableComponent::SetClickable(bool _b)
{
    m_IsClickable = _b;
}

//----------------------------------------------------------------------------
bool SnoozableComponent::IsPressed() const
{
    return m_IsPressed;
}

//----------------------------------------------------------------------------
void SnoozableComponent::SetPressed(bool _b)
{
    m_IsPressed = _b;
}

//----------------------------------------------------------------------------
forge::Chrono& SnoozableComponent::GetTimer()
{
    return m_Timer;
}
