#include <snooze/Precomp.h>
#include <snooze/presentation/StoryView.h>

#include <forge/engine/data/api/DataAPI.h>

#include <snooze/data/DataList.h>
#include <snooze/data/FontCatalog.h>

//----------------------------------------------------------------------------
StoryView::StoryView()
{
    forge::Font::Ptr font = forge::DataAPI::GetDataFrom<FontCatalog>(DataList::Font::StoryFont);

    m_StoryPanel.GetBackground()->SetOutlineColor({ 0, 0, 0 });
    m_StoryPanel.GetBackground()->SetOutlineThickness(5.f);
    m_StoryPanel.GetBackground()->SetFillColor({ 200, 200, 200 });
    m_StoryPanel.GetText().Gravity = forge::GUIGravity::TopLeft;
    m_StoryPanel.GetText().RelativePadding = { 3, 4 };
    m_StoryPanel.GetText()->SetFont(font);
    m_StoryPanel.GetText()->SetSize(42);
    m_StoryPanel.GetText()->SetFillColor({ 55, 55, 55 });

    AddWidget(&m_StoryPanel);
}

//----------------------------------------------------------------------------
void StoryView::SetAlpha(u8 _a)
{
    m_StoryPanel.GetBackground()->SetOutlineColor({ 0, 0, 0, _a });
    m_StoryPanel.GetBackground()->SetFillColor({ 200, 200, 200, _a });
    m_StoryPanel.GetText()->SetFillColor({ 55, 55, 55, _a });
}

//----------------------------------------------------------------------------
forge::builtin::gui::QuadTextPanel& StoryView::GetStoryPanel()
{
    return m_StoryPanel;
}
