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
    ButtonPushedEvent::Handlers +=
        ButtonPushedEvent::Handler(this, &SnoozeViewController::OnButtonPushedEvent);

    m_SnoozeView = new SnoozeView();
    m_SnoozeView->SetPixelSize({ 202 * HUD_SCALE, 64  * HUD_SCALE });
    m_SnoozeView->SetPixelPadding({ 154 * HUD_SCALE, 212 * HUD_SCALE });

    OpenView(m_SnoozeView);
}

//----------------------------------------------------------------------------
void SnoozeViewController::OnStop()
{
    ButtonPushedEvent::Handlers -=
        ButtonPushedEvent::Handler(this, &SnoozeViewController::OnButtonPushedEvent);

    CloseView(m_SnoozeView);
    delete m_SnoozeView;
    m_SnoozeView = nullptr;
}

//----------------------------------------------------------------------------
void SnoozeViewController::Update()
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

    if (m_StoryView != nullptr)
    {
        //m_StoryView->SetAlpha(static_cast<u8>(std::max(0.f, (std::log10(1.f - m_StoryTimer.GetElapsedRatio()) + 1.f) * 255)));

        if (m_StoryTimer.IsElapsed())
        {
            if (m_StoryPages.size() > 0)
            {
                DisplayNextAvailableStoryPage();
            }
            else
            {
                CloseView(m_StoryView);
                delete m_StoryView;
                m_StoryView = nullptr;
            }
        }
    }
}

//----------------------------------------------------------------------------
void SnoozeViewController::OnButtonPushedEvent(const ButtonPushedEvent& _event)
{
    if (m_StoryView == nullptr)
    {
        m_StoryView = new StoryView();
        m_StoryView->SetGravity(forge::GUIGravity::Bottom);
        m_StoryView->SetRelativeSize({ 90, 20 });
        m_StoryView->SetRelativePadding({ 0, 2 });
    }

    // TODO: Get next texts from Story Singleton
    {
        m_StoryPages.clear();
        if (_event.GetIsPostMiniGame())
            m_StoryPages.push_back("SUPER");
        m_StoryPages.push_back("WELL");
        m_StoryPages.push_back("PLAYED");
    }

    DisplayNextAvailableStoryPage();

    OpenView(m_StoryView);
}

//----------------------------------------------------------------------------
void SnoozeViewController::DisplayNextAvailableStoryPage()
{
    forge::String str = m_StoryPages[0];
    m_StoryPages.erase(m_StoryPages.cbegin());
    m_StoryView->GetStoryPanel().GetText()->SetString(str);
    m_StoryTimer.Start(2000);
}
