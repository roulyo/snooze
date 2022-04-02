
    #pragma once
    #include <forge/engine/data/DataCatalog.h>
    #include "FontFactories.h"

    #include <forge/engine/rendering/resource/Font.h>

    //----------------------------------------------------------------------------
    class FontCatalog : public forge::DataCatalog<forge::Font>
    {
        FRG__DECL_CATALOG(FontCatalog);

    public:
        FontCatalog();
        ~FontCatalog();

    private:

        forge::generated::FontFactories::AlarmClockFactory m_AlarmClockFactory;

    };
