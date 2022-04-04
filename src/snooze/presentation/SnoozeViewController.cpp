#include <snooze/Precomp.h>
#include <snooze/presentation/SnoozeViewController.h>

#include <random>

#include <forge/engine/data/api/DataAPI.h>
#include <forge/engine/time/api/TimeAPI.h>

#include <forge/builtin/presentation/behaviors/ClickableBehavior.h>
#include <forge/builtin/rendering/RenderableComponent.h>

#include <snooze/data/DataList.h>
#include <snooze/data/SoundCatalog.h>
#include <snooze/Story.h>

//----------------------------------------------------------------------------
static constexpr f32 HUD_SCALE = 1080.f / 600.f;

static forge::Sound::Ptr s_SpeechSound = nullptr;
static std::random_device rd;

//----------------------------------------------------------------------------
SnoozeViewController::SnoozeViewController()
    : m_ItemView(nullptr)
    , m_SnoozeView(nullptr)
    , m_StoryView(nullptr)
    , m_ThoughtView(nullptr)
    , m_ConfigView(nullptr)
    , m_SoundMuted(false)
    , m_MusicMuted(false)
{
    m_SDA.Init();
    s_SpeechSound = forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::Speech);
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
    m_SnoozeView->SetPixelPadding({ 154 * HUD_SCALE, 207 * HUD_SCALE });

    OpenView(m_SnoozeView);

    m_ConfigView = new ConfigView();
    m_ConfigView->SetGravity(forge::GUIGravity::TopRight);
    m_ConfigView->SetPixelSize({ 100, 50 });
    m_ConfigView->GetMuteSoundButton().AddBehavior<forge::builtin::ClickableBehavior>(
        FRG__BIND_BEHAVIOR(SnoozeViewController, OnMuteSoundClicked, this)
    );
    m_ConfigView->GetMuteMusicButton().AddBehavior<forge::builtin::ClickableBehavior>(
        FRG__BIND_BEHAVIOR(SnoozeViewController, OnMuteMusicClicked, this)
    );

    OpenView(m_ConfigView);
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

    CloseView(m_ConfigView);
    delete m_ConfigView;
    m_ConfigView = nullptr;

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
    UpdateSnoozeView();
    UpdateStoryView();
    UpdateThoughtView();
}

//----------------------------------------------------------------------------
void SnoozeViewController::UpdateSnoozeView()
{
    if (m_SnoozeView != nullptr)
    {
        u32 timeSec = m_SDA.GetRemainingTimeMs() / 1000;
        u32 seconds = timeSec % 60;
        u32 minutes = timeSec / 60;

        forge::String secStr = seconds < 10 ? "0" :  "";
        forge::String minStr = minutes < 10 ? "0" :  "";

        if (seconds < 20 && seconds >= 10)
        {
            m_SnoozeView->GetSecondsDisplay().SetGravity(forge::GUIGravity::Right);
        }
        else
        {
            m_SnoozeView->GetSecondsDisplay().SetGravity(forge::GUIGravity::Center);
        }

        m_SnoozeView->GetSecondsDisplay().GetText()->SetString(secStr + std::to_string(seconds));
        m_SnoozeView->GetMinutesDisplay().GetText()->SetString(minStr + std::to_string(minutes));
        m_SnoozeView->GetColonDisplay().GetText()->SetFillColor(
            { 255, 0 , 0, static_cast<u8>(255 * (timeSec % 2)) });
    }
}

//----------------------------------------------------------------------------
void SnoozeViewController::UpdateStoryView()
{
    if (m_StoryView != nullptr)
    {
        UpdateCurrentStoryDisplay();

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
void SnoozeViewController::UpdateThoughtView()
{
    if (m_ThoughtView != nullptr)
    {
        if (m_ThoughtTimer.IsElapsed())
        {
            CloseView(m_ThoughtView);
            delete m_ThoughtView;
            m_ThoughtView = nullptr;
        }
    }
}

//----------------------------------------------------------------------------
void SnoozeViewController::OnButtonPushedEvent(const ButtonPushedEvent& _event)
{
    if (_event.GetIsPostMiniGame())
    {
        if (m_StoryView == nullptr)
        {
            m_StoryView = new StoryView();
            m_StoryView->SetGravity(forge::GUIGravity::Bottom);
            m_StoryView->SetRelativeSize({ 90, 20 });
            m_StoryView->SetRelativePadding({ 0, 2 });
            OpenView(m_StoryView);
        }

        m_StoryPages = Story::GetInstance().GetNextStory();

        DisplayNextAvailableStoryPage();
    }
    else
    {
        if (m_ThoughtView == nullptr)
        {
            m_ThoughtView = new ThoughtView();

            OpenView(m_ThoughtView);
        }

        m_ThoughtView->SetRelativeSize({ 20, 10 });
        m_ThoughtView->SetRelativePadding({ static_cast<f32>((rd() % 20) + 60 * (rd() % 2)),
                                            static_cast<f32>((rd() % 20) + 60 * (rd() % 2)) });

        m_Thought = Story::GetInstance().GetRandomThought();

        DisplayThought();
    }
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
void SnoozeViewController::OnMuteSoundClicked(forge::GUIWidget* _widget,
                                              const forge::SystemEvent& _event)
{
    m_SoundMuted = !m_SoundMuted;

    if (m_SoundMuted)
    {
        SetGlobalSoundVolume(0.0f);
        m_ConfigView->SetSoundOff();
    }
    else
    {
        SetGlobalSoundVolume(100.0f);
        m_ConfigView->SetSoundOn();
    }
}

//----------------------------------------------------------------------------
void SnoozeViewController::OnMuteMusicClicked(forge::GUIWidget* _widget,
                                              const forge::SystemEvent& _event)
{
    m_MusicMuted = !m_MusicMuted;

    if (m_MusicMuted)
    {
        SetGlobalMusicVolume(0.0f);
        m_ConfigView->SetMusicOff();
    }
    else
    {
        SetGlobalMusicVolume(100.0f);
        m_ConfigView->SetMusicOn();
    }
}

//----------------------------------------------------------------------------
void SnoozeViewController::DisplayNextAvailableStoryPage()
{
    if (m_StoryPages.size() > 0)
    {
        m_CurrentStory.Content = m_StoryPages[0];
        m_CurrentStory.Index = 0;

        m_StoryPages.erase(m_StoryPages.cbegin());
        m_StoryTimer.Start(SnoozeConfig::StoryDisplayTimeMs);
    }
}

//----------------------------------------------------------------------------
void SnoozeViewController::UpdateCurrentStoryDisplay()
{
    static u64 startTimeMs;

    if (m_CurrentStory.Index == 0)
    {
        startTimeMs = forge::TimeAPI::GetGameTimeMilliseconds();
    }

    u32 prevIndex = m_CurrentStory.Index;
    f32 charCount =   (SnoozeConfig::SpeechCharactersPerSecond / 1000.f)
                    * (forge::TimeAPI::GetGameTimeMilliseconds() - startTimeMs);
    m_CurrentStory.Index = std::min(m_CurrentStory.Content.size(), static_cast<u64>(charCount));
    m_CurrentStory.Index = std::max(1u, m_CurrentStory.Index);

    if (prevIndex != m_CurrentStory.Index && (m_CurrentStory.Index % 7 == 1))
    {
        u8 charValue = m_CurrentStory.Content[m_CurrentStory.Index] % 26;
        f32 pitch = 1.f + (static_cast<f32>(charValue) / 26.f);

        s_SpeechSound->SetPitch(pitch);
        PlaySound(s_SpeechSound);
    }

    forge::String str = m_CurrentStory.Content.substr(0, m_CurrentStory.Index);
    m_StoryView->GetStoryPanel().GetText()->SetString(str);
}

//----------------------------------------------------------------------------
void SnoozeViewController::DisplayThought()
{
    m_ThoughtView->GetToughtPanel().GetText()->SetString('*' + m_Thought + '*');
    m_ThoughtTimer.Start(SnoozeConfig::ThoughtDisplayTimeMs);
}
