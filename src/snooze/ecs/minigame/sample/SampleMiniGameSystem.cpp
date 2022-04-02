#include <snooze/Precomp.h>
#include <snooze/ecs/minigame/sample/SampleMiniGameSystem.h>

#include <iostream>

#include <forge/engine/data/api/DataAPI.h>
#include <forge/engine/ecs/Entity.h>

#include <snooze/data/DataList.h>
#include <snooze/data/EntityCatalog.h>

//----------------------------------------------------------------------------
SampleMiniGameSystem::SampleMiniGameSystem()
    : m_BroomAcquiered(false)
    , m_WebCleaning(0)
{
}

//----------------------------------------------------------------------------
void SampleMiniGameSystem::Execute(const u64& _dt, const forge::Entity::Ptr& _entity)
{
    SampleMiniGameComponent& comp = _entity->GetComponent<SampleMiniGameComponent>();

    BaseMiniGame::Update(comp);

    if (m_BroomAcquiered && m_Broom != nullptr)
    {
        RequestRemoveEntity(m_Broom);
        m_Broom = nullptr;
    }

    if (m_WebCleaning > 5)
    {
        RequestRemoveEntity(m_Web);
        m_Web = nullptr;

        BaseMiniGame::CompleteGame(comp);
    }
}

//----------------------------------------------------------------------------
void SampleMiniGameSystem::OnMiniGameStart()
{
    forge::builtin::EntityClickedEvent::Handlers +=
        forge::builtin::EntityClickedEvent::Handler(this, &SampleMiniGameSystem::OnEntityClickedEvent);

    m_Broom = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::Broom);
    m_Broom->SetPosition(57, 57, 10);

    RequestAddEntity(m_Broom);

    m_Web = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::Web);
    m_Web->SetPosition(48, 42, 10);

    RequestAddEntity(m_Web);
}

//----------------------------------------------------------------------------
void SampleMiniGameSystem::OnMiniGameStop()
{
    forge::builtin::EntityClickedEvent::Handlers -=
        forge::builtin::EntityClickedEvent::Handler(this, &SampleMiniGameSystem::OnEntityClickedEvent);
}

//----------------------------------------------------------------------------
void SampleMiniGameSystem::OnEntityClickedEvent(const forge::builtin::EntityClickedEvent& _event)
{
    if (_event.GetIsPressed())
        return;

    if (_event.GetEntity() == m_Broom)
    {
        m_BroomAcquiered = true;
    }
    else if (_event.GetEntity() == m_Web && m_BroomAcquiered)
    {
        ++m_WebCleaning;

        m_Web->GetComponent<forge::builtin::RenderableComponent>().GetSprite()
            ->SetOverlayColor({ 255, 255, 255, static_cast<u8>(255 / (m_WebCleaning + 1)) });
    }
}
