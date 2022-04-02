#include <snooze/Precomp.h>
#include <snooze/Snooze.h>

#include <forge/engine/camera/api/CameraAPI.h>
#include <forge/engine/data/api/DataAPI.h>

#include <forge/builtin/freeroaming/SimpleGameState.h>

#include <snooze/data/DataList.h>
#include <snooze/data/EntityCatalog.h>
#include <snooze/data/SpriteCatalog.h>
#include <snooze/data/TextureCatalog.h>

//----------------------------------------------------------------------------
Snooze::Snooze()
{
}

//----------------------------------------------------------------------------
Snooze::~Snooze()
{
}

//----------------------------------------------------------------------------
void Snooze::OnInit()
{
    RegisterCatalogType<EntityCatalog>();
    RegisterCatalogType<SpriteCatalog>();
    RegisterCatalogType<TextureCatalog>();

    m_World.Init(100.f, 100.f);

    forge::Entity::Ptr mc = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::PlayableCharacter);
    mc->SetPosition(50.f - mc->GetSize().w * 0.5f, 50.f - mc->GetSize().d * 0.5f, 0.f);
    m_World.AddEntity(mc);

    forge::CameraAPI::SetLookAt({ 50.f, 50.f, 0.f });
    forge::CameraAPI::SetDistance(10);
    forge::CameraAPI::SetFieldOfView(90);
    forge::CameraAPI::SetFilmedWorld(GetWorld());

    RegisterGameState<forge::builtin::SimpleGameState>();
    RequestState(forge::builtin::SimpleGameState::Id);
}

//----------------------------------------------------------------------------
void Snooze::OnQuit()
{
}
