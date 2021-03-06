
    #include <forge/Project.h>
    #include "DataList.h"

    namespace DataList
    {

    namespace Entity
    {

        constexpr forge::DataNameId Alarm = forge::DataNameId("Entity::Alarm");

        constexpr forge::DataNameId AlarmScrew = forge::DataNameId("Entity::AlarmScrew");

        constexpr forge::DataNameId AlarmButton = forge::DataNameId("Entity::AlarmButton");

        constexpr forge::DataNameId Screwdriver = forge::DataNameId("Entity::Screwdriver");

        constexpr forge::DataNameId CleaningBroom = forge::DataNameId("Entity::CleaningBroom");

        constexpr forge::DataNameId CleaningWeb = forge::DataNameId("Entity::CleaningWeb");

        constexpr forge::DataNameId CleaningFire = forge::DataNameId("Entity::CleaningFire");

        constexpr forge::DataNameId CleaningIce = forge::DataNameId("Entity::CleaningIce");

        constexpr forge::DataNameId CleaningSponge = forge::DataNameId("Entity::CleaningSponge");

        constexpr forge::DataNameId CleaningGoo = forge::DataNameId("Entity::CleaningGoo");

        constexpr forge::DataNameId LockKey = forge::DataNameId("Entity::LockKey");

        constexpr forge::DataNameId LockLock = forge::DataNameId("Entity::LockLock");

        constexpr forge::DataNameId LockMetalBox = forge::DataNameId("Entity::LockMetalBox");

        constexpr forge::DataNameId MouseAttackOpenAlarm = forge::DataNameId("Entity::MouseAttackOpenAlarm");

        constexpr forge::DataNameId MouseAttackSmoke = forge::DataNameId("Entity::MouseAttackSmoke");

        constexpr forge::DataNameId MouseAttackBbqMouse = forge::DataNameId("Entity::MouseAttackBbqMouse");

        constexpr forge::DataNameId MouseAttackWetMouse = forge::DataNameId("Entity::MouseAttackWetMouse");

        constexpr forge::DataNameId MouseAttackWaterGlass = forge::DataNameId("Entity::MouseAttackWaterGlass");

        constexpr forge::DataNameId VerminEnemy = forge::DataNameId("Entity::VerminEnemy");

        constexpr forge::DataNameId BatteryContainer = forge::DataNameId("Entity::BatteryContainer");

        constexpr forge::DataNameId BatteryMouse = forge::DataNameId("Entity::BatteryMouse");

        constexpr forge::DataNameId BatteryItem = forge::DataNameId("Entity::BatteryItem");

    }

    namespace Font
    {

        constexpr forge::DataNameId AlarmClock = forge::DataNameId("Font::AlarmClock");

        constexpr forge::DataNameId StoryFont = forge::DataNameId("Font::StoryFont");

    }

    namespace Music
    {

        constexpr forge::DataNameId Ambient = forge::DataNameId("Music::Ambient");

    }

    namespace SoundBuffer
    {

        constexpr forge::DataNameId Error = forge::DataNameId("SoundBuffer::Error");

        constexpr forge::DataNameId Speech = forge::DataNameId("SoundBuffer::Speech");

        constexpr forge::DataNameId SnoozePress = forge::DataNameId("SoundBuffer::SnoozePress");

        constexpr forge::DataNameId SnoozeRelease = forge::DataNameId("SoundBuffer::SnoozeRelease");

        constexpr forge::DataNameId Screw = forge::DataNameId("SoundBuffer::Screw");

        constexpr forge::DataNameId TakeObjectCommon = forge::DataNameId("SoundBuffer::TakeObjectCommon");

        constexpr forge::DataNameId CleanCommon = forge::DataNameId("SoundBuffer::CleanCommon");

        constexpr forge::DataNameId Key = forge::DataNameId("SoundBuffer::Key");

        constexpr forge::DataNameId Lock1 = forge::DataNameId("SoundBuffer::Lock1");

        constexpr forge::DataNameId Lock2 = forge::DataNameId("SoundBuffer::Lock2");

        constexpr forge::DataNameId Water1 = forge::DataNameId("SoundBuffer::Water1");

        constexpr forge::DataNameId Water2 = forge::DataNameId("SoundBuffer::Water2");

        constexpr forge::DataNameId BBQSplash = forge::DataNameId("SoundBuffer::BBQSplash");

        constexpr forge::DataNameId HitMouse = forge::DataNameId("SoundBuffer::HitMouse");

    }

    namespace Sound
    {

        constexpr forge::DataNameId Error = forge::DataNameId("Sound::Error");

        constexpr forge::DataNameId Speech = forge::DataNameId("Sound::Speech");

        constexpr forge::DataNameId Screw = forge::DataNameId("Sound::Screw");

        constexpr forge::DataNameId SnoozePress = forge::DataNameId("Sound::SnoozePress");

        constexpr forge::DataNameId SnoozeRelease = forge::DataNameId("Sound::SnoozeRelease");

        constexpr forge::DataNameId TakeObjectCommon = forge::DataNameId("Sound::TakeObjectCommon");

        constexpr forge::DataNameId CleanCommon = forge::DataNameId("Sound::CleanCommon");

        constexpr forge::DataNameId Key = forge::DataNameId("Sound::Key");

        constexpr forge::DataNameId Lock1 = forge::DataNameId("Sound::Lock1");

        constexpr forge::DataNameId Lock2 = forge::DataNameId("Sound::Lock2");

        constexpr forge::DataNameId Water1 = forge::DataNameId("Sound::Water1");

        constexpr forge::DataNameId Water2 = forge::DataNameId("Sound::Water2");

        constexpr forge::DataNameId BBQSplash = forge::DataNameId("Sound::BBQSplash");

        constexpr forge::DataNameId HitMouse = forge::DataNameId("Sound::HitMouse");

    }

    namespace Sprite
    {

        constexpr forge::DataNameId ForgeSprite = forge::DataNameId("Sprite::ForgeSprite");

        constexpr forge::DataNameId SoundOn = forge::DataNameId("Sprite::SoundOn");

        constexpr forge::DataNameId SoundOff = forge::DataNameId("Sprite::SoundOff");

        constexpr forge::DataNameId MusicOn = forge::DataNameId("Sprite::MusicOn");

        constexpr forge::DataNameId MusicOff = forge::DataNameId("Sprite::MusicOff");

        constexpr forge::DataNameId AlarmNeutralSprite = forge::DataNameId("Sprite::AlarmNeutralSprite");

        constexpr forge::DataNameId AlarmScrewSprite = forge::DataNameId("Sprite::AlarmScrewSprite");

        constexpr forge::DataNameId AlarmButtonNeutralSprite = forge::DataNameId("Sprite::AlarmButtonNeutralSprite");

        constexpr forge::DataNameId AlarmButtonPressedSprite = forge::DataNameId("Sprite::AlarmButtonPressedSprite");

        constexpr forge::DataNameId AlarmButtonPressedProblemSprite = forge::DataNameId("Sprite::AlarmButtonPressedProblemSprite");

        constexpr forge::DataNameId CleaningBroom = forge::DataNameId("Sprite::CleaningBroom");

        constexpr forge::DataNameId CleaningWeb = forge::DataNameId("Sprite::CleaningWeb");

        constexpr forge::DataNameId CleaningFire = forge::DataNameId("Sprite::CleaningFire");

        constexpr forge::DataNameId CleaningIce = forge::DataNameId("Sprite::CleaningIce");

        constexpr forge::DataNameId CleaningSponge = forge::DataNameId("Sprite::CleaningSponge");

        constexpr forge::DataNameId CleaningGoo = forge::DataNameId("Sprite::CleaningGoo");

        constexpr forge::DataNameId ScrewdriverSprite = forge::DataNameId("Sprite::ScrewdriverSprite");

        constexpr forge::DataNameId LockKeySprite = forge::DataNameId("Sprite::LockKeySprite");

        constexpr forge::DataNameId LockLockSprite = forge::DataNameId("Sprite::LockLockSprite");

        constexpr forge::DataNameId LockMetalBoxSprite = forge::DataNameId("Sprite::LockMetalBoxSprite");

        constexpr forge::DataNameId MouseAttackOpenAlarmSprite = forge::DataNameId("Sprite::MouseAttackOpenAlarmSprite");

        constexpr forge::DataNameId MouseAttackSmokeSprite = forge::DataNameId("Sprite::MouseAttackSmokeSprite");

        constexpr forge::DataNameId MouseAttackBbqMouseSprite = forge::DataNameId("Sprite::MouseAttackBbqMouseSprite");

        constexpr forge::DataNameId MouseAttackWetMouseSprite = forge::DataNameId("Sprite::MouseAttackWetMouseSprite");

        constexpr forge::DataNameId MouseAttackWaterGlassSprite = forge::DataNameId("Sprite::MouseAttackWaterGlassSprite");

        constexpr forge::DataNameId VerminEnemySprite = forge::DataNameId("Sprite::VerminEnemySprite");

        constexpr forge::DataNameId BatteryMissingOneSprite = forge::DataNameId("Sprite::BatteryMissingOneSprite");

        constexpr forge::DataNameId BatteryCompleteSprite = forge::DataNameId("Sprite::BatteryCompleteSprite");

        constexpr forge::DataNameId BatteryStealingMouseSprite = forge::DataNameId("Sprite::BatteryStealingMouseSprite");

        constexpr forge::DataNameId BatteryKOMouse = forge::DataNameId("Sprite::BatteryKOMouse");

        constexpr forge::DataNameId BatteryItemSprite = forge::DataNameId("Sprite::BatteryItemSprite");

    }

    namespace Texture
    {

        constexpr forge::DataNameId ForgeSheet = forge::DataNameId("Texture::ForgeSheet");

        constexpr forge::DataNameId AlarmSheet = forge::DataNameId("Texture::AlarmSheet");

        constexpr forge::DataNameId SampleSheet = forge::DataNameId("Texture::SampleSheet");

        constexpr forge::DataNameId ConfigSheet = forge::DataNameId("Texture::ConfigSheet");

    }

    }
