
    #pragma once
    #include <forge/engine/data/DataCatalog.h>
    #include "SoundBufferFactories.h"

    #include <forge/Project.h>

    #include <forge/engine/audio/resource/SoundBuffer.h>

    //----------------------------------------------------------------------------
    class SoundBufferCatalog : public forge::DataCatalog<forge::SoundBuffer>
    {
        FRG__DECL_CATALOG(SoundBufferCatalog);

    public:
        SoundBufferCatalog();
        ~SoundBufferCatalog();

    private:

        forge::generated::SoundBufferFactories::ErrorFactory m_ErrorFactory;

        forge::generated::SoundBufferFactories::SnoozePressFactory m_SnoozePressFactory;

        forge::generated::SoundBufferFactories::SnoozeReleaseFactory m_SnoozeReleaseFactory;

        forge::generated::SoundBufferFactories::ScrewFactory m_ScrewFactory;

        forge::generated::SoundBufferFactories::TakeObjectCommonFactory m_TakeObjectCommonFactory;

        forge::generated::SoundBufferFactories::CleanCommonFactory m_CleanCommonFactory;

        forge::generated::SoundBufferFactories::KeyFactory m_KeyFactory;

        forge::generated::SoundBufferFactories::Lock1Factory m_Lock1Factory;

        forge::generated::SoundBufferFactories::Lock2Factory m_Lock2Factory;

        forge::generated::SoundBufferFactories::Water1Factory m_Water1Factory;

        forge::generated::SoundBufferFactories::Water2Factory m_Water2Factory;

        forge::generated::SoundBufferFactories::BBQSplashFactory m_BBQSplashFactory;

        forge::generated::SoundBufferFactories::HitMouseFactory m_HitMouseFactory;

    };
