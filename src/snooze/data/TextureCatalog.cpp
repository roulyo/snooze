
    #include <forge/Project.h>
    #include "TextureCatalog.h"
    #include "DataList.h"

    //----------------------------------------------------------------------------
    TextureCatalog::TextureCatalog()
    {

        RegisterData(DataList::Texture::ForgeSheet, m_ForgeSheetFactory);

        RegisterData(DataList::Texture::AlarmSheet, m_AlarmSheetFactory);

        RegisterData(DataList::Texture::SampleSheet, m_SampleSheetFactory);

        RegisterData(DataList::Texture::ConfigSheet, m_ConfigSheetFactory);

    }

    //----------------------------------------------------------------------------
    TextureCatalog::~TextureCatalog()
    {
        m_Factories.clear();
    }
