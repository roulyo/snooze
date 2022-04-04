
    #pragma once
    #include <forge/engine/data/DataCatalog.h>
    #include "MusicFactories.h"

    #include <forge/Project.h>

    #include <forge/engine/audio/resource/Music.h>

    //----------------------------------------------------------------------------
    class MusicCatalog : public forge::DataCatalog<forge::Music>
    {
        FRG__DECL_CATALOG(MusicCatalog);

    public:
        MusicCatalog();
        ~MusicCatalog();

    private:

        forge::generated::MusicFactories::AmbientFactory m_AmbientFactory;

    };
