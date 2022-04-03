#include <snooze/Precomp.h>
#include <snooze/ecs/minigame/padlock/PadlockMiniGameSystem.h>

#include <iostream>
#include <random>

#include <forge/engine/data/api/DataAPI.h>
#include <forge/engine/ecs/Entity.h>

#include <snooze/GameEvents.h>
#include <snooze/data/DataList.h>
#include <snooze/data/EntityCatalog.h>

//----------------------------------------------------------------------------
PadlockMiniGameSystem::PadlockMiniGameSystem()
    : m_KeyAcquired(false)
    , m_PadlockUnlocked(false)
{
}

//----------------------------------------------------------------------------
void PadlockMiniGameSystem::Execute(const u64& _dt, const forge::Entity::Ptr& _entity)
{
    PadlockMiniGameComponent& comp = _entity->GetComponent<PadlockMiniGameComponent>();

    BaseMiniGame::Update(comp);

    if (m_KeyAcquired && m_Key != nullptr)
    {
        ItemAcquieredEvent::Broadcast(m_Key);
        RequestRemoveEntity(m_Key);
        m_Key = nullptr;
    }
    if (m_PadlockUnlocked)
    {
        ItemLostEvent::Broadcast();
        RequestRemoveEntity(m_Lock);
        RequestRemoveEntity(m_ChainFront);
        RequestRemoveEntity(m_ChainBack);
        m_Lock = m_ChainFront = m_ChainBack = nullptr;

        BaseMiniGame::CompleteGame(comp);
    }
}

//----------------------------------------------------------------------------
void PadlockMiniGameSystem::OnMiniGameStart()
{
    static forge::Vector<forge::Vector3f> predefined_locations;
    static std::random_device rd;

    // Initialize predefined locations
    predefined_locations.push_back({40.f, 40.f, 10.f});
    predefined_locations.push_back({56.f, 56.f, 10.f});
    predefined_locations.push_back({40.f, 56.f, 10.f});
    predefined_locations.push_back({56.f, 40.f, 10.f});
    predefined_locations.push_back({41.f, 50.f, 1.f});
    predefined_locations.push_back({54.f, 49.f, 1.f});

    forge::builtin::EntityClickedEvent::Handlers +=
        forge::builtin::EntityClickedEvent::Handler(this, &PadlockMiniGameSystem::OnEntityClickedEvent);

    // Setup the lock aesthetics
    m_Lock = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::LockLock);
    m_Lock->SetPosition(50.f - m_Lock->GetSize().w * 0.5f, 50.f - m_Lock->GetSize().d * 0.5f, 2.f);
    RequestAddEntity(m_Lock);
    m_ChainFront = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::LockChainFront);
    m_ChainFront->SetPosition(50.f - m_ChainFront->GetSize().w * 0.5f, 50.f - m_ChainFront->GetSize().d * 0.5f, 1.f);
    RequestAddEntity(m_ChainFront);
    m_ChainBack = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::LockChainBack);
    m_ChainBack->SetPosition(50.f - m_ChainBack->GetSize().w * 0.5f, 50.f - m_ChainBack->GetSize().d * 0.5f, 0.f);
    RequestAddEntity(m_ChainBack);

    // Pop the key at a random place (40-58)
    forge::Vector3f rand_location = predefined_locations[rd() % predefined_locations.size()];
    m_Key = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::LockKey);
    m_Key->SetPosition(rand_location.x, rand_location.y, rand_location.z);
    RequestAddEntity(m_Key);

    // Initialize minigame variables
    m_KeyAcquired = m_PadlockUnlocked = false;
}

//----------------------------------------------------------------------------
void PadlockMiniGameSystem::OnMiniGameStop()
{
    forge::builtin::EntityClickedEvent::Handlers -=
        forge::builtin::EntityClickedEvent::Handler(this, &PadlockMiniGameSystem::OnEntityClickedEvent);
}

//----------------------------------------------------------------------------
void PadlockMiniGameSystem::OnEntityClickedEvent(const forge::builtin::EntityClickedEvent& _event)
{
    if (_event.GetIsPressed())
        return;

    if (_event.GetEntity() == m_Key)
    {
        m_KeyAcquired = true;
    }
    else if (_event.GetEntity() == m_Lock && m_KeyAcquired)
    {
        m_PadlockUnlocked = true;
    }
}
