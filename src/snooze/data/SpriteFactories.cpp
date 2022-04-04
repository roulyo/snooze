
    #include <forge/Project.h>
    #include <forge/engine/data/api/DataAPI.h>
    
    #include "SpriteFactories.h"
    #include "DataList.h"

    
    #include "TextureCatalog.h"



    namespace forge { namespace generated { namespace SpriteFactories {

    //----------------------------------------------------------------------------
    forge::Sprite* ForgeSpriteFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::ForgeSprite);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::ForgeSheet));

        data->SetTextureQuad(0, 0, 512, 204);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* AlarmNeutralSpriteFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::AlarmNeutralSprite);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(0, 0, 600, 600);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* AlarmScrewSpriteFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::AlarmScrewSprite);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(600, 0, 600, 600);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* AlarmButtonNeutralSpriteFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::AlarmButtonNeutralSprite);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(1200, 0, 600, 600);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* AlarmButtonPressedSpriteFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::AlarmButtonPressedSprite);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(1800, 0, 600, 600);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* AlarmButtonPressedProblemSpriteFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::AlarmButtonPressedProblemSprite);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(2400, 0, 600, 600);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* CleaningBroomFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::CleaningBroom);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(1000, 1800, 200, 200);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* CleaningWebFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::CleaningWeb);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(600, 2400, 600, 600);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* CleaningFireFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::CleaningFire);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(600, 1800, 200, 200);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* CleaningIceFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::CleaningIce);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(0, 2400, 600, 600);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* CleaningSpongeFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::CleaningSponge);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(600, 2200, 200, 200);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* CleaningGooFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::CleaningGoo);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(1200, 2400, 600, 600);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* ScrewdriverSpriteFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::ScrewdriverSprite);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(1200, 1600, 200, 200);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* LockKeySpriteFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::LockKeySprite);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(1000, 2200, 200, 200);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* LockLockSpriteFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::LockLockSprite);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(1200, 1800, 600, 600);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* LockMetalBoxSpriteFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::LockMetalBoxSprite);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(0, 1800, 600, 600);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* MouseAttackOpenAlarmSpriteFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::MouseAttackOpenAlarmSprite);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(0, 600, 600, 600);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* MouseAttackSmokeSpriteFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::MouseAttackSmokeSprite);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(0, 1200, 600, 600);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* MouseAttackBbqMouseSpriteFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::MouseAttackBbqMouseSprite);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(600, 1200, 600, 600);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* MouseAttackWetMouseSpriteFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::MouseAttackWetMouseSprite);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(1800, 1200, 600, 600);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* MouseAttackWaterGlassSpriteFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::MouseAttackWaterGlassSprite);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(1200, 1200, 200, 200);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* VerminEnemySpriteFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::VerminEnemySprite);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(1600, 1200, 200, 200);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* BatteryMissingOneSpriteFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::BatteryMissingOneSprite);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(600, 600, 600, 600);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* BatteryCompleteSpriteFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::BatteryCompleteSprite);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(1200, 600, 600, 600);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* BatteryStealingMouseSpriteFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::BatteryStealingMouseSprite);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(1800, 600, 600, 600);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* BatteryKOMouseFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::BatteryKOMouse);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(2400, 600, 600, 600);

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sprite* BatteryItemSpriteFactory::Create() const
    {
        forge::Sprite* data = new forge::Sprite();
        data->SetDataNameId(DataList::Sprite::BatteryItemSprite);

        data->SetTexture(forge::DataAPI::GetDataFrom<TextureCatalog>(DataList::Texture::AlarmSheet));

        data->SetTextureQuad(1600, 1600, 200, 200);

        return data;
    }

    }}}
