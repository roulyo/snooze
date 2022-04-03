#include <snooze/Precomp.h>
#include <snooze/ecs/minigame/vermins/VerminsMiniGameSystem.h>

#include <iostream>
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
    , m_TimeToVermin(5000)
    , m_FirstRun (true)
{
}

//----------------------------------------------------------------------------
void VerminsMiniGameSystem::Execute(const u64& _dt, const forge::Entity::Ptr& _entity)
{
    static std::random_device rd;
    VerminsMiniGameComponent& comp = _entity->GetComponent<VerminsMiniGameComponent>();

    BaseMiniGame::Update(comp);

    // Spawn new vermin, restart Timer
    if (m_FirstRun or (m_Timer.IsElapsed() && m_Vermins.size() <= m_MaxVermins))
    {
        m_FirstRun = false;
        forge::Entity::Ptr vermin = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::VerminEnemy);
        u8 randX, randY = 0;
        do
        {
            randX = rd() % (56 - 40 + 1) + 40;
            randY = rd() % (56 - 40 + 1) + 40;
        } while (randX < 42 and randY < 42);
        vermin->SetPosition(randX, randY, 10.f);
        RequestAddEntity(vermin);
        m_Vermins.push_back({vermin, false});
        m_Timer.Start(m_TimeToVermin);
    }

    // Lock'n'loaded?
    if (m_ToolAcquired)
    {
        if (m_Tool != nullptr)
        {
            ItemAcquieredEvent::Broadcast(m_Tool);
            RequestRemoveEntity(m_Tool);
            m_Tool = nullptr;
        }

        // Check for clicked vermins, purge them with holy fire
        auto it = m_Vermins.begin();

        while (it != m_Vermins.end())
        {
            if (it->second)
            {
                RequestRemoveEntity(it->first);
                it = m_Vermins.erase(it);
            }
            else {
                ++it;
            }
        }

        // Are you winning son
        if (m_Vermins.size() == 0)
        {
            ItemLostEvent::Broadcast();
            BaseMiniGame::CompleteGame(comp);
        }
    }
}

//----------------------------------------------------------------------------
void VerminsMiniGameSystem::Reset()
{
    RequestRemoveEntity(m_Tool);
    m_Tool = nullptr;

    auto it = m_Vermins.begin();

    while (it != m_Vermins.end())
    {
        RequestRemoveEntity(it->first);
        it = m_Vermins.erase(it);
    }

    ItemLostEvent::Broadcast();

    m_ToolAcquired = false;
    m_Tool = nullptr;
    m_MaxVermins = 0;
    m_Timer.Stop();
    m_Vermins.clear();
}

//----------------------------------------------------------------------------
void VerminsMiniGameSystem::OnMiniGameStart()
{
    forge::builtin::EntityClickedEvent::Handlers +=
        forge::builtin::EntityClickedEvent::Handler(this, &VerminsMiniGameSystem::OnEntityClickedEvent);

    static std::random_device rd;
    m_FirstRun = true;
    m_MaxVermins = rd() % 11;
    m_Timer.Start(m_TimeToVermin);
    // TODO: Random (or predefined) tool location
    m_Tool = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::CleaningBroom);
    m_Tool->SetPosition(57.f, 57.f, 10.f);
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
