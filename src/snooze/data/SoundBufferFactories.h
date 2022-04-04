
    #pragma once
    #include <forge/engine/data/DataFactory.h>

    #include <forge/Project.h>

    #include <forge/engine/audio/resource/SoundBuffer.h>

    namespace forge { namespace generated { namespace SoundBufferFactories {

    //----------------------------------------------------------------------------
    class ErrorFactory : public forge::AbstractDataFactory
    {
    public:
        forge::SoundBuffer* Create() const override;

    private:
        static forge::SoundBuffer* m_Data;

    };

    //----------------------------------------------------------------------------
    class SpeechFactory : public forge::AbstractDataFactory
    {
    public:
        forge::SoundBuffer* Create() const override;

    private:
        static forge::SoundBuffer* m_Data;

    };

    //----------------------------------------------------------------------------
    class SnoozePressFactory : public forge::AbstractDataFactory
    {
    public:
        forge::SoundBuffer* Create() const override;

    private:
        static forge::SoundBuffer* m_Data;

    };

    //----------------------------------------------------------------------------
    class SnoozeReleaseFactory : public forge::AbstractDataFactory
    {
    public:
        forge::SoundBuffer* Create() const override;

    private:
        static forge::SoundBuffer* m_Data;

    };

    //----------------------------------------------------------------------------
    class ScrewFactory : public forge::AbstractDataFactory
    {
    public:
        forge::SoundBuffer* Create() const override;

    private:
        static forge::SoundBuffer* m_Data;

    };

    //----------------------------------------------------------------------------
    class TakeObjectCommonFactory : public forge::AbstractDataFactory
    {
    public:
        forge::SoundBuffer* Create() const override;

    private:
        static forge::SoundBuffer* m_Data;

    };

    //----------------------------------------------------------------------------
    class CleanCommonFactory : public forge::AbstractDataFactory
    {
    public:
        forge::SoundBuffer* Create() const override;

    private:
        static forge::SoundBuffer* m_Data;

    };

    //----------------------------------------------------------------------------
    class KeyFactory : public forge::AbstractDataFactory
    {
    public:
        forge::SoundBuffer* Create() const override;

    private:
        static forge::SoundBuffer* m_Data;

    };

    //----------------------------------------------------------------------------
    class Lock1Factory : public forge::AbstractDataFactory
    {
    public:
        forge::SoundBuffer* Create() const override;

    private:
        static forge::SoundBuffer* m_Data;

    };

    //----------------------------------------------------------------------------
    class Lock2Factory : public forge::AbstractDataFactory
    {
    public:
        forge::SoundBuffer* Create() const override;

    private:
        static forge::SoundBuffer* m_Data;

    };

    //----------------------------------------------------------------------------
    class Water1Factory : public forge::AbstractDataFactory
    {
    public:
        forge::SoundBuffer* Create() const override;

    private:
        static forge::SoundBuffer* m_Data;

    };

    //----------------------------------------------------------------------------
    class Water2Factory : public forge::AbstractDataFactory
    {
    public:
        forge::SoundBuffer* Create() const override;

    private:
        static forge::SoundBuffer* m_Data;

    };

    //----------------------------------------------------------------------------
    class BBQSplashFactory : public forge::AbstractDataFactory
    {
    public:
        forge::SoundBuffer* Create() const override;

    private:
        static forge::SoundBuffer* m_Data;

    };

    //----------------------------------------------------------------------------
    class HitMouseFactory : public forge::AbstractDataFactory
    {
    public:
        forge::SoundBuffer* Create() const override;

    private:
        static forge::SoundBuffer* m_Data;

    };

    }}}
