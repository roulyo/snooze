#pragma once

#include <forge/engine/presentation/View.h>

#include <forge/builtin/presentation/guiwidgets/TextPanel.h>

//----------------------------------------------------------------------------
class GameOverView : public forge::View
{
public:
    GameOverView(bool _success);

    forge::builtin::gui::QuadTextPanel&  GetButton();
    forge::builtin::gui::QuadTextPanel&  GetMiscText();

private:
    void SetupBackground();
    void SetupGameOverText(bool _success);
    void SetupMiscText(bool _success);
    void SetupButton(bool _success);

private:
    forge::builtin::gui::QuadPanel      m_Background;
    forge::builtin::gui::QuadTextPanel  m_GameOverText;
    forge::builtin::gui::QuadTextPanel  m_MiscText;
    forge::builtin::gui::QuadTextPanel  m_Button;

};
