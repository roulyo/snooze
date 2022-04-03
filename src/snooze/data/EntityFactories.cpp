
    #include <forge/Project.h>
    #include <forge/engine/data/api/DataAPI.h>
    
    #include "EntityFactories.h"
    #include "DataList.h"

    //extra_includes

    namespace forge { namespace generated { namespace EntityFactories {

    //----------------------------------------------------------------------------
    forge::Entity* SnoozeButtonFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::SnoozeButton);

        data->SetSize(5.12, 2.04, 0);
data->AddComponent<SnoozableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::ForgeSprite));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* AlarmFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::Alarm);

        data->SetSize(20, 20, 0);
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::AlarmNeutralSprite));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* AlarmScrewFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::AlarmScrew);

        data->SetSize(20, 20, 0);
data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::AlarmScrewSprite));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* AlarmButtonFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::AlarmButton);

        data->SetSize(20, 20, 0);
data->AddComponent<SnoozableComponent>();
data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::AlarmButtonNeutralSprite));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* CleaningBroomFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::CleaningBroom);

        data->SetSize(3, 3, 0);
data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::CleaningBroom));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* CleaningWebFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::CleaningWeb);

        data->SetSize(20, 20, 0);
data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::CleaningWeb));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* CleaningFireFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::CleaningFire);

        data->SetSize(3, 3, 0);
data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::CleaningFire));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* CleaningIceFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::CleaningIce);

        data->SetSize(20, 20, 0);
data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::CleaningIce));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* CleaningSpongeFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::CleaningSponge);

        data->SetSize(3, 3, 0);
data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::CleaningSponge));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* CleaningGooFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::CleaningGoo);

        data->SetSize(20, 20, 0);
data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::CleaningGoo));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* LockKeyFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::LockKey);

        data->SetSize(5, 5, 0);
data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::LockKeySprite));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* LockLockFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::LockLock);

        data->SetSize(20, 20, 0);
data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::LockLockSprite));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* LockChainBackFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::LockChainBack);

        data->SetSize(20, 20, 0);
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::LockChainBackSprite));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* LockChainFrontFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::LockChainFront);

        data->SetSize(20, 20, 0);
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::LockChainFrontSprite));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* MouseAttackOpenAlarmFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::MouseAttackOpenAlarm);

        data->SetSize(20, 20, 0);
data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::MouseAttackOpenAlarmSprite));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* MouseAttackSmokeFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::MouseAttackSmoke);

        data->SetSize(20, 20, 0);
data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::MouseAttackSmokeSprite));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* MouseAttackBbqMouseFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::MouseAttackBbqMouse);

        data->SetSize(20, 20, 0);
data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::MouseAttackBbqMouseSprite));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* MouseAttackWetMouseFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::MouseAttackWetMouse);

        data->SetSize(20, 20, 0);
data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::MouseAttackWetMouseSprite));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* MouseAttackWaterGlassFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::MouseAttackWaterGlass);

        data->SetSize(5, 5, 0);
data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::MouseAttackWaterGlassSprite));
        return data;
    }

    }}}
