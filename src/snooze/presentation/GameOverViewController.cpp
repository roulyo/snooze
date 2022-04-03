#include <snooze/Precomp.h>
#include <snooze/Story.h>
#include <snooze/presentation/GameOverViewController.h>

static constexpr f32 HUD_SCALE = 1080.f / 600.f;

//----------------------------------------------------------------------------
GameOverViewController::GameOverViewController()
{
    m_SDA.Init();
}

//----------------------------------------------------------------------------
void GameOverViewController::OnStart()
{
    //m_SnoozeView = new SnoozeView();
    //m_SnoozeView->SetPixelSize({ 202 * HUD_SCALE, 64  * HUD_SCALE });
    //m_SnoozeView->SetPixelPadding({ 154 * HUD_SCALE, 212 * HUD_SCALE });

    //OpenView(m_SnoozeView);
}

//----------------------------------------------------------------------------
void GameOverViewController::OnStop()
{
    //CloseView(m_SnoozeView);
    //delete m_SnoozeView;
    //m_SnoozeView = nullptr;
}

//----------------------------------------------------------------------------
void GameOverViewController::Update()
{
    if (m_SnoozeView != nullptr)
    {
        u32 timeSec = m_SDA.GetRemainingTimeMs() / 1000;
        u32 seconds = timeSec % 60;
        u32 minutes = timeSec / 60;

        forge::String secStr = seconds < 10 ? "0" :  "";
        forge::String minStr = seconds < 10 ? "0" :  "";

        m_SnoozeView->GetMinutesDisplay().GetText()->SetString(minStr + std::to_string(minutes));
        m_SnoozeView->GetSecondsDisplay().GetText()->SetString(secStr + std::to_string(seconds));
        m_SnoozeView->GetColonDisplay().GetText()->SetFillColor(
            { 255, 0 , 0, static_cast<u8>(255 * (timeSec % 2)) });
    }
}
