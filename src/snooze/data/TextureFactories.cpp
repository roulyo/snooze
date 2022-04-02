
    #include <forge/Project.h>
    #include <forge/engine/data/api/DataAPI.h>
    
    #include "TextureFactories.h"
    #include "DataList.h"

    //extra_includes

    namespace forge { namespace generated { namespace TextureFactories {

    //----------------------------------------------------------------------------
    forge::Texture* ForgeSheetFactory::m_Data = nullptr;

    //----------------------------------------------------------------------------
    forge::Texture* ForgeSheetFactory::Create() const
    {
    if (m_Data == nullptr)
    {
        forge::Texture* data = new forge::Texture();
        m_Data = data;
        data->SetInstanceAddr(&m_Data);
        data->SetDataNameId(DataList::Texture::ForgeSheet);

        data->SetFile("assets/forge.png");

    }

        return m_Data;
    }

    }}}
