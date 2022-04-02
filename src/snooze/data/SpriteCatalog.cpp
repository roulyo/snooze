
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

        RegisterData(DataList::Sprite::SampleBroom, m_SampleBroomFactory);

        RegisterData(DataList::Sprite::SampleWeb, m_SampleWebFactory);

        RegisterData(DataList::Sprite::LockKeySprite, m_LockKeySpriteFactory);

        RegisterData(DataList::Sprite::LockLockSprite, m_LockLockSpriteFactory);

        RegisterData(DataList::Sprite::LockChainFrontSprite, m_LockChainFrontSpriteFactory);

        RegisterData(DataList::Sprite::LockChainBackSprite, m_LockChainBackSpriteFactory);

    }

    //----------------------------------------------------------------------------
    SpriteCatalog::~SpriteCatalog()
    {
        m_Factories.clear();
    }
