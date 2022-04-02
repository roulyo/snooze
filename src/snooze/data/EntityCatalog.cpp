
    #include <forge/Project.h>
    #include "EntityCatalog.h"
    #include "DataList.h"

    //----------------------------------------------------------------------------
    EntityCatalog::EntityCatalog()
    {

        RegisterData(DataList::Entity::SnoozeButton, m_SnoozeButtonFactory);

    }

    //----------------------------------------------------------------------------
    EntityCatalog::~EntityCatalog()
    {
        m_Factories.clear();
    }
