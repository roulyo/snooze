
    #include <forge/Project.h>
    #include "FontCatalog.h"
    #include "DataList.h"

    //----------------------------------------------------------------------------
    FontCatalog::FontCatalog()
    {

        RegisterData(DataList::Font::AlarmClock, m_AlarmClockFactory);

        RegisterData(DataList::Font::StoryFont, m_StoryFontFactory);

    }

    //----------------------------------------------------------------------------
    FontCatalog::~FontCatalog()
    {
        m_Factories.clear();
    }
