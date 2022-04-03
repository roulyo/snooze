
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
    class LockChainFrontSpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class LockChainBackSpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    }}}
