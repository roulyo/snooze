
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

        RegisterData(DataList::Sprite::CleaningBroom, m_CleaningBroomFactory);

        RegisterData(DataList::Sprite::CleaningWeb, m_CleaningWebFactory);

        RegisterData(DataList::Sprite::CleaningFire, m_CleaningFireFactory);

        RegisterData(DataList::Sprite::CleaningIce, m_CleaningIceFactory);

        RegisterData(DataList::Sprite::CleaningSponge, m_CleaningSpongeFactory);

        RegisterData(DataList::Sprite::CleaningGoo, m_CleaningGooFactory);

        RegisterData(DataList::Sprite::LockKeySprite, m_LockKeySpriteFactory);

        RegisterData(DataList::Sprite::LockLockSprite, m_LockLockSpriteFactory);

        RegisterData(DataList::Sprite::LockChainFrontSprite, m_LockChainFrontSpriteFactory);

        RegisterData(DataList::Sprite::LockChainBackSprite, m_LockChainBackSpriteFactory);

        RegisterData(DataList::Sprite::MouseAttackOpenAlarmSprite, m_MouseAttackOpenAlarmSpriteFactory);

        RegisterData(DataList::Sprite::MouseAttackSmokeSprite, m_MouseAttackSmokeSpriteFactory);

        RegisterData(DataList::Sprite::MouseAttackBbqMouseSprite, m_MouseAttackBbqMouseSpriteFactory);

        RegisterData(DataList::Sprite::MouseAttackWetMouseSprite, m_MouseAttackWetMouseSpriteFactory);

        RegisterData(DataList::Sprite::MouseAttackWaterGlassSprite, m_MouseAttackWaterGlassSpriteFactory);

        RegisterData(DataList::Sprite::VerminEnemySprite, m_VerminEnemySpriteFactory);

    }

    //----------------------------------------------------------------------------
    SpriteCatalog::~SpriteCatalog()
    {
        m_Factories.clear();
    }
