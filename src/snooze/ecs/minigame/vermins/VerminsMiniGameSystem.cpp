#include <snooze/Precomp.h>
#include <snooze/ecs/minigame/vermins/VerminsMiniGameSystem.h>

#include <iostream>
#include <algorithm>
#include <random>

#include <forge/engine/data/api/DataAPI.h>
#include <forge/engine/ecs/Entity.h>

#include <snooze/data/DataList.h>
#include <snooze/data/EntityCatalog.h>
#include <snooze/GameEvents.h>

//----------------------------------------------------------------------------
VerminsMiniGameSystem::VerminsMiniGameSystem()
    : m_ToolAcquired(false)
    , m_Tool(nullptr)
    , m_MaxVermins(0)
    , m_KeyAcquired(false)
    , m_Victory(false)
{
}

//----------------------------------------------------------------------------
void VerminsMiniGameSystem::Execute(const u64& _dt, const forge::Entity::Ptr& _entity)
{
    static std::random_device rd;
    VerminsMiniGameComponent& comp = _entity->GetComponent<VerminsMiniGameComponent>();

    BaseMiniGame::Update(comp);

    // Lock'n'loaded?
    if (m_ToolAcquired)
    {
        if (m_Tool != nullptr)
        {
            ItemAcquieredEvent::Broadcast(m_Tool);
            RequestRemoveEntity(m_Tool);
            m_Tool = nullptr;
        }
        if (m_KeyAcquired && m_Key != nullptr) {
            ItemLostEvent::Broadcast();
            ItemAcquieredEvent::Broadcast(m_Key);
            RequestRemoveEntity(m_Key);
            m_Key = nullptr;
        }
        if (m_Victory) {
            Reset();
            BaseMiniGame::CompleteGame(comp);
        }

        // Check for clicked vermins, purge them with holy fire
        auto it = m_Vermins.begin();

        while (it != m_Vermins.end())
        {
            if (it->second)
            {
                if (m_Key == nullptr)
                {
                    // Chance for spawning they key : 1/3
                    bool keySpawn = rd() % 3 == 0;

                    // Making sure the key always spawn for the last kill
                    if (keySpawn || m_Vermins.size() == 1)
                    {
                        m_Key = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::LockKey);
                        forge::Vector3f keyPosition = it->first->GetPosition();
                        m_Key->SetPosition(keyPosition.x, keyPosition.y, 9.f);
                        RequestAddEntity(m_Key);
                    }
                }

                RequestRemoveEntity(it->first);
                it = m_Vermins.erase(it);
            }
            else {
                ++it;
            }
        }
    }
}

//----------------------------------------------------------------------------
void VerminsMiniGameSystem::Reset()
{
    RequestRemoveEntity(m_Tool);
    m_Tool = nullptr;
    RequestRemoveEntity(m_Key);
    m_Key = nullptr;
    RequestRemoveEntity(m_Lock);
    m_Lock = nullptr;
    RequestRemoveEntity(m_MetalBox);
    m_MetalBox = nullptr;


    auto it = m_Vermins.begin();

    while (it != m_Vermins.end())
    {
        RequestRemoveEntity(it->first);
        it = m_Vermins.erase(it);
    }

    ItemLostEvent::Broadcast();

    m_ToolAcquired = m_Victory = m_KeyAcquired = false;
    m_MaxVermins = 0;
    m_Vermins.clear();
}

//----------------------------------------------------------------------------
void VerminsMiniGameSystem::OnMiniGameStart()
{
    forge::builtin::EntityClickedEvent::Handlers +=
        forge::builtin::EntityClickedEvent::Handler(this, &VerminsMiniGameSystem::OnEntityClickedEvent);

    static std::random_device rd;
    m_MaxVermins = rd() % 5 + 1;

    m_Lock = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::LockLock);
    m_Lock->SetPosition(50.f - m_Lock->GetSize().w * 0.5f, 50.f - m_Lock->GetSize().d * 0.5f, 4.f);
    RequestAddEntity(m_Lock);
    m_MetalBox = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::LockMetalBox);
    m_MetalBox->SetPosition(50.f - m_MetalBox->GetSize().w * 0.5f, 50.f - m_MetalBox->GetSize().d * 0.5f, 3.f);
    RequestAddEntity(m_MetalBox);

    forge::Vector<forge::Vector3f> spawnPoints;
    for (u32 i = 0; i < SnoozeConfig::MobSpawnPointCount; i++)
    {
        spawnPoints.push_back(SnoozeConfig::MobSpawnPoints[i]);
    }
    std::random_shuffle(spawnPoints.begin(), spawnPoints.end());

    // Populating the array with vermins
    for (int i = 0; i < m_MaxVermins; i++)
    {
        forge::Entity::Ptr vermin = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::VerminEnemy);
        forge::Vector3f randLocation = spawnPoints[i];
        vermin->SetPosition(randLocation.x, randLocation.y, randLocation.z);
        RequestAddEntity(vermin);
        m_Vermins.push_back({vermin, false});
    }

    m_Tool = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::CleaningBroom);
    m_Tool->SetPosition(53.f, 53.f, 10.f);
    RequestAddEntity(m_Tool);
}

//----------------------------------------------------------------------------
void VerminsMiniGameSystem::OnMiniGameStop()
{
    forge::builtin::EntityClickedEvent::Handlers -=
        forge::builtin::EntityClickedEvent::Handler(this, &VerminsMiniGameSystem::OnEntityClickedEvent);

    Reset();
}

//----------------------------------------------------------------------------
void VerminsMiniGameSystem::OnEntityClickedEvent(const forge::builtin::EntityClickedEvent& _event)
{
    if (_event.GetIsPressed())
        return;

    if (_event.GetEntity() == m_Tool)
    {
        m_ToolAcquired = true;
    }
    else if (_event.GetEntity() == m_Key)
    {
        m_KeyAcquired = true;
    }
    else if (_event.GetEntity() == m_Lock && m_KeyAcquired)
    {
        m_Victory = true;
    }

    if (m_ToolAcquired)
    {
        for (auto & vermin : m_Vermins)
        {
            if (_event.GetEntity() == vermin.first)
            {
                vermin.second = true;
            }
        }
    }
}
