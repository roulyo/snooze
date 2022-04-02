
    #include <forge/Project.h>
    #include "SpriteCatalog.h"
    #include "DataList.h"

    //----------------------------------------------------------------------------
    SpriteCatalog::SpriteCatalog()
    {

        RegisterData(DataList::Sprite::ForgeSprite, m_ForgeSpriteFactory);

        RegisterData(DataList::Sprite::AlarmNeutralSprite, m_AlarmNeutralSpriteFactory);

        RegisterData(DataList::Sprite::AlarmScrewSprite, m_AlarmScrewSpriteFactory);

        RegisterData(DataList::Sprite::AlarmButtonNeutralSprite, m_AlarmButtonNeutralSpriteFactory);

        RegisterData(DataList::Sprite::AlarmButtonPressedSprite, m_AlarmButtonPressedSpriteFactory);

    }

    //----------------------------------------------------------------------------
    SpriteCatalog::~SpriteCatalog()
    {
        m_Factories.clear();
    }
