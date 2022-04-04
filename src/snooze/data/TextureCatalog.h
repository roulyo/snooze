
    #pragma once
    #include <forge/engine/data/DataCatalog.h>
    #include "TextureFactories.h"

    #include <forge/Project.h>

    #include <forge/engine/rendering/resource/Texture.h>

    //----------------------------------------------------------------------------
    class TextureCatalog : public forge::DataCatalog<forge::Texture>
    {
        FRG__DECL_CATALOG(TextureCatalog);

    public:
        TextureCatalog();
        ~TextureCatalog();

    private:

        forge::generated::TextureFactories::ForgeSheetFactory m_ForgeSheetFactory;

        forge::generated::TextureFactories::AlarmSheetFactory m_AlarmSheetFactory;

        forge::generated::TextureFactories::SampleSheetFactory m_SampleSheetFactory;

        forge::generated::TextureFactories::ConfigSheetFactory m_ConfigSheetFactory;

    };
