#pragma once

#include <forge/engine/presentation/View.h>

#include <forge/builtin/presentation/guiwidgets/TextPanel.h>

//----------------------------------------------------------------------------
class StoryView : public forge::View
{
public:
    StoryView();

    forge::builtin::gui::QuadTextPanel& GetStoryPanel();
    forge::builtin::gui::QuadTextPanel& GetToughtPanel();

private:
    void SetupStoryPanel();
    void SetupThoughtPanel();

private:
    forge::builtin::gui::QuadTextPanel   m_StoryPanel;

};

//----------------------------------------------------------------------------
class ThoughtView : public forge::View
{
public:
    ThoughtView();

    forge::builtin::gui::QuadTextPanel& GetToughtPanel();

private:
    void SetupThoughtPanel();

private:
    forge::builtin::gui::QuadTextPanel   m_ThoughtPanel;

};
