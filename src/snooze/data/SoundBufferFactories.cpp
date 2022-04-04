
    #include <forge/Project.h>
    #include <forge/engine/data/api/DataAPI.h>
    
    #include "SoundBufferFactories.h"
    #include "DataList.h"

    //extra_includes

    namespace forge { namespace generated { namespace SoundBufferFactories {

    //----------------------------------------------------------------------------
    forge::SoundBuffer* ErrorFactory::m_Data = nullptr;

    //----------------------------------------------------------------------------
    forge::SoundBuffer* ErrorFactory::Create() const
    {
    if (m_Data == nullptr)
    {
        forge::SoundBuffer* data = new forge::SoundBuffer();
        m_Data = data;
        data->SetInstanceAddr(&m_Data);
        data->SetDataNameId(DataList::SoundBuffer::Error);

        data->SetFile("assets/error.wav");

    }

        return m_Data;
    }

    //----------------------------------------------------------------------------
    forge::SoundBuffer* SnoozePressFactory::m_Data = nullptr;

    //----------------------------------------------------------------------------
    forge::SoundBuffer* SnoozePressFactory::Create() const
    {
    if (m_Data == nullptr)
    {
        forge::SoundBuffer* data = new forge::SoundBuffer();
        m_Data = data;
        data->SetInstanceAddr(&m_Data);
        data->SetDataNameId(DataList::SoundBuffer::SnoozePress);

        data->SetFile("assets/snooze_press.wav");

    }

        return m_Data;
    }

    //----------------------------------------------------------------------------
    forge::SoundBuffer* SnoozeReleaseFactory::m_Data = nullptr;

    //----------------------------------------------------------------------------
    forge::SoundBuffer* SnoozeReleaseFactory::Create() const
    {
    if (m_Data == nullptr)
    {
        forge::SoundBuffer* data = new forge::SoundBuffer();
        m_Data = data;
        data->SetInstanceAddr(&m_Data);
        data->SetDataNameId(DataList::SoundBuffer::SnoozeRelease);

        data->SetFile("assets/snooze_release.wav");

    }

        return m_Data;
    }

    //----------------------------------------------------------------------------
    forge::SoundBuffer* ScrewFactory::m_Data = nullptr;

    //----------------------------------------------------------------------------
    forge::SoundBuffer* ScrewFactory::Create() const
    {
    if (m_Data == nullptr)
    {
        forge::SoundBuffer* data = new forge::SoundBuffer();
        m_Data = data;
        data->SetInstanceAddr(&m_Data);
        data->SetDataNameId(DataList::SoundBuffer::Screw);

        data->SetFile("assets/screw.wav");

    }

        return m_Data;
    }

    //----------------------------------------------------------------------------
    forge::SoundBuffer* TakeObjectCommonFactory::m_Data = nullptr;

    //----------------------------------------------------------------------------
    forge::SoundBuffer* TakeObjectCommonFactory::Create() const
    {
    if (m_Data == nullptr)
    {
        forge::SoundBuffer* data = new forge::SoundBuffer();
        m_Data = data;
        data->SetInstanceAddr(&m_Data);
        data->SetDataNameId(DataList::SoundBuffer::TakeObjectCommon);

        data->SetFile("assets/take_object_common.wav");

    }

        return m_Data;
    }

    //----------------------------------------------------------------------------
    forge::SoundBuffer* CleanCommonFactory::m_Data = nullptr;

    //----------------------------------------------------------------------------
    forge::SoundBuffer* CleanCommonFactory::Create() const
    {
    if (m_Data == nullptr)
    {
        forge::SoundBuffer* data = new forge::SoundBuffer();
        m_Data = data;
        data->SetInstanceAddr(&m_Data);
        data->SetDataNameId(DataList::SoundBuffer::CleanCommon);

        data->SetFile("assets/clean_common.wav");

    }

        return m_Data;
    }

    //----------------------------------------------------------------------------
    forge::SoundBuffer* KeyFactory::m_Data = nullptr;

    //----------------------------------------------------------------------------
    forge::SoundBuffer* KeyFactory::Create() const
    {
    if (m_Data == nullptr)
    {
        forge::SoundBuffer* data = new forge::SoundBuffer();
        m_Data = data;
        data->SetInstanceAddr(&m_Data);
        data->SetDataNameId(DataList::SoundBuffer::Key);

        data->SetFile("assets/key.wav");

    }

        return m_Data;
    }

    //----------------------------------------------------------------------------
    forge::SoundBuffer* Lock1Factory::m_Data = nullptr;

    //----------------------------------------------------------------------------
    forge::SoundBuffer* Lock1Factory::Create() const
    {
    if (m_Data == nullptr)
    {
        forge::SoundBuffer* data = new forge::SoundBuffer();
        m_Data = data;
        data->SetInstanceAddr(&m_Data);
        data->SetDataNameId(DataList::SoundBuffer::Lock1);

        data->SetFile("assets/lock1.wav");

    }

        return m_Data;
    }

    //----------------------------------------------------------------------------
    forge::SoundBuffer* Lock2Factory::m_Data = nullptr;

    //----------------------------------------------------------------------------
    forge::SoundBuffer* Lock2Factory::Create() const
    {
    if (m_Data == nullptr)
    {
        forge::SoundBuffer* data = new forge::SoundBuffer();
        m_Data = data;
        data->SetInstanceAddr(&m_Data);
        data->SetDataNameId(DataList::SoundBuffer::Lock2);

        data->SetFile("assets/lock2.wav");

    }

        return m_Data;
    }

    //----------------------------------------------------------------------------
    forge::SoundBuffer* Water1Factory::m_Data = nullptr;

    //----------------------------------------------------------------------------
    forge::SoundBuffer* Water1Factory::Create() const
    {
    if (m_Data == nullptr)
    {
        forge::SoundBuffer* data = new forge::SoundBuffer();
        m_Data = data;
        data->SetInstanceAddr(&m_Data);
        data->SetDataNameId(DataList::SoundBuffer::Water1);

        data->SetFile("assets/water1.wav");

    }

        return m_Data;
    }

    //----------------------------------------------------------------------------
    forge::SoundBuffer* Water2Factory::m_Data = nullptr;

    //----------------------------------------------------------------------------
    forge::SoundBuffer* Water2Factory::Create() const
    {
    if (m_Data == nullptr)
    {
        forge::SoundBuffer* data = new forge::SoundBuffer();
        m_Data = data;
        data->SetInstanceAddr(&m_Data);
        data->SetDataNameId(DataList::SoundBuffer::Water2);

        data->SetFile("assets/water2.wav");

    }

        return m_Data;
    }

    //----------------------------------------------------------------------------
    forge::SoundBuffer* BBQSplashFactory::m_Data = nullptr;

    //----------------------------------------------------------------------------
    forge::SoundBuffer* BBQSplashFactory::Create() const
    {
    if (m_Data == nullptr)
    {
        forge::SoundBuffer* data = new forge::SoundBuffer();
        m_Data = data;
        data->SetInstanceAddr(&m_Data);
        data->SetDataNameId(DataList::SoundBuffer::BBQSplash);

        data->SetFile("assets/fire.wav");

    }

        return m_Data;
    }

    //----------------------------------------------------------------------------
    forge::SoundBuffer* HitMouseFactory::m_Data = nullptr;

    //----------------------------------------------------------------------------
    forge::SoundBuffer* HitMouseFactory::Create() const
    {
    if (m_Data == nullptr)
    {
        forge::SoundBuffer* data = new forge::SoundBuffer();
        m_Data = data;
        data->SetInstanceAddr(&m_Data);
        data->SetDataNameId(DataList::SoundBuffer::HitMouse);

        data->SetFile("assets/hit_mouse.wav");

    }

        return m_Data;
    }

    }}}
