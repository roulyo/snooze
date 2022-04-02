
    #include <forge/Project.h>
    #include "TextureCatalog.h"
    #include "DataList.h"

    //----------------------------------------------------------------------------
    TextureCatalog::TextureCatalog()
    {

        RegisterData(DataList::Texture::ForgeSheet, m_ForgeSheetFactory);

    }

    //----------------------------------------------------------------------------
    TextureCatalog::~TextureCatalog()
    {
        m_Factories.clear();
    }
