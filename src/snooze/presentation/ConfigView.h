#pragma once

#include <forge/engine/presentation/View.h>

#include <forge/builtin/presentation/guiwidgets/Panel.h>

//----------------------------------------------------------------------------
class ConfigView : public forge::View
{
public:
    ConfigView();

    void SetSoundOn();
    void SetSoundOff();
    void SetMusicOn();
    void SetMusicOff();

    forge::builtin::gui::QuadPanel&  GetMuteSoundButton();
    forge::builtin::gui::QuadPanel&  GetMuteMusicButton();

private:
    forge::builtin::gui::QuadPanel  m_MuteSoundButton;
    forge::builtin::gui::QuadPanel  m_MuteMusicButton;

};
