
    #include <forge/Project.h>
    #include <forge/engine/data/api/DataAPI.h>
    
    #include "EntityFactories.h"
    #include "DataList.h"

    //extra_includes

    namespace forge { namespace generated { namespace EntityFactories {

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
auto& hoverComp = data->AddComponent<HoverableComponent>();
hoverComp.SetCursorType(CursorType::Cross);
auto& soundComp = data->AddComponent<SoundClickableComponent>();
soundComp.SetOnPressSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::Screw));
soundComp.SetOnReleaseSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::Screw));

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
auto& hoverComp = data->AddComponent<HoverableComponent>();
hoverComp.SetCursorType(CursorType::Hand);
auto& soundComp = data->AddComponent<SoundClickableComponent>();
soundComp.SetOnPressSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::SnoozePress));
soundComp.SetOnReleaseSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::SnoozeRelease));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* ScrewdriverFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::Screwdriver);

        data->SetSize(6.5, 6.5, 0);
data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::ScrewdriverSprite));
auto& hoverComp = data->AddComponent<HoverableComponent>();
hoverComp.SetCursorType(CursorType::Hand);
auto& soundComp = data->AddComponent<SoundClickableComponent>();
soundComp.SetOnReleaseSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::TakeObjectCommon));

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
auto& hoverComp = data->AddComponent<HoverableComponent>();
hoverComp.SetCursorType(CursorType::Hand);
auto& soundComp = data->AddComponent<SoundClickableComponent>();
soundComp.SetOnReleaseSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::TakeObjectCommon));

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
auto& hoverComp = data->AddComponent<HoverableComponent>();
hoverComp.SetCursorType(CursorType::Cross);
auto& soundComp = data->AddComponent<SoundClickableComponent>();
soundComp.SetOnReleaseSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::CleanCommon));

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
auto& hoverComp = data->AddComponent<HoverableComponent>();
hoverComp.SetCursorType(CursorType::Hand);
auto& soundComp = data->AddComponent<SoundClickableComponent>();
soundComp.SetOnReleaseSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::TakeObjectCommon));

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
auto& hoverComp = data->AddComponent<HoverableComponent>();
hoverComp.SetCursorType(CursorType::Cross);
auto& soundComp = data->AddComponent<SoundClickableComponent>();
soundComp.SetOnReleaseSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::CleanCommon));

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
auto& hoverComp = data->AddComponent<HoverableComponent>();
hoverComp.SetCursorType(CursorType::Hand);
auto& soundComp = data->AddComponent<SoundClickableComponent>();
soundComp.SetOnReleaseSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::TakeObjectCommon));

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
auto& hoverComp = data->AddComponent<HoverableComponent>();
hoverComp.SetCursorType(CursorType::Cross);
auto& soundComp = data->AddComponent<SoundClickableComponent>();
soundComp.SetOnReleaseSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::CleanCommon));

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
auto& hoverComp = data->AddComponent<HoverableComponent>();
hoverComp.SetCursorType(CursorType::Hand);
auto& soundComp = data->AddComponent<SoundClickableComponent>();
soundComp.SetOnReleaseSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::Key));

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
auto& hoverComp = data->AddComponent<HoverableComponent>();
hoverComp.SetCursorType(CursorType::Cross);
auto& soundComp = data->AddComponent<SoundClickableComponent>();
soundComp.SetOnPressSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::Lock1));
soundComp.SetOnReleaseSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::Lock2));

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
//data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::MouseAttackOpenAlarmSprite));
//auto& soundComp = data->AddComponent<SoundClickableComponent>();
//soundComp.SetOnPressSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::Error));
//soundComp.SetOnReleaseSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::Error));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* MouseAttackSmokeFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::MouseAttackSmoke);

        data->SetSize(20, 20, 0);
//data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::MouseAttackSmokeSprite));
//auto& soundComp = data->AddComponent<SoundClickableComponent>();
//soundComp.SetOnPressSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::Error));
//soundComp.SetOnReleaseSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::Error));

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
auto& hoverComp = data->AddComponent<HoverableComponent>();
hoverComp.SetCursorType(CursorType::Cross);
auto& soundComp = data->AddComponent<SoundClickableComponent>();
soundComp.SetOnReleaseSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::BBQSplash));

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
auto& hoverComp = data->AddComponent<HoverableComponent>();
hoverComp.SetCursorType(CursorType::Cross);
//auto& soundComp = data->AddComponent<SoundClickableComponent>();
//soundComp.SetOnPressSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::Error));
//soundComp.SetOnReleaseSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::Error));

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
auto& hoverComp = data->AddComponent<HoverableComponent>();
hoverComp.SetCursorType(CursorType::Hand);
auto& soundComp = data->AddComponent<SoundClickableComponent>();
soundComp.SetOnPressSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::Water1));
soundComp.SetOnReleaseSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::Water2));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* VerminEnemyFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::VerminEnemy);

        data->SetSize(6.5, 6.5, 0);
data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::VerminEnemySprite));
auto& hoverComp = data->AddComponent<HoverableComponent>();
hoverComp.SetCursorType(CursorType::Cross);
auto& soundComp = data->AddComponent<SoundClickableComponent>();
soundComp.SetOnReleaseSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::HitMouse));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* BatteryContainerFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::BatteryContainer);

        data->SetSize(20, 20, 0);
data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::BatteryMissingOneSprite));
auto& hoverComp = data->AddComponent<HoverableComponent>();
hoverComp.SetCursorType(CursorType::Cross);
auto& soundComp = data->AddComponent<SoundClickableComponent>();
soundComp.SetOnPressSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::Water1));
soundComp.SetOnReleaseSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::Water2));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* BatteryMouseFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::BatteryMouse);

        data->SetSize(20, 20, 0);
data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::BatteryStealingMouseSprite));
auto& hoverComp = data->AddComponent<HoverableComponent>();
hoverComp.SetCursorType(CursorType::Cross);
auto& soundComp = data->AddComponent<SoundClickableComponent>();
soundComp.SetOnPressSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::HitMouse));
soundComp.SetOnReleaseSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::HitMouse));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Entity* BatteryItemFactory::Create() const
    {
        forge::Entity* data = new forge::Entity();
        data->SetDataNameId(DataList::Entity::BatteryItem);

        data->SetSize(6.5, 6.5, 0);
data->AddComponent<forge::builtin::ScreenMappableComponent>();
auto& renderComp = data->AddComponent<forge::builtin::RenderableComponent>();
renderComp.SetSprite(forge::DataAPI::GetDataFrom<SpriteCatalog>(DataList::Sprite::BatteryItemSprite));
auto& hoverComp = data->AddComponent<HoverableComponent>();
hoverComp.SetCursorType(CursorType::Hand);
auto& soundComp = data->AddComponent<SoundClickableComponent>();
soundComp.SetOnPressSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::HitMouse));
soundComp.SetOnReleaseSound(forge::DataAPI::GetDataFrom<SoundCatalog>(DataList::Sound::HitMouse));
        return data;
    }

    }}}
