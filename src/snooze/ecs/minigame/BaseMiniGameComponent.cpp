#include <snooze/Precomp.h>
#include <snooze/ecs/minigame/BaseMiniGameComponent.h>

//----------------------------------------------------------------------------
bool BaseMiniGameComponent::IsStarted() const
{
    return m_IsStarted;
}

//----------------------------------------------------------------------------
void BaseMiniGameComponent::SetStarted(bool _b)
{
    m_IsStarted = _b;
}