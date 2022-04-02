
    #include <forge/Project.h>
    #include "SpriteCatalog.h"
    #include "DataList.h"

    //----------------------------------------------------------------------------
    SpriteCatalog::SpriteCatalog()
    {

        RegisterData(DataList::Sprite::ForgeSprite, m_ForgeSpriteFactory);

    }

    //----------------------------------------------------------------------------
    SpriteCatalog::~SpriteCatalog()
    {
        m_Factories.clear();
    }
