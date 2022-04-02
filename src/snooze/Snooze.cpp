#include <snooze/Precomp.h>
#include <snooze/Snooze.h>

#include <random>

#include <forge/engine/camera/api/CameraAPI.h>
#include <forge/engine/data/api/DataAPI.h>

#include <snooze/data/DataList.h>
#include <snooze/data/EntityCatalog.h>
#include <snooze/data/FontCatalog.h>
#include <snooze/data/SpriteCatalog.h>
#include <snooze/data/TextureCatalog.h>
#include <snooze/ecs/minigame/sample/SampleMiniGameComponent.h>
#include <snooze/gamestate/BaseGameState.h>


//----------------------------------------------------------------------------
Snooze::Snooze()
{
    m_MiniGames.push_back(SampleMiniGameComponent::Id);
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


    m_World.Init(100.f, 100.f);

    forge::Entity::Ptr alarm = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::Alarm);
    alarm->SetPosition(50.f - alarm->GetSize().w * 0.5f, 50.f - alarm->GetSize().d * 0.5f, 1.f);
    m_World.AddEntity(alarm);

    forge::Entity::Ptr screw1 = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::LockChainBack);
    screw1->SetPosition(50.f - screw1->GetSize().w * 0.5f, 50.f - screw1->GetSize().d * 0.5f, 0.f);
    m_World.AddEntity(screw1);

    forge::Entity::Ptr screw = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::LockChainFront);
    screw->SetPosition(50.f - screw->GetSize().w * 0.5f, 50.f - screw->GetSize().d * 0.5f, 1.f);
    m_World.AddEntity(screw);

    forge::Entity::Ptr button = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::LockLock);
    button->SetPosition(50.f - button->GetSize().w * 0.5f, 50.f - button->GetSize().d * 0.5f, 1.f);
    m_World.AddEntity(button);

    forge::CameraAPI::SetLookAt({50.f, 50.f, 0.f});
    forge::CameraAPI::SetDistance(10);
    forge::CameraAPI::SetFieldOfView(90);
    forge::CameraAPI::SetFilmedWorld(GetWorld());

    StartMiniGameRequestEvent::Handlers +=
        StartMiniGameRequestEvent::Handler(this, &Snooze::OnStartMiniGameRequestEvent);
    StopMiniGameRequestEvent::Handlers +=
        StopMiniGameRequestEvent::Handler(this, &Snooze::OnStopMiniGameRequestEvent);

    RegisterGameState<BaseGameState>();
    RequestState(BaseGameState::Id);
}

//----------------------------------------------------------------------------
void Snooze::OnQuit()
{
    StartMiniGameRequestEvent::Handlers -=
        StartMiniGameRequestEvent::Handler(this, &Snooze::OnStartMiniGameRequestEvent);
    StopMiniGameRequestEvent::Handlers -=
        StopMiniGameRequestEvent::Handler(this, &Snooze::OnStopMiniGameRequestEvent);
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
}

//----------------------------------------------------------------------------
void Snooze::OnStopMiniGameRequestEvent(const StopMiniGameRequestEvent& _event)
{
    if (m_CurrentGame == SampleMiniGameComponent::Id)
    {
        m_GameEntity->RemoveComponent<SampleMiniGameComponent>();
    }
}
