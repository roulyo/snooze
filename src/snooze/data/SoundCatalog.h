
    #pragma once
    #include <forge/engine/data/DataCatalog.h>
    #include "SoundFactories.h"

    #include <forge/Project.h>

    #include <forge/engine/audio/playable/Sound.h>

    //----------------------------------------------------------------------------
    class SoundCatalog : public forge::DataCatalog<forge::Sound>
    {
        FRG__DECL_CATALOG(SoundCatalog);

    public:
        SoundCatalog();
        ~SoundCatalog();

    private:

        forge::generated::SoundFactories::ErrorFactory m_ErrorFactory;

        forge::generated::SoundFactories::ScrewFactory m_ScrewFactory;

        forge::generated::SoundFactories::SnoozePressFactory m_SnoozePressFactory;

        forge::generated::SoundFactories::SnoozeReleaseFactory m_SnoozeReleaseFactory;

        forge::generated::SoundFactories::TakeObjectCommonFactory m_TakeObjectCommonFactory;

        forge::generated::SoundFactories::CleanCommonFactory m_CleanCommonFactory;

        forge::generated::SoundFactories::KeyFactory m_KeyFactory;

        forge::generated::SoundFactories::Lock1Factory m_Lock1Factory;

        forge::generated::SoundFactories::Lock2Factory m_Lock2Factory;

        forge::generated::SoundFactories::Water1Factory m_Water1Factory;

        forge::generated::SoundFactories::Water2Factory m_Water2Factory;

        forge::generated::SoundFactories::BBQSplashFactory m_BBQSplashFactory;

        forge::generated::SoundFactories::HitMouseFactory m_HitMouseFactory;

    };
