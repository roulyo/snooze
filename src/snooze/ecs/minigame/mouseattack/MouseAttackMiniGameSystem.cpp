#include <snooze/Precomp.h>
#include <snooze/ecs/minigame/mouseattack/MouseAttackMiniGameSystem.h>

#include <iostream>
#include <random>

#include <forge/engine/data/api/DataAPI.h>
#include <forge/engine/ecs/Entity.h>

#include <snooze/data/DataList.h>
#include <snooze/data/EntityCatalog.h>

//----------------------------------------------------------------------------
MouseAttackMiniGameSystem::MouseAttackMiniGameSystem()
    : m_alarmOpened(false)
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

    // TODO Later
    if (m_gameSolved)
    {
        std::cout << "Mouse attack finished" << std::endl;
        RequestRemoveEntity(m_SnoozeButton);
        RequestRemoveEntity(m_Smoke);
        RequestRemoveEntity(m_Screw);
        RequestRemoveEntity(m_BbqMouse);
        RequestRemoveEntity(m_WetMouse);
        RequestRemoveEntity(m_OpenAlarm);
        RequestRemoveEntity(m_WaterGlass);

        m_SnoozeButton = m_Smoke = m_Screw = nullptr;
        m_BbqMouse = m_WetMouse = m_OpenAlarm = nullptr;
        m_WaterGlass = nullptr;

        BaseMiniGame::CompleteGame(comp);
    }
}

//----------------------------------------------------------------------------
void MouseAttackMiniGameSystem::OnMiniGameStart()
{
    static std::random_device rd;

    forge::builtin::EntityClickedEvent::Handlers +=
        forge::builtin::EntityClickedEvent::Handler(this, &MouseAttackMiniGameSystem::OnEntityClickedEvent);

    // Setup the entities
    m_Screw = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::AlarmScrew);
    m_Screw->SetPosition(50.f - m_Screw->GetSize().w * 0.5f, 50.f - m_Screw->GetSize().d * 0.5f, 0.4f);
    RequestAddEntity(m_Screw);

    m_Smoke = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::MouseAttackSmoke);
    m_Smoke->SetPosition(50.f - m_Smoke->GetSize().w * 0.5f, 50.f - m_Smoke->GetSize().d * 0.5f, 1.f);
    RequestAddEntity(m_Smoke);

    m_OpenAlarm = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::MouseAttackOpenAlarm);
    m_OpenAlarm->SetPosition(50.f - m_OpenAlarm->GetSize().w * 0.5f, 50.f - m_OpenAlarm->GetSize().d * 0.5f, 0.4f);

    m_BbqMouse = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::MouseAttackBbqMouse);
    m_BbqMouse->SetPosition(50.f - m_BbqMouse->GetSize().w * 0.5f, 50.f - m_BbqMouse->GetSize().d * 0.5f, 0.5f);

    m_WetMouse = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::MouseAttackWetMouse);
    m_WetMouse->SetPosition(50.f - m_WetMouse->GetSize().w * 0.5f, 50.f - m_WetMouse->GetSize().d * 0.5f, 0.5f);

    m_WaterGlass = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::MouseAttackWaterGlass);
    m_WaterGlass->SetPosition(55, 55, 10);

    // Initialize minigame variables
    m_alarmOpened = false;
}

//----------------------------------------------------------------------------
void MouseAttackMiniGameSystem::OnMiniGameStop()
{
    forge::builtin::EntityClickedEvent::Handlers -=
        forge::builtin::EntityClickedEvent::Handler(this, &MouseAttackMiniGameSystem::OnEntityClickedEvent);
}

//----------------------------------------------------------------------------
void MouseAttackMiniGameSystem::OnEntityClickedEvent(const forge::builtin::EntityClickedEvent& _event)
{
    if (_event.GetIsPressed())
        return;
    if (_event.GetEntity() == m_Screw)
    {
        RequestRemoveEntity(m_Screw);
        RequestAddEntity(m_OpenAlarm);
        RequestAddEntity(m_BbqMouse);
        RequestAddEntity(m_WaterGlass);
        m_alarmOpened = true;
    } else if (_event.GetEntity() == m_WaterGlass)
    {
        RequestRemoveEntity(m_WaterGlass);
        m_gotWater = true;
    } else if (_event.GetEntity() == m_BbqMouse)
    {
        if (m_gotWater) {
            RequestRemoveEntity(m_BbqMouse);
            RequestRemoveEntity(m_Smoke);
            RequestAddEntity(m_WetMouse);
            m_fireStopped = true;
        }
    } else if (_event.GetEntity() == m_WetMouse)
    {
        if (m_fireStopped) {
            m_gameSolved = true;
        }
    }
}