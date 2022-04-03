#include <snooze/Precomp.h>
#include <snooze/presentation/SnoozeViewController.h>

#include <forge/builtin/rendering/RenderableComponent.h>

#include <snooze/Story.h>

//----------------------------------------------------------------------------
static constexpr f32 HUD_SCALE = 1080.f / 600.f;

//----------------------------------------------------------------------------
SnoozeViewController::SnoozeViewController()
    : m_ItemView(nullptr)
    , m_SnoozeView(nullptr)
    , m_StoryView(nullptr)
{
    m_SDA.Init();
}

//----------------------------------------------------------------------------
void SnoozeViewController::OnStart()
{
    ButtonPushedEvent::Handlers +=
        ButtonPushedEvent::Handler(this, &SnoozeViewController::OnButtonPushedEvent);
    ItemAcquieredEvent::Handlers +=
        ItemAcquieredEvent::Handler(this, &SnoozeViewController::OnItemAcquieredEvent);
    ItemLostEvent::Handlers +=
        ItemLostEvent::Handler(this, &SnoozeViewController::OnItemLostEvent);

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
    ItemAcquieredEvent::Handlers -=
        ItemAcquieredEvent::Handler(this, &SnoozeViewController::OnItemAcquieredEvent);
    ItemLostEvent::Handlers -=
        ItemLostEvent::Handler(this, &SnoozeViewController::OnItemLostEvent);

    CloseView(m_SnoozeView);
    delete m_SnoozeView;
    m_SnoozeView = nullptr;
    m_StoryTimer.Stop();

    if (m_ItemView != nullptr)
    {
        CloseView(m_ItemView);
        delete m_ItemView;
        m_ItemView = nullptr;
    }

    if (m_StoryView != nullptr)
    {
        CloseView(m_StoryView);
        delete m_StoryView;
        m_StoryView = nullptr;
    }
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

    {
        if (_event.GetIsPostMiniGame())
        {
            m_StoryPages = Story::GetInstance().GetNextStory();
        }
        else
        {
            m_StoryPages = Story::GetInstance().GetRandomThought();
        }
    }

    DisplayNextAvailableStoryPage();

    OpenView(m_StoryView);
}

//----------------------------------------------------------------------------
void SnoozeViewController::OnItemAcquieredEvent(const ItemAcquieredEvent& _event)
{
    m_ItemView = new ItemView();
    m_ItemView->SetPixelSize({ 170, 170 });
    m_ItemView->SetPixelPadding({ 30, 30 });
    m_ItemView->GetItemPanel().GetBackground()->SetSprite(
        _event.GetItem()->GetComponent<forge::builtin::RenderableComponent>()
        .GetSprite());

    OpenView(m_ItemView);
}

//----------------------------------------------------------------------------
void SnoozeViewController::OnItemLostEvent(const ItemLostEvent& _event)
{
    if (m_ItemView != nullptr)
    {
        CloseView(m_ItemView);
        delete m_ItemView;
        m_ItemView = nullptr;
    }
}

//----------------------------------------------------------------------------
void SnoozeViewController::DisplayNextAvailableStoryPage()
{
    if (m_StoryPages.size() > 0)
    {
        forge::String str = m_StoryPages[0];
        m_StoryPages.erase(m_StoryPages.cbegin());
        m_StoryView->GetStoryPanel().GetText()->SetString(str);
        m_StoryTimer.Start(2000);
    }
}
