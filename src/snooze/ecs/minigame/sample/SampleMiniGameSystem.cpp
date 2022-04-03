#include <snooze/Precomp.h>
#include <snooze/ecs/minigame/sample/SampleMiniGameSystem.h>

#include <iostream>
#include <random>

#include <forge/engine/data/api/DataAPI.h>
#include <forge/engine/ecs/Entity.h>
#include <forge/engine/presentation/api/PresentationAPI.h>
#include <forge/engine/window/Cursor.h>

#include <snooze/data/DataList.h>
#include <snooze/data/EntityCatalog.h>

//----------------------------------------------------------------------------
SampleMiniGameSystem::SampleMiniGameSystem()
    : m_ToolAcquired(false)
    , m_Cleaning(0)
{
    m_Variants[0] = forge::Pair<forge::Entity::Ptr, forge::Entity::Ptr>(
        forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::CleaningIce),
        forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::CleaningFire)
    );
    m_Variants[1] = forge::Pair<forge::Entity::Ptr, forge::Entity::Ptr>(
        forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::CleaningWeb),
        forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::CleaningBroom)
    );
    m_Variants[2] = forge::Pair<forge::Entity::Ptr, forge::Entity::Ptr>(
        forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::CleaningGoo),
        forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::CleaningSponge)
    );
}

//----------------------------------------------------------------------------
void SampleMiniGameSystem::Execute(const u64& _dt, const forge::Entity::Ptr& _entity)
{
    SampleMiniGameComponent& comp = _entity->GetComponent<SampleMiniGameComponent>();

    BaseMiniGame::Update(comp);

    if (m_ToolAcquired && m_Tool != nullptr)
    {
        RequestRemoveEntity(m_Tool);
        m_Tool = nullptr;
    }

    if (m_Cleaning > 5)
    {
        RequestRemoveEntity(m_Problem);
        BaseMiniGame::CompleteGame(comp);

        m_Problem = nullptr;
    }
}

//----------------------------------------------------------------------------
void SampleMiniGameSystem::OnMiniGameStart()
{
    forge::builtin::EntityClickedEvent::Handlers +=
        forge::builtin::EntityClickedEvent::Handler(this, &SampleMiniGameSystem::OnEntityClickedEvent);

    static std::random_device rd;
    forge::Pair<forge::Entity::Ptr, forge::Entity::Ptr> pair = m_Variants[rd() % numberOfVariants];

    m_Problem = pair.first;
    //m_Problem->SetPosition(48, 42, 10);
    m_Problem->SetPosition(50.f - m_Problem->GetSize().w * 0.5f, 50.f - m_Problem->GetSize().d * 0.5f, 3.f);
    RequestAddEntity(m_Problem);

    m_Tool = pair.second;
    m_Tool->SetPosition(57, 57, 10);
    RequestAddEntity(m_Tool);
}

//----------------------------------------------------------------------------
void SampleMiniGameSystem::OnMiniGameStop()
{
    forge::builtin::EntityClickedEvent::Handlers -=
        forge::builtin::EntityClickedEvent::Handler(this, &SampleMiniGameSystem::OnEntityClickedEvent);

    // Resetting the alpha for future
    m_Problem->GetComponent<forge::builtin::RenderableComponent>().GetSprite()
            ->SetOverlayColor({ 255, 255, 255, 255 });

    // reset cursor
    forge::PresentationAPI::SetCursor(forge::Cursor::Arrow);

    m_ToolAcquired = false;
    m_Cleaning = 0;
}

//----------------------------------------------------------------------------
void SampleMiniGameSystem::OnEntityClickedEvent(const forge::builtin::EntityClickedEvent& _event)
{
    if (_event.GetIsPressed())
        return;

    if (_event.GetEntity() == m_Tool)
    {
        m_ToolAcquired = true;
    }
    else if (_event.GetEntity() == m_Problem && m_ToolAcquired)
    {
        ++m_Cleaning;

        m_Problem->GetComponent<forge::builtin::RenderableComponent>().GetSprite()
            ->SetOverlayColor({ 255, 255, 255, static_cast<u8>(255 / (m_Cleaning + 1)) });
    }
}
