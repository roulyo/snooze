#include <snooze/Precomp.h>
#include <snooze/presentation/ItemView.h>

#include <forge/engine/data/api/DataAPI.h>

#include <snooze/data/DataList.h>
#include <snooze/data/FontCatalog.h>
#include <snooze/data/SpriteCatalog.h>

//----------------------------------------------------------------------------
ItemView::ItemView()
{
    m_Background.GetBackground()->SetFillColor({ 255, 239, 203 });
    m_Background.GetBackground()->SetOutlineColor({ 255, 239, 203 });
    m_Background.GetBackground()->SetOutlineThickness(5);
    m_ItemPanel.GetBackground()->SetOutlineColor({ 0, 0, 0 });
    m_ItemPanel.GetBackground()->SetOutlineThickness(5);

    AddWidget(&m_Background);
    AddWidget(&m_ItemPanel);
}

//----------------------------------------------------------------------------
forge::builtin::gui::QuadPanel& ItemView::GetItemPanel()
{
    return m_ItemPanel;
}
