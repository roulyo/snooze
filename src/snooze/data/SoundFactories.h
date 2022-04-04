
    #pragma once
    #include <forge/engine/data/DataFactory.h>

    #include <forge/Project.h>

    #include <forge/engine/audio/playable/Sound.h>

    namespace forge { namespace generated { namespace SoundFactories {

    //----------------------------------------------------------------------------
    class ErrorFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sound* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class ScrewFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sound* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class SnoozePressFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sound* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class SnoozeReleaseFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sound* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class TakeObjectCommonFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sound* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class CleanCommonFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sound* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class KeyFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sound* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class Lock1Factory : public forge::AbstractDataFactory
    {
    public:
        forge::Sound* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class Lock2Factory : public forge::AbstractDataFactory
    {
    public:
        forge::Sound* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class Water1Factory : public forge::AbstractDataFactory
    {
    public:
        forge::Sound* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class Water2Factory : public forge::AbstractDataFactory
    {
    public:
        forge::Sound* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class BBQSplashFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sound* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class HitMouseFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sound* Create() const override;

    };    

    }}}
