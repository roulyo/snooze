#include <snooze/Precomp.h>
#include <snooze/Snooze.h>

#include <forge/engine/camera/api/CameraAPI.h>
#include <forge/engine/data/api/DataAPI.h>

#include <snooze/data/DataList.h>
#include <snooze/data/EntityCatalog.h>
#include <snooze/data/SpriteCatalog.h>
#include <snooze/data/TextureCatalog.h>

#include <snooze/gamestate/BaseGameState.h>

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

    forge::Entity::Ptr alarm = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::Alarm);
    alarm->SetPosition(50.f - alarm->GetSize().w * 0.5f, 50.f - alarm->GetSize().d * 0.5f, 0.f);
    m_World.AddEntity(alarm);

    forge::Entity::Ptr screw = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::AlarmScrew);
    screw->SetPosition(50.f - screw->GetSize().w * 0.5f, 50.f - screw->GetSize().d * 0.5f, 0.f);
    m_World.AddEntity(screw);

    forge::Entity::Ptr button = forge::DataAPI::GetDataFrom<EntityCatalog>(DataList::Entity::AlarmButtonNeutral);
    button->SetPosition(50.f - button->GetSize().w * 0.5f, 50.f - button->GetSize().d * 0.5f, 0.f);
    m_World.AddEntity(button);

    forge::CameraAPI::SetLookAt({50.f, 50.f, 0.f});
    forge::CameraAPI::SetDistance(10);
    forge::CameraAPI::SetFieldOfView(90);
    forge::CameraAPI::SetFilmedWorld(GetWorld());

    RegisterGameState<BaseGameState>();
    RequestState(BaseGameState::Id);
}

//----------------------------------------------------------------------------
void Snooze::OnQuit()
{
}
