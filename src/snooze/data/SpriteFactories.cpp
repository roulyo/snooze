
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

    }}}
