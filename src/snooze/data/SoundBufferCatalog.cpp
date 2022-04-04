
    #include <forge/Project.h>
    #include "SoundBufferCatalog.h"
    #include "DataList.h"

    //----------------------------------------------------------------------------
    SoundBufferCatalog::SoundBufferCatalog()
    {

        RegisterData(DataList::SoundBuffer::Error, m_ErrorFactory);

        RegisterData(DataList::SoundBuffer::SnoozePress, m_SnoozePressFactory);

        RegisterData(DataList::SoundBuffer::SnoozeRelease, m_SnoozeReleaseFactory);

        RegisterData(DataList::SoundBuffer::Screw, m_ScrewFactory);

        RegisterData(DataList::SoundBuffer::TakeObjectCommon, m_TakeObjectCommonFactory);

        RegisterData(DataList::SoundBuffer::CleanCommon, m_CleanCommonFactory);

        RegisterData(DataList::SoundBuffer::Key, m_KeyFactory);

        RegisterData(DataList::SoundBuffer::Lock1, m_Lock1Factory);

        RegisterData(DataList::SoundBuffer::Lock2, m_Lock2Factory);

        RegisterData(DataList::SoundBuffer::Water1, m_Water1Factory);

        RegisterData(DataList::SoundBuffer::Water2, m_Water2Factory);

        RegisterData(DataList::SoundBuffer::BBQSplash, m_BBQSplashFactory);

        RegisterData(DataList::SoundBuffer::HitMouse, m_HitMouseFactory);

    }

    //----------------------------------------------------------------------------
    SoundBufferCatalog::~SoundBufferCatalog()
    {
        m_Factories.clear();
    }
