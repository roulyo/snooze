
    #include <forge/Project.h>
    #include <forge/engine/data/api/DataAPI.h>
    
    #include "SoundFactories.h"
    #include "DataList.h"

    
    #include "SoundBufferCatalog.h"



    namespace forge { namespace generated { namespace SoundFactories {

    //----------------------------------------------------------------------------
    forge::Sound* ErrorFactory::Create() const
    {
        forge::Sound* data = new forge::Sound();
        data->SetDataNameId(DataList::Sound::Error);

        data->SetSoundBuffer(forge::DataAPI::GetDataFrom<SoundBufferCatalog>(DataList::SoundBuffer::Error));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sound* SpeechFactory::Create() const
    {
        forge::Sound* data = new forge::Sound();
        data->SetDataNameId(DataList::Sound::Speech);

        data->SetSoundBuffer(forge::DataAPI::GetDataFrom<SoundBufferCatalog>(DataList::SoundBuffer::Speech));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sound* ScrewFactory::Create() const
    {
        forge::Sound* data = new forge::Sound();
        data->SetDataNameId(DataList::Sound::Screw);

        data->SetSoundBuffer(forge::DataAPI::GetDataFrom<SoundBufferCatalog>(DataList::SoundBuffer::Screw));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sound* SnoozePressFactory::Create() const
    {
        forge::Sound* data = new forge::Sound();
        data->SetDataNameId(DataList::Sound::SnoozePress);

        data->SetSoundBuffer(forge::DataAPI::GetDataFrom<SoundBufferCatalog>(DataList::SoundBuffer::SnoozePress));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sound* SnoozeReleaseFactory::Create() const
    {
        forge::Sound* data = new forge::Sound();
        data->SetDataNameId(DataList::Sound::SnoozeRelease);

        data->SetSoundBuffer(forge::DataAPI::GetDataFrom<SoundBufferCatalog>(DataList::SoundBuffer::SnoozeRelease));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sound* TakeObjectCommonFactory::Create() const
    {
        forge::Sound* data = new forge::Sound();
        data->SetDataNameId(DataList::Sound::TakeObjectCommon);

        data->SetSoundBuffer(forge::DataAPI::GetDataFrom<SoundBufferCatalog>(DataList::SoundBuffer::TakeObjectCommon));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sound* CleanCommonFactory::Create() const
    {
        forge::Sound* data = new forge::Sound();
        data->SetDataNameId(DataList::Sound::CleanCommon);

        data->SetSoundBuffer(forge::DataAPI::GetDataFrom<SoundBufferCatalog>(DataList::SoundBuffer::CleanCommon));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sound* KeyFactory::Create() const
    {
        forge::Sound* data = new forge::Sound();
        data->SetDataNameId(DataList::Sound::Key);

        data->SetSoundBuffer(forge::DataAPI::GetDataFrom<SoundBufferCatalog>(DataList::SoundBuffer::Key));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sound* Lock1Factory::Create() const
    {
        forge::Sound* data = new forge::Sound();
        data->SetDataNameId(DataList::Sound::Lock1);

        data->SetSoundBuffer(forge::DataAPI::GetDataFrom<SoundBufferCatalog>(DataList::SoundBuffer::Lock1));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sound* Lock2Factory::Create() const
    {
        forge::Sound* data = new forge::Sound();
        data->SetDataNameId(DataList::Sound::Lock2);

        data->SetSoundBuffer(forge::DataAPI::GetDataFrom<SoundBufferCatalog>(DataList::SoundBuffer::Lock2));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sound* Water1Factory::Create() const
    {
        forge::Sound* data = new forge::Sound();
        data->SetDataNameId(DataList::Sound::Water1);

        data->SetSoundBuffer(forge::DataAPI::GetDataFrom<SoundBufferCatalog>(DataList::SoundBuffer::Water1));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sound* Water2Factory::Create() const
    {
        forge::Sound* data = new forge::Sound();
        data->SetDataNameId(DataList::Sound::Water2);

        data->SetSoundBuffer(forge::DataAPI::GetDataFrom<SoundBufferCatalog>(DataList::SoundBuffer::Water2));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sound* BBQSplashFactory::Create() const
    {
        forge::Sound* data = new forge::Sound();
        data->SetDataNameId(DataList::Sound::BBQSplash);

        data->SetSoundBuffer(forge::DataAPI::GetDataFrom<SoundBufferCatalog>(DataList::SoundBuffer::BBQSplash));

        return data;
    }

    //----------------------------------------------------------------------------
    forge::Sound* HitMouseFactory::Create() const
    {
        forge::Sound* data = new forge::Sound();
        data->SetDataNameId(DataList::Sound::HitMouse);

        data->SetSoundBuffer(forge::DataAPI::GetDataFrom<SoundBufferCatalog>(DataList::SoundBuffer::HitMouse));

        return data;
    }

    }}}
