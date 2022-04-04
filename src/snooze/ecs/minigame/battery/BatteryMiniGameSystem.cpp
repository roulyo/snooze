#include <snooze/Precomp.h>
#include <snooze/ecs/minigame/battery/BatteryMiniGameSystem.h>

#include <iostream>
#include <random>

#include <forge/engine/data/api/DataAPI.h>
#include <forge/engine/ecs/Entity.h>

#include <snooze/GameEvents.h>
#include <snooze/data/DataList.h>
#include <snooze/data/EntityCatalog.h>

//----------------------------------------------------------------------------
BatteryMiniGameSystem::BatteryMiniGameSystem()
    : m_alarmOpened(false)
    , m_screwdriverPicked(false)
    , m_gameSolved(false)
    , m_mouseIsAlive(true)
    , m_batteryCollected(false)
{
}

//----------------------------------------------------------------------------
void BatteryMiniGameSystem::Execute(const u64& _dt, const forge::Entity::Ptr& _entity)
{
    BatteryMiniGameComponent &comp = _entity->GetComponent<BatteryMiniGameComponent>();

    BaseMiniGame::Update(comp);

    if (m_screwdriverPicked && m_Screwdriver != nullptr)
    {
        m_Screw->GetComponent<SoundClickableComponent>().SetIsMute(false);
        ItemAcquieredEvent::Broadcast(m_Screwdriver);
        RequestRemoveEntity(m_Screwdriver);
        m_Screwdriver = nullptr;
    } else if (m_alarmOpened && m_Screw != nullptr)
    {
        ItemLostEvent::Broadcast();
        m_Screw->GetComponent<SoundClickableComponent>().SetIsMute(true);
        RequestRemoveEntity(m_Screw);
        m_Screw = nullptr;

        RequestAddEntity(m_OpenAlarm);
        RequestAddEntity(m_BatteryContainer);
        RequestAddEntity(m_Mouse);
    } else if (!m_mouseIsAlive && m_Battery == nullptr && !m_batteryCollected)
    {
        forge::builtin::RenderableComponent& renderComp = m_Mouse->GetComponent<forge::builtin::RenderableComponent>();
        renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::BatteryKOMouse));

        m_Battery = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::BatteryItem);
        m_Battery->SetPosition(53.f, 53.f, 8.f);
        RequestAddEntity(m_Battery);
    } else if (m_batteryCollected && m_Battery != nullptr)
    {
        m_BatteryContainer->GetComponent<SoundClickableComponent>().SetIsMute(false);
        ItemAcquieredEvent::Broadcast(m_Battery);
        RequestRemoveEntity(m_Battery);
        m_Battery = nullptr;
    } else if (m_gameSolved && !m_EndGameTimer.IsStarted()) {
        forge::builtin::RenderableComponent& renderComp = m_BatteryContainer->GetComponent<forge::builtin::RenderableComponent>();
        renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::BatteryCompleteSprite));
        ItemLostEvent::Broadcast();
        m_EndGameTimer.Start(1000);
    }

    if (m_EndGameTimer.IsStarted())
    {
        if (m_EndGameTimer.IsElapsed())
        {
            m_EndGameTimer.Stop();

            RequestRemoveEntity(m_OpenAlarm);
            if (m_Screw != nullptr)
            {
                m_Screw->GetComponent<SoundClickableComponent>().SetIsMute(true);
            }
            RequestRemoveEntity(m_Screw);
            RequestRemoveEntity(m_Screwdriver);
            RequestRemoveEntity(m_Mouse);
            RequestRemoveEntity(m_Battery);
            if (m_BatteryContainer != nullptr)
            {
                m_BatteryContainer->GetComponent<SoundClickableComponent>().SetIsMute(true);
            }
            RequestRemoveEntity(m_BatteryContainer);

            m_OpenAlarm = m_Screwdriver = m_Screw = nullptr;
            m_Mouse = m_Battery = m_BatteryContainer = nullptr;

            m_gameSolved = m_screwdriverPicked = m_alarmOpened = m_batteryCollected = false;
            m_mouseIsAlive = true;

            BaseMiniGame::CompleteGame(comp);
        }
    }
}

//----------------------------------------------------------------------------
void BatteryMiniGameSystem::Reset()
{
    RequestRemoveEntity(m_OpenAlarm);
    if (m_Screw != nullptr)
    {
        m_Screw->GetComponent<SoundClickableComponent>().SetIsMute(true);
    }
    RequestRemoveEntity(m_Screw);
    RequestRemoveEntity(m_Screwdriver);
    RequestRemoveEntity(m_Mouse);
    RequestRemoveEntity(m_Battery);
    if (m_BatteryContainer != nullptr)
    {
        m_BatteryContainer->GetComponent<SoundClickableComponent>().SetIsMute(true);
    }
    RequestRemoveEntity(m_BatteryContainer);

    m_OpenAlarm = m_Screwdriver = m_Screw = nullptr;
    m_Mouse = m_Battery = m_BatteryContainer = nullptr;

    ItemLostEvent::Broadcast();

    // Initialize minigame variables
    m_gameSolved = m_screwdriverPicked = m_alarmOpened = m_batteryCollected = false;
    m_mouseIsAlive = true;
}

//----------------------------------------------------------------------------
void BatteryMiniGameSystem::OnMiniGameStart()
{
    static std::random_device rd;

    forge::builtin::EntityClickedEvent::Handlers +=
        forge::builtin::EntityClickedEvent::Handler(this, &BatteryMiniGameSystem::OnEntityClickedEvent);

    // Setup the entities
    m_Screw = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::AlarmScrew);
    m_Screw->SetPosition(50.f - m_Screw->GetSize().w * 0.5f, 50.f - m_Screw->GetSize().d * 0.5f, 1.3f);
    RequestAddEntity(m_Screw);

    m_Screwdriver = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::Screwdriver);
    forge::Vector3f rand_location = SnoozeConfig::ToolSpawnPoints[rd() % SnoozeConfig::ToolSpawnPointCount];
    m_Screwdriver->SetPosition(rand_location.x, rand_location.y, rand_location.z);
    RequestAddEntity(m_Screwdriver);

    m_OpenAlarm = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::MouseAttackOpenAlarm);
    m_OpenAlarm->SetPosition(50.f - m_OpenAlarm->GetSize().w * 0.5f, 50.f - m_OpenAlarm->GetSize().d * 0.5f, 1.8f);

    m_Mouse = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::BatteryMouse);
    m_Mouse->SetPosition(50.f - m_Mouse->GetSize().w * 0.5f, 50.f - m_Mouse->GetSize().d * 0.5f, 2.1f);

    m_BatteryContainer = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::BatteryContainer);
    m_BatteryContainer->SetPosition(50.f - m_BatteryContainer->GetSize().w * 0.5f, 50.f - m_BatteryContainer->GetSize().d * 0.5f, 2.1f);
}

//----------------------------------------------------------------------------
void BatteryMiniGameSystem::OnMiniGameStop()
{
    forge::builtin::EntityClickedEvent::Handlers -=
        forge::builtin::EntityClickedEvent::Handler(this, &BatteryMiniGameSystem::OnEntityClickedEvent);

    Reset();
}

//----------------------------------------------------------------------------
void BatteryMiniGameSystem::OnEntityClickedEvent(const forge::builtin::EntityClickedEvent& _event)
{
    if (_event.GetIsPressed())
        return;
    if (_event.GetEntity() == m_Screwdriver)
    {
        m_screwdriverPicked = true;
    } else if (_event.GetEntity() == m_Screw && m_screwdriverPicked)
    {
        m_alarmOpened = true;
    } else if (_event.GetEntity() == m_Mouse && m_mouseIsAlive) {
        m_mouseIsAlive = false;
    } else if (_event.GetEntity() == m_Battery) {
        m_batteryCollected = true;
    } else if (_event.GetEntity() == m_BatteryContainer && m_batteryCollected) {
        m_gameSolved = true;
    }
}
