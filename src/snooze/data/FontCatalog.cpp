
    #include <forge/Project.h>
    #include "FontCatalog.h"
    #include "DataList.h"

    //----------------------------------------------------------------------------
    FontCatalog::FontCatalog()
    {

        RegisterData(DataList::Font::AlarmClock, m_AlarmClockFactory);

    }

    //----------------------------------------------------------------------------
    FontCatalog::~FontCatalog()
    {
        m_Factories.clear();
    }
