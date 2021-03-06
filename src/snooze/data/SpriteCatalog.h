
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

        forge::generated::SpriteFactories::SoundOnFactory m_SoundOnFactory;

        forge::generated::SpriteFactories::SoundOffFactory m_SoundOffFactory;

        forge::generated::SpriteFactories::MusicOnFactory m_MusicOnFactory;

        forge::generated::SpriteFactories::MusicOffFactory m_MusicOffFactory;

        forge::generated::SpriteFactories::AlarmNeutralSpriteFactory m_AlarmNeutralSpriteFactory;

        forge::generated::SpriteFactories::AlarmScrewSpriteFactory m_AlarmScrewSpriteFactory;

        forge::generated::SpriteFactories::AlarmButtonNeutralSpriteFactory m_AlarmButtonNeutralSpriteFactory;

        forge::generated::SpriteFactories::AlarmButtonPressedSpriteFactory m_AlarmButtonPressedSpriteFactory;

        forge::generated::SpriteFactories::AlarmButtonPressedProblemSpriteFactory m_AlarmButtonPressedProblemSpriteFactory;

        forge::generated::SpriteFactories::CleaningBroomFactory m_CleaningBroomFactory;

        forge::generated::SpriteFactories::CleaningWebFactory m_CleaningWebFactory;

        forge::generated::SpriteFactories::CleaningFireFactory m_CleaningFireFactory;

        forge::generated::SpriteFactories::CleaningIceFactory m_CleaningIceFactory;

        forge::generated::SpriteFactories::CleaningSpongeFactory m_CleaningSpongeFactory;

        forge::generated::SpriteFactories::CleaningGooFactory m_CleaningGooFactory;

        forge::generated::SpriteFactories::ScrewdriverSpriteFactory m_ScrewdriverSpriteFactory;

        forge::generated::SpriteFactories::LockKeySpriteFactory m_LockKeySpriteFactory;

        forge::generated::SpriteFactories::LockLockSpriteFactory m_LockLockSpriteFactory;

        forge::generated::SpriteFactories::LockMetalBoxSpriteFactory m_LockMetalBoxSpriteFactory;

        forge::generated::SpriteFactories::MouseAttackOpenAlarmSpriteFactory m_MouseAttackOpenAlarmSpriteFactory;

        forge::generated::SpriteFactories::MouseAttackSmokeSpriteFactory m_MouseAttackSmokeSpriteFactory;

        forge::generated::SpriteFactories::MouseAttackBbqMouseSpriteFactory m_MouseAttackBbqMouseSpriteFactory;

        forge::generated::SpriteFactories::MouseAttackWetMouseSpriteFactory m_MouseAttackWetMouseSpriteFactory;

        forge::generated::SpriteFactories::MouseAttackWaterGlassSpriteFactory m_MouseAttackWaterGlassSpriteFactory;

        forge::generated::SpriteFactories::VerminEnemySpriteFactory m_VerminEnemySpriteFactory;

        forge::generated::SpriteFactories::BatteryMissingOneSpriteFactory m_BatteryMissingOneSpriteFactory;

        forge::generated::SpriteFactories::BatteryCompleteSpriteFactory m_BatteryCompleteSpriteFactory;

        forge::generated::SpriteFactories::BatteryStealingMouseSpriteFactory m_BatteryStealingMouseSpriteFactory;

        forge::generated::SpriteFactories::BatteryKOMouseFactory m_BatteryKOMouseFactory;

        forge::generated::SpriteFactories::BatteryItemSpriteFactory m_BatteryItemSpriteFactory;

    };
