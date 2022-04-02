
    #include <forge/Project.h>
    #include <forge/engine/data/api/DataAPI.h>
    
    #include "FontFactories.h"
    #include "DataList.h"

    //extra_includes

    namespace forge { namespace generated { namespace FontFactories {

    //----------------------------------------------------------------------------
    forge::Font* AlarmClockFactory::m_Data = nullptr;

    //----------------------------------------------------------------------------
    forge::Font* AlarmClockFactory::Create() const
    {
    if (m_Data == nullptr)
    {
        forge::Font* data = new forge::Font();
        m_Data = data;
        data->SetInstanceAddr(&m_Data);
        data->SetDataNameId(DataList::Font::AlarmClock);

        data->SetFile("assets/alarm_clock.ttf");

    }

        return m_Data;
    }

    }}}
