#include <snooze/Precomp.h>
#include <snooze/Snooze.h>
#include <snooze/Story.h>

#include <random>

#include <forge/engine/camera/api/CameraAPI.h>
#include <forge/engine/data/api/DataAPI.h>
#include <forge/engine/presentation/api/PresentationAPI.h>
#include <forge/engine/window/Cursor.h>

#include <snooze/data/DataList.h>
#include <snooze/data/EntityCatalog.h>
#include <snooze/data/FontCatalog.h>
#include <snooze/data/MusicCatalog.h>
#include <snooze/data/SoundBufferCatalog.h>
#include <snooze/data/SoundCatalog.h>
#include <snooze/data/SpriteCatalog.h>
#include <snooze/data/TextureCatalog.h>
#include <snooze/ecs/minigame/sample/SampleMiniGameComponent.h>
#include <snooze/ecs/minigame/padlock/PadlockMiniGameComponent.h>
#include <snooze/ecs/minigame/mouseattack/MouseAttackMiniGameComponent.h>
#include <snooze/ecs/minigame/battery/BatteryMiniGameComponent.h>
#include <snooze/ecs/minigame/vermins/VerminsMiniGameComponent.h>
#include <snooze/gamestate/BaseGameState.h>
#include <snooze/gamestate/GameOverState.h>


//----------------------------------------------------------------------------
static bool s_GameCompleted = false;

bool Snooze::IsGameCompleted()
{
    return s_GameCompleted;
}

//----------------------------------------------------------------------------
Snooze::Snooze()
{
    m_MiniGames.push_back(SampleMiniGameComponent::Id);
    m_MiniGames.push_back(SampleMiniGameComponent::Id);
    m_MiniGames.push_back(SampleMiniGameComponent::Id);
    m_MiniGames.push_back(PadlockMiniGameComponent::Id);
    m_MiniGames.push_back(MouseAttackMiniGameComponent::Id);
    m_MiniGames.push_back(VerminsMiniGameComponent::Id);
    m_MiniGames.push_back(BatteryMiniGameComponent::Id);
}

//----------------------------------------------------------------------------
Snooze::~Snooze()
{
}

//----------------------------------------------------------------------------
void Snooze::OnInit()
{
    RegisterCatalogType<EntityCatalog>();
    RegisterCatalogType<FontCatalog>();
    RegisterCatalogType<MusicCatalog>();
    RegisterCatalogType<SpriteCatalog>();
    RegisterCatalogType<TextureCatalog>();
    RegisterCatalogType<SoundCatalog>();
    RegisterCatalogType<SoundBufferCatalog>();

    // Instanciate story singleton
    Story::Instantiate();

    m_World.Init(100.f, 100.f);

    forge::Entity::Ptr alarm = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::Alarm);
    alarm->SetPosition(50.f - alarm->GetSize().w * 0.5f, 50.f - alarm->GetSize().d * 0.5f, 1.f);
    m_World.AddEntity(alarm);

    forge::Entity::Ptr screw = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::AlarmScrew);
    screw->SetPosition(50.f - screw->GetSize().w * 0.5f, 50.f - screw->GetSize().d * 0.5f, 1.2f);
    m_World.AddEntity(screw);

    forge::Entity::Ptr button = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::AlarmButton);
    button->SetPosition(50.f - button->GetSize().w * 0.5f, 50.f - button->GetSize().d * 0.5f, 2.f);
    m_World.AddEntity(button);

    forge::CameraAPI::SetLookAt({50.f, 50.f, 0.f});
    forge::CameraAPI::SetDistance(10);
    forge::CameraAPI::SetFieldOfView(90);
    forge::CameraAPI::SetFilmedWorld(GetWorld());

    StartMiniGameRequestEvent::Handlers +=
        StartMiniGameRequestEvent::Handler(this, &Snooze::OnStartMiniGameRequestEvent);
    StopMiniGameRequestEvent::Handlers +=
        StopMiniGameRequestEvent::Handler(this, &Snooze::OnStopMiniGameRequestEvent);
    GameOverRequestedEvent::Handlers +=
        GameOverRequestedEvent::Handler(this, &Snooze::OnGameOverRequestedEvent);
    GameOverEvent::Handlers +=
        GameOverEvent::Handler(this, &Snooze::OnGameOverEvent);
    RetryRequestedEvent::Handlers +=
        RetryRequestedEvent::Handler(this, &Snooze::OnRetryRequestedEvent);
    QuitRequestedEvent::Handlers +=
        QuitRequestedEvent::Handler(this, &Snooze::OnQuitRequestedEvent);

    RegisterGameState<BaseGameState>();
    RegisterGameState<GameOverState>();
    AddBidirectionalLink(BaseGameState::Id, GameOverState::Id);
    RequestState(BaseGameState::Id);

    PlayMusic(forge::DataAPI::GetDataFrom<MusicCatalog>(DataList::Music::Ambient), true);
}

//----------------------------------------------------------------------------
void Snooze::OnQuit()
{
    StartMiniGameRequestEvent::Handlers -=
        StartMiniGameRequestEvent::Handler(this, &Snooze::OnStartMiniGameRequestEvent);
    StopMiniGameRequestEvent::Handlers -=
        StopMiniGameRequestEvent::Handler(this, &Snooze::OnStopMiniGameRequestEvent);
    GameOverRequestedEvent::Handlers -=
        GameOverRequestedEvent::Handler(this, &Snooze::OnGameOverRequestedEvent);
    GameOverEvent::Handlers -=
        GameOverEvent::Handler(this, &Snooze::OnGameOverEvent);
    RetryRequestedEvent::Handlers -=
        RetryRequestedEvent::Handler(this, &Snooze::OnRetryRequestedEvent);
    QuitRequestedEvent::Handlers -=
        QuitRequestedEvent::Handler(this, &Snooze::OnQuitRequestedEvent);
}

//----------------------------------------------------------------------------
void Snooze::OnStartMiniGameRequestEvent(const StartMiniGameRequestEvent& _event)
{
    static std::random_device rd;

    m_CurrentGame = m_MiniGames[rd() % m_MiniGames.size()];

    if (m_CurrentGame == SampleMiniGameComponent::Id)
    {
        m_GameEntity->AddComponent<SampleMiniGameComponent>();
    }
    else if (m_CurrentGame == PadlockMiniGameComponent::Id)
    {
        m_GameEntity->AddComponent<PadlockMiniGameComponent>();
    }
    else if (m_CurrentGame == MouseAttackMiniGameComponent::Id)
    {
        m_GameEntity->AddComponent<MouseAttackMiniGameComponent>();
    }
    else if (m_CurrentGame == BatteryMiniGameComponent::Id)
    {
        m_GameEntity->AddComponent<BatteryMiniGameComponent>();
    }
    else if (m_CurrentGame == VerminsMiniGameComponent::Id)
    {
        m_GameEntity->AddComponent<VerminsMiniGameComponent>();
    }
}

//----------------------------------------------------------------------------
void Snooze::OnStopMiniGameRequestEvent(const StopMiniGameRequestEvent& _event)
{
    if (m_CurrentGame == SampleMiniGameComponent::Id)
    {
        m_GameEntity->RemoveComponent<SampleMiniGameComponent>();
    }
    else if (m_CurrentGame == PadlockMiniGameComponent::Id)
    {
        m_GameEntity->RemoveComponent<PadlockMiniGameComponent>();
    }
    else if (m_CurrentGame == MouseAttackMiniGameComponent::Id)
    {
        m_GameEntity->RemoveComponent<MouseAttackMiniGameComponent>();
    }
    else if (m_CurrentGame == BatteryMiniGameComponent::Id)
    {
        m_GameEntity->RemoveComponent<BatteryMiniGameComponent>();
    }
    else if (m_CurrentGame == VerminsMiniGameComponent::Id)
    {
        m_GameEntity->RemoveComponent<VerminsMiniGameComponent>();
    }

    m_CurrentGame = forge::AbstractComponent::Id;
}

//----------------------------------------------------------------------------
void Snooze::OnGameOverRequestedEvent(const GameOverRequestedEvent& _event)
{
    // Let minigame clean and send GameOverEvent
    if (m_CurrentGame != forge::AbstractComponent::Id)
        return;

    GameOverEvent::Broadcast(_event.GetIsSuccessful());
}

//----------------------------------------------------------------------------
void Snooze::OnGameOverEvent(const GameOverEvent& _event)
{
    s_GameCompleted = _event.GetIsSuccessful();

    Story::GetInstance().Reset();
    forge::PresentationAPI::SetCursor(forge::Cursor::Arrow);

    RequestState(GameOverState::Id);
}

//----------------------------------------------------------------------------
void Snooze::OnRetryRequestedEvent(const RetryRequestedEvent& _event)
{
    RequestState(BaseGameState::Id);
}

//----------------------------------------------------------------------------
void Snooze::OnQuitRequestedEvent(const QuitRequestedEvent& _event)
{
    Stop();
}
