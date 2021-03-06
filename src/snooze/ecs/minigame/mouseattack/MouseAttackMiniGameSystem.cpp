#include <snooze/Precomp.h>
#include <snooze/ecs/minigame/mouseattack/MouseAttackMiniGameSystem.h>

#include <iostream>
#include <random>

#include <forge/engine/data/api/DataAPI.h>
#include <forge/engine/ecs/Entity.h>

#include <snooze/GameEvents.h>
#include <snooze/data/DataList.h>
#include <snooze/data/EntityCatalog.h>

//----------------------------------------------------------------------------
MouseAttackMiniGameSystem::MouseAttackMiniGameSystem()
    : m_alarmOpened(false)
    , m_screwdriverPicked(false)
    , m_gameSolved(false)
    , m_fireStopped(false)
    , m_gotWater(false)
{
}

//----------------------------------------------------------------------------
void MouseAttackMiniGameSystem::Execute(const u64& _dt, const forge::Entity::Ptr& _entity)
{
    MouseAttackMiniGameComponent &comp = _entity->GetComponent<MouseAttackMiniGameComponent>();

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
        RequestAddEntity(m_BbqMouse);
        RequestAddEntity(m_WaterGlass);
    } else if (m_gotWater && m_WaterGlass != nullptr)
    {
        m_BbqMouse->GetComponent<SoundClickableComponent>().SetIsMute(false);
        ItemAcquieredEvent::Broadcast(m_WaterGlass);
        RequestRemoveEntity(m_WaterGlass);
        m_WaterGlass = nullptr;
    } else if (m_fireStopped && m_BbqMouse != nullptr)
    {
        ItemLostEvent::Broadcast();
        m_BbqMouse->GetComponent<SoundClickableComponent>().SetIsMute(true);
        RequestRemoveEntity(m_BbqMouse);
        m_BbqMouse = nullptr;
        RequestRemoveEntity(m_Smoke);
        m_Smoke = nullptr;
        RequestAddEntity(m_WetMouse);

        m_EndGameTimer.Start(1000);
    }

    if (m_EndGameTimer.IsStarted())
    {
        if (m_EndGameTimer.IsElapsed())
        {
            m_EndGameTimer.Stop();

            RequestRemoveEntity(m_SnoozeButton);
            RequestRemoveEntity(m_Smoke);
            if (m_Screw != nullptr)
            {
                m_Screw->GetComponent<SoundClickableComponent>().SetIsMute(true);
            }
            RequestRemoveEntity(m_Screw);
            RequestRemoveEntity(m_Screwdriver);
            if (m_BbqMouse != nullptr)
            {
                m_BbqMouse->GetComponent<SoundClickableComponent>().SetIsMute(true);
            }
            RequestRemoveEntity(m_BbqMouse);
            RequestRemoveEntity(m_WetMouse);
            RequestRemoveEntity(m_OpenAlarm);
            RequestRemoveEntity(m_WaterGlass);

            m_SnoozeButton = m_Smoke = m_Screw = nullptr;
            m_BbqMouse = m_WetMouse = m_OpenAlarm = nullptr;
            m_WaterGlass = m_Screwdriver = nullptr;

            BaseMiniGame::CompleteGame(comp);
        }
    }
}

//----------------------------------------------------------------------------
void MouseAttackMiniGameSystem::Reset()
{
    RequestRemoveEntity(m_SnoozeButton);
    RequestRemoveEntity(m_Smoke);
    if (m_Screw != nullptr)
    {
        m_Screw->GetComponent<SoundClickableComponent>().SetIsMute(true);
    }
    RequestRemoveEntity(m_Screw);
    RequestRemoveEntity(m_Screwdriver);
    if (m_BbqMouse != nullptr)
    {
        m_BbqMouse->GetComponent<SoundClickableComponent>().SetIsMute(true);
    }
    RequestRemoveEntity(m_BbqMouse);
    RequestRemoveEntity(m_WetMouse);
    RequestRemoveEntity(m_OpenAlarm);
    RequestRemoveEntity(m_WaterGlass);

    m_SnoozeButton = m_Smoke = m_Screw = nullptr;
    m_BbqMouse = m_WetMouse = m_OpenAlarm = nullptr;
    m_WaterGlass = m_Screwdriver = nullptr;

    ItemLostEvent::Broadcast();

    // Initialize minigame variables
    m_alarmOpened = m_screwdriverPicked = m_fireStopped = m_gotWater = m_gameSolved = false;
}

//----------------------------------------------------------------------------
void MouseAttackMiniGameSystem::OnMiniGameStart()
{
    static std::random_device rd;

    forge::builtin::EntityClickedEvent::Handlers +=
        forge::builtin::EntityClickedEvent::Handler(this, &MouseAttackMiniGameSystem::OnEntityClickedEvent);

    // Setup the entities
    m_Screw = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::AlarmScrew);
    m_Screw->SetPosition(50.f - m_Screw->GetSize().w * 0.5f, 50.f - m_Screw->GetSize().d * 0.5f, 1.3f);
    RequestAddEntity(m_Screw);

    m_Screwdriver = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::Screwdriver);
    forge::Vector3f rand_location = SnoozeConfig::ToolSpawnPoints[rd() % SnoozeConfig::ToolSpawnPointCount];
    m_Screwdriver->SetPosition(rand_location.x, rand_location.y, rand_location.z);
    RequestAddEntity(m_Screwdriver);

    m_Smoke = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::MouseAttackSmoke);
    m_Smoke->SetPosition(50.f - m_Smoke->GetSize().w * 0.5f, 50.f - m_Smoke->GetSize().d * 0.5f, 2.f);
    RequestAddEntity(m_Smoke);

    m_OpenAlarm = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::MouseAttackOpenAlarm);
    m_OpenAlarm->SetPosition(50.f - m_OpenAlarm->GetSize().w * 0.5f, 50.f - m_OpenAlarm->GetSize().d * 0.5f, 1.8f);

    m_BbqMouse = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::MouseAttackBbqMouse);
    m_BbqMouse->SetPosition(50.f - m_BbqMouse->GetSize().w * 0.5f, 50.f - m_BbqMouse->GetSize().d * 0.5f, 2.1f);

    m_WetMouse = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::MouseAttackWetMouse);
    m_WetMouse->SetPosition(50.f - m_WetMouse->GetSize().w * 0.5f, 50.f - m_WetMouse->GetSize().d * 0.5f, 2.1f);

    m_WaterGlass = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::MouseAttackWaterGlass);
    m_WaterGlass->SetPosition(55.f, 55.f, 10.f);
}

//----------------------------------------------------------------------------
void MouseAttackMiniGameSystem::OnMiniGameStop()
{
    forge::builtin::EntityClickedEvent::Handlers -=
        forge::builtin::EntityClickedEvent::Handler(this, &MouseAttackMiniGameSystem::OnEntityClickedEvent);

    Reset();
}

//----------------------------------------------------------------------------
void MouseAttackMiniGameSystem::OnEntityClickedEvent(const forge::builtin::EntityClickedEvent& _event)
{
    if (_event.GetIsPressed())
        return;
    if (_event.GetEntity() == m_Screwdriver)
    {
        m_screwdriverPicked = true;
    } else if (_event.GetEntity() == m_Screw && m_screwdriverPicked)
    {
        m_alarmOpened = true;
    } else if (_event.GetEntity() == m_WaterGlass)
    {
        m_gotWater = true;
    } else if (_event.GetEntity() == m_BbqMouse)
    {
        if (m_gotWater) {
            m_fireStopped = true;
        }
    }
}
