
    #include <forge/Project.h>
    #include "SoundCatalog.h"
    #include "DataList.h"

    //----------------------------------------------------------------------------
    SoundCatalog::SoundCatalog()
    {

        RegisterData(DataList::Sound::Error, m_ErrorFactory);

        RegisterData(DataList::Sound::Speech, m_SpeechFactory);

        RegisterData(DataList::Sound::Screw, m_ScrewFactory);

        RegisterData(DataList::Sound::SnoozePress, m_SnoozePressFactory);

        RegisterData(DataList::Sound::SnoozeRelease, m_SnoozeReleaseFactory);

        RegisterData(DataList::Sound::TakeObjectCommon, m_TakeObjectCommonFactory);

        RegisterData(DataList::Sound::CleanCommon, m_CleanCommonFactory);

        RegisterData(DataList::Sound::Key, m_KeyFactory);

        RegisterData(DataList::Sound::Lock1, m_Lock1Factory);

        RegisterData(DataList::Sound::Lock2, m_Lock2Factory);

        RegisterData(DataList::Sound::Water1, m_Water1Factory);

        RegisterData(DataList::Sound::Water2, m_Water2Factory);

        RegisterData(DataList::Sound::BBQSplash, m_BBQSplashFactory);

        RegisterData(DataList::Sound::HitMouse, m_HitMouseFactory);

    }

    //----------------------------------------------------------------------------
    SoundCatalog::~SoundCatalog()
    {
        m_Factories.clear();
    }
