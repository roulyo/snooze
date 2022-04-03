#pragma once

#include <forge/engine/presentation/View.h>

#include <forge/builtin/presentation/guiwidgets/TextPanel.h>

//----------------------------------------------------------------------------
class StoryView : public forge::View
{
public:
    StoryView();

    forge::builtin::gui::QuadTextPanel& GetStoryPanel();

    void SetAlpha(u8 _a);

private:
    forge::builtin::gui::QuadTextPanel   m_StoryPanel;

};
