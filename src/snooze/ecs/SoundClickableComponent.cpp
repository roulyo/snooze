#include <snooze/Precomp.h>
#include <snooze/ecs/SoundClickableComponent.h>

//----------------------------------------------------------------------------
FRG__IMPL_COMPONENT(SoundClickableComponent);

//----------------------------------------------------------------------------
SoundClickableComponent::SoundClickableComponent()
    : m_OnPressSound(nullptr)
    , m_OnReleaseSound(nullptr)
{
}