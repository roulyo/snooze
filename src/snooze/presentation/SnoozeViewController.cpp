#include <snooze/Precomp.h>
#include <snooze/presentation/SnoozeViewController.h>

static constexpr f32 HUD_SCALE = 1080.f / 600.f;

//----------------------------------------------------------------------------
SnoozeViewController::SnoozeViewController()
{
    m_SDA.Init();
}

//----------------------------------------------------------------------------
void SnoozeViewController::OnStart()
{
    m_View = new SnoozeView();
    m_View->SetPixelSize({ 202 * HUD_SCALE, 64  * HUD_SCALE });
    m_View->SetPixelPadding({ 154 * HUD_SCALE, 222 * HUD_SCALE });

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

        forge::String secStr = seconds < 10 ? "0" :  "";
        forge::String minStr = seconds < 10 ? "0" :  "";

        m_View->GetMinutesDisplay().GetText()->SetString(minStr + std::to_string(minutes));
        m_View->GetSecondsDisplay().GetText()->SetString(secStr + std::to_string(seconds));
        m_View->GetColonDisplay().GetText()->SetFillColor(
            { 255, 0 , 0, static_cast<u8>(255 * (timeSec % 2)) });
    }
}
