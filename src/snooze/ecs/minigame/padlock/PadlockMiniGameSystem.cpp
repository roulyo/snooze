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
        RequestRemoveEntity(m_MetalBox);
        m_Lock = m_MetalBox = nullptr;

        BaseMiniGame::CompleteGame(comp);
    }
}

//----------------------------------------------------------------------------
void PadlockMiniGameSystem::Reset()
{

    RequestRemoveEntity(m_Key);
    RequestRemoveEntity(m_Lock);
    RequestRemoveEntity(m_MetalBox);

    m_Key = nullptr;
    m_Lock = m_MetalBox = nullptr;

    ItemLostEvent::Broadcast();

    // Initialize minigame variables
    m_KeyAcquired = m_PadlockUnlocked = false;
}

//----------------------------------------------------------------------------
void PadlockMiniGameSystem::OnMiniGameStart()
{
    static std::random_device rd;

    forge::builtin::EntityClickedEvent::Handlers +=
        forge::builtin::EntityClickedEvent::Handler(this, &PadlockMiniGameSystem::OnEntityClickedEvent);

    // Setup the lock aesthetics
    m_Lock = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::LockLock);
    m_Lock->SetPosition(50.f - m_Lock->GetSize().w * 0.5f, 50.f - m_Lock->GetSize().d * 0.5f, 4.f);
    RequestAddEntity(m_Lock);
    m_MetalBox = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::LockMetalBox);
    m_MetalBox->SetPosition(50.f - m_MetalBox->GetSize().w * 0.5f, 50.f - m_MetalBox->GetSize().d * 0.5f, 3.f);
    RequestAddEntity(m_MetalBox);

    // Pop the key at a random place (40-58)
    forge::Vector3f rand_location = SnoozeConfig::KeysSpawnPoints[rd() % SnoozeConfig::KeysSpawnPointCount];
    m_Key = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::LockKey);
    m_Key->SetPosition(rand_location.x, rand_location.y, rand_location.z);
    RequestAddEntity(m_Key);
}

//----------------------------------------------------------------------------
void PadlockMiniGameSystem::OnMiniGameStop()
{
    forge::builtin::EntityClickedEvent::Handlers -=
        forge::builtin::EntityClickedEvent::Handler(this, &PadlockMiniGameSystem::OnEntityClickedEvent);

    Reset();
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
