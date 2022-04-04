#include <snooze/Precomp.h>
#include <snooze/presentation/StoryView.h>

#include <forge/engine/data/api/DataAPI.h>

#include <snooze/data/DataList.h>
#include <snooze/data/FontCatalog.h>

//----------------------------------------------------------------------------
StoryView::StoryView()
{
    SetupStoryPanel();
}

//----------------------------------------------------------------------------
void StoryView::SetupStoryPanel()
{
    forge::Font::Ptr font = forge::DataAPI::GetDataFrom<FontCatalog>(DataList::Font::StoryFont);

    m_StoryPanel.GetBackground()->SetOutlineColor({ 0, 0, 0 });
    m_StoryPanel.GetBackground()->SetOutlineThickness(5.f);
    m_StoryPanel.GetBackground()->SetFillColor({ 200, 200, 200 });
    m_StoryPanel.GetText().Gravity = forge::GUIGravity::TopLeft;
    m_StoryPanel.GetText().RelativePadding = { 10, 12 };
    m_StoryPanel.GetText()->SetFont(font);
    m_StoryPanel.GetText()->SetSize(42);
    m_StoryPanel.GetText()->SetFillColor({ 55, 55, 55 });

    AddWidget(&m_StoryPanel);
}

//----------------------------------------------------------------------------
forge::builtin::gui::QuadTextPanel& StoryView::GetStoryPanel()
{
    return m_StoryPanel;
}

//----------------------------------------------------------------------------
ThoughtView::ThoughtView()
{
    SetupThoughtPanel();
}

//----------------------------------------------------------------------------
void ThoughtView::SetupThoughtPanel()
{
    forge::Font::Ptr font = forge::DataAPI::GetDataFrom<FontCatalog>(DataList::Font::StoryFont);

    m_ThoughtPanel.GetBackground()->SetFillColor({ 0, 0, 0, 0 });

    m_ThoughtPanel.GetText()->SetFont(font);
    m_ThoughtPanel.GetText()->SetStyle(forge::Text::Style::Italic);
    m_ThoughtPanel.GetText()->SetSize(28);
    m_ThoughtPanel.GetText()->SetFillColor({ 55, 55, 55 });

    AddWidget(&m_ThoughtPanel);
}

//----------------------------------------------------------------------------
forge::builtin::gui::QuadTextPanel& ThoughtView::GetToughtPanel()
{
    return m_ThoughtPanel;
}
