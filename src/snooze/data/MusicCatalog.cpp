
    #include <forge/Project.h>
    #include "MusicCatalog.h"
    #include "DataList.h"

    //----------------------------------------------------------------------------
    MusicCatalog::MusicCatalog()
    {

        RegisterData(DataList::Music::Ambient, m_AmbientFactory);

    }

    //----------------------------------------------------------------------------
    MusicCatalog::~MusicCatalog()
    {
        m_Factories.clear();
    }
