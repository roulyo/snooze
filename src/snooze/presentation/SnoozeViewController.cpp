#include <snooze/Precomp.h>
#include <snooze/presentation/SnoozeViewController.h>

//----------------------------------------------------------------------------
SnoozeViewController::SnoozeViewController()
{
    m_SDA.Init();
}

//----------------------------------------------------------------------------
void SnoozeViewController::OnStart()
{
    m_View = new SnoozeView();
    m_View->SetPixelSize({ 202, 64 });
    m_View->SetPixelPadding({ 154, 238 });

    OpenView(m_View);
}

//----------------------------------------------------------------------------
void SnoozeViewController::OnStop()
{
    CloseView(m_View);
    delete m_View;
    m_View = nullptr;
}

//----------------------------------------------------------------------------
void SnoozeViewController::Update()
{
    if (m_View != nullptr)
    {
        u32 timeSec = m_SDA.GetRemainingTimeMs() / 1000;
        u32 seconds = timeSec % 60;
        u32 minutes = timeSec / 60;

        m_View->GetMinutesDisplay().GetText()->SetString(std::to_string(minutes));
        m_View->GetSecondsDisplay().GetText()->SetString(std::to_string(seconds));
        m_View->GetColonDisplay().GetText()->SetFillColor(
            { 255, 0 , 0, static_cast<u8>(255 * (timeSec % 2)) });
    }
}
