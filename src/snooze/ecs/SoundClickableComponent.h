#pragma once

#include <forge/engine/audio/playable/Sound.h>
#include <forge/engine/ecs/Component.h>

//----------------------------------------------------------------------------
class SoundClickableComponent : public forge::AbstractComponent
{
    FRG__DECL_COMPONENT(SoundClickableComponent);

public:
    SoundClickableComponent();

    FRG__CLASS_ATTR_RW(forge::Sound::Ptr, OnPressSound);
    FRG__CLASS_ATTR_RW(forge::Sound::Ptr, OnReleaseSound);

};
