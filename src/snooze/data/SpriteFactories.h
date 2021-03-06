
    #pragma once
    #include <forge/engine/data/DataFactory.h>

    #include <forge/Project.h>

    #include <forge/engine/rendering/drawable/Sprite.h>

    namespace forge { namespace generated { namespace SpriteFactories {

    //----------------------------------------------------------------------------
    class ForgeSpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class SoundOnFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class SoundOffFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class MusicOnFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class MusicOffFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class AlarmNeutralSpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class AlarmScrewSpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class AlarmButtonNeutralSpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class AlarmButtonPressedSpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class AlarmButtonPressedProblemSpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class CleaningBroomFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class CleaningWebFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class CleaningFireFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class CleaningIceFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class CleaningSpongeFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class CleaningGooFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class ScrewdriverSpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class LockKeySpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class LockLockSpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class LockMetalBoxSpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class MouseAttackOpenAlarmSpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class MouseAttackSmokeSpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class MouseAttackBbqMouseSpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class MouseAttackWetMouseSpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class MouseAttackWaterGlassSpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class VerminEnemySpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class BatteryMissingOneSpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class BatteryCompleteSpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class BatteryStealingMouseSpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class BatteryKOMouseFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class BatteryItemSpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    }}}
