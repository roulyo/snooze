#include <snooze/Precomp.h>
#include <snooze/presentation/SnoozeView.h>

#include <forge/engine/data/api/DataAPI.h>

#include <snooze/data/DataList.h>
#include <snooze/data/FontCatalog.h>

//----------------------------------------------------------------------------
SnoozeView::SnoozeView()
{
    forge::Font::Ptr font = forge::DataAPI::GetDataFrom<FontCatalog>(DataList::Font::AlarmClock);

    m_MinutesDiv.SetGravity(forge::GUIGravity::Left);
    m_MinutesDiv.SetRelativeSize({ 50, 100 });
    m_MinutesDiv.SetRelativePadding({ 0 , 0 });
    m_MinutesDiv.AddChild(&m_Minutes);

    m_Minutes.GetBackground()->SetFillColor({ 0, 0, 0, 0 });
    //m_Minutes.GetText().Gravity = forge::GUIGravity::Center;
    //m_Minutes.GetText().RelativePadding = { 13, 0 };
    m_Minutes.GetText()->SetFont(font);
    m_Minutes.GetText()->SetSize(100);
    m_Minutes.GetText()->SetFillColor({ 255, 0, 0 });
    m_Minutes.GetText()->SetString("88");

    m_Colon.GetBackground()->SetFillColor({ 0, 0, 0, 0 });
    m_Colon.GetText().Gravity = forge::GUIGravity::Top;
    m_Colon.GetText().RelativePadding = { 0, 15 };
    m_Colon.GetText()->SetFont(font);
    m_Colon.GetText()->SetSize(100);
    m_Colon.GetText()->SetFillColor({ 255, 0, 0 });
    m_Colon.GetText()->SetString(":");

    m_SecondsDiv.SetGravity(forge::GUIGravity::Left);
    m_SecondsDiv.SetRelativeSize({ 50, 100 });
    m_SecondsDiv.SetRelativePadding({ 50 , 0 });
    m_SecondsDiv.AddChild(&m_Seconds);

    m_Seconds.GetBackground()->SetFillColor({ 0, 0, 0, 0 });
    //m_Seconds.GetText().Gravity = forge::GUIGravity::Center;
    m_Seconds.SetGravity(forge::GUIGravity::Center);
    m_Seconds.SetRelativePadding({ 10, 0 });
    m_Seconds.GetText()->SetFont(font);
    m_Seconds.GetText()->SetSize(100);
    m_Seconds.GetText()->SetFillColor({ 255, 0, 0 });
    m_Seconds.GetText()->SetString("88");

    AddWidget(&m_MinutesDiv);
    AddWidget(&m_Colon);
    AddWidget(&m_SecondsDiv);
}

//----------------------------------------------------------------------------
forge::builtin::gui::QuadTextPanel& SnoozeView::GetMinutesDisplay()
{
    return m_Minutes;
}

//----------------------------------------------------------------------------
forge::builtin::gui::QuadTextPanel& SnoozeView::GetColonDisplay()
{
    return m_Colon;
}

//----------------------------------------------------------------------------
forge::builtin::gui::QuadTextPanel& SnoozeView::GetSecondsDisplay()
{
    return m_Seconds;
}
