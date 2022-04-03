#include <snooze/Precomp.h>
#include <snooze/Snooze.h>
#include <snooze/Story.h>

#include <random>

#include <forge/engine/camera/api/CameraAPI.h>
#include <forge/engine/data/api/DataAPI.h>

#include <snooze/data/DataList.h>
#include <snooze/data/EntityCatalog.h>
#include <snooze/data/FontCatalog.h>
#include <snooze/data/SpriteCatalog.h>
#include <snooze/data/TextureCatalog.h>
#include <snooze/ecs/minigame/sample/SampleMiniGameComponent.h>
#include <snooze/ecs/minigame/padlock/PadlockMiniGameComponent.h>
#include <snooze/ecs/minigame/mouseattack/MouseAttackMiniGameComponent.h>
#include <snooze/gamestate/BaseGameState.h>
#include <snooze/gamestate/GameOverState.h>


//----------------------------------------------------------------------------
Snooze::Snooze()
{
    m_MiniGames.push_back(SampleMiniGameComponent::Id);
    m_MiniGames.push_back(PadlockMiniGameComponent::Id);
    m_MiniGames.push_back(MouseAttackMiniGameComponent::Id);
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
    RegisterCatalogType<SpriteCatalog>();
    RegisterCatalogType<TextureCatalog>();


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
    GameOverEvent::Handlers +=
        GameOverEvent::Handler(this, &Snooze::OnGameOverEvent);

    RegisterGameState<BaseGameState>();
    RegisterGameState<GameOverState>();
    AddBidirectionalLink(BaseGameState::Id, GameOverState::Id);
    RequestState(BaseGameState::Id);
}

//----------------------------------------------------------------------------
void Snooze::OnQuit()
{
    StartMiniGameRequestEvent::Handlers -=
        StartMiniGameRequestEvent::Handler(this, &Snooze::OnStartMiniGameRequestEvent);
    StopMiniGameRequestEvent::Handlers -=
        StopMiniGameRequestEvent::Handler(this, &Snooze::OnStopMiniGameRequestEvent);
    GameOverEvent::Handlers -=
        GameOverEvent::Handler(this, &Snooze::OnGameOverEvent);
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
}

void Snooze::OnGameOverEvent(const GameOverEvent& _event)
{
    RequestState(GameOverState::Id);
}
