
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

    }}}
