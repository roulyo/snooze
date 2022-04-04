#pragma once

#include <forge/engine/presentation/View.h>

#include <forge/builtin/presentation/guiwidgets/Div.h>
#include <forge/builtin/presentation/guiwidgets/TextPanel.h>

//----------------------------------------------------------------------------
class SnoozeView : public forge::View
{
public:
    SnoozeView();

    forge::builtin::gui::QuadTextPanel& GetMinutesDisplay();
    forge::builtin::gui::QuadTextPanel& GetColonDisplay();
    forge::builtin::gui::QuadTextPanel& GetSecondsDisplay();

private:
    forge::builtin::gui::Div             m_MinutesDiv;
    forge::builtin::gui::QuadTextPanel   m_Minutes;
    forge::builtin::gui::QuadTextPanel   m_Colon;
    forge::builtin::gui::Div             m_SecondsDiv;
    forge::builtin::gui::QuadTextPanel   m_Seconds;

};
