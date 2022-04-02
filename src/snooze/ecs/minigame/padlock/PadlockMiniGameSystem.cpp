#include <snooze/Precomp.h>
#include <snooze/ecs/minigame/padlock/PadlockMiniGameSystem.h>

#include <iostream>

#include <forge/engine/data/api/DataAPI.h>
#include <forge/engine/ecs/Entity.h>

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
        RequestRemoveEntity(m_Key);
        m_Key = nullptr;
    }
    if (m_PadlockUnlocked)
    {
        RequestRemoveEntity(m_Lock);
        m_Lock = nullptr;

        BaseMiniGame::CompleteGame(comp);
    }
}

//----------------------------------------------------------------------------
void PadlockMiniGameSystem::OnMiniGameStart()
{
    forge::builtin::EntityClickedEvent::Handlers +=
        forge::builtin::EntityClickedEvent::Handler(this, &PadlockMiniGameSystem::OnEntityClickedEvent);

    std::cout << "Padlock start" << std::endl;

    m_Lock = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::LockLock);
    m_Lock->SetPosition(57, 57, 10);
    RequestAddEntity(m_Lock);

    m_Key = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::LockKey);
    m_Key->SetPosition(78, 72, 10);
    RequestAddEntity(m_Key);
/*
forge::Entity::Ptr screw1 = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::LockChainBack);
    screw1->SetPosition(50.f - screw1->GetSize().w * 0.5f, 50.f - screw1->GetSize().d * 0.5f, 0.f);
    m_World.AddEntity(screw1);

    forge::Entity::Ptr screw = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::LockChainFront);
    screw->SetPosition(50.f - screw->GetSize().w * 0.5f, 50.f - screw->GetSize().d * 0.5f, 1.f);
    m_World.AddEntity(screw);

    forge::Entity::Ptr button = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::LockLock);
    button->SetPosition(50.f - button->GetSize().w * 0.5f, 50.f - button->GetSize().d * 0.5f, 1.f);
    m_World.AddEntity(button);
*/
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
