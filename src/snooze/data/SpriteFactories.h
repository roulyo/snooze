
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
    class SampleBroomFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class SampleWebFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    }}}
