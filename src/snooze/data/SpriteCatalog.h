
    #pragma once
    #include <forge/engine/data/DataCatalog.h>
    #include "SpriteFactories.h"

    #include <forge/Project.h>

    #include <forge/engine/rendering/drawable/Sprite.h>

    //----------------------------------------------------------------------------
    class SpriteCatalog : public forge::DataCatalog<forge::Sprite>
    {
        FRG__DECL_CATALOG(SpriteCatalog);

    public:
        SpriteCatalog();
        ~SpriteCatalog();

    private:

        forge::generated::SpriteFactories::ForgeSpriteFactory m_ForgeSpriteFactory;

        forge::generated::SpriteFactories::AlarmNeutralSpriteFactory m_AlarmNeutralSpriteFactory;

        forge::generated::SpriteFactories::AlarmScrewSpriteFactory m_AlarmScrewSpriteFactory;

        forge::generated::SpriteFactories::AlarmButtonNeutralSpriteFactory m_AlarmButtonNeutralSpriteFactory;

        forge::generated::SpriteFactories::AlarmButtonPressedSpriteFactory m_AlarmButtonPressedSpriteFactory;

        forge::generated::SpriteFactories::CleaningBroomFactory m_CleaningBroomFactory;

        forge::generated::SpriteFactories::CleaningWebFactory m_CleaningWebFactory;

        forge::generated::SpriteFactories::CleaningFireFactory m_CleaningFireFactory;

        forge::generated::SpriteFactories::CleaningIceFactory m_CleaningIceFactory;

        forge::generated::SpriteFactories::CleaningSpongeFactory m_CleaningSpongeFactory;

        forge::generated::SpriteFactories::CleaningGooFactory m_CleaningGooFactory;

        forge::generated::SpriteFactories::LockKeySpriteFactory m_LockKeySpriteFactory;

        forge::generated::SpriteFactories::LockLockSpriteFactory m_LockLockSpriteFactory;

        forge::generated::SpriteFactories::LockChainFrontSpriteFactory m_LockChainFrontSpriteFactory;

        forge::generated::SpriteFactories::LockChainBackSpriteFactory m_LockChainBackSpriteFactory;

        forge::generated::SpriteFactories::MouseAttackOpenAlarmSpriteFactory m_MouseAttackOpenAlarmSpriteFactory;

        forge::generated::SpriteFactories::MouseAttackSmokeSpriteFactory m_MouseAttackSmokeSpriteFactory;

        forge::generated::SpriteFactories::MouseAttackBbqMouseSpriteFactory m_MouseAttackBbqMouseSpriteFactory;

        forge::generated::SpriteFactories::MouseAttackWetMouseSpriteFactory m_MouseAttackWetMouseSpriteFactory;

        forge::generated::SpriteFactories::MouseAttackWaterGlassSpriteFactory m_MouseAttackWaterGlassSpriteFactory;

        forge::generated::SpriteFactories::VerminEnemySpriteFactory m_VerminEnemySpriteFactory;

    };
