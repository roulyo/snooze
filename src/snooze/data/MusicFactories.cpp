
    #include <forge/Project.h>
    #include <forge/engine/data/api/DataAPI.h>
    
    #include "MusicFactories.h"
    #include "DataList.h"

    //extra_includes

    namespace forge { namespace generated { namespace MusicFactories {

    //----------------------------------------------------------------------------
    forge::Music* AmbientFactory::m_Data = nullptr;

    //----------------------------------------------------------------------------
    forge::Music* AmbientFactory::Create() const
    {
    if (m_Data == nullptr)
    {
        forge::Music* data = new forge::Music();
        m_Data = data;
        data->SetInstanceAddr(&m_Data);
        data->SetDataNameId(DataList::Music::Ambient);

        data->SetFile("assets/music.ogg");

    }

        return m_Data;
    }

    }}}
