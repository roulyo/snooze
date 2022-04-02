
    #include <forge/Project.h>
    #include "EntityCatalog.h"
    #include "DataList.h"

    //----------------------------------------------------------------------------
    EntityCatalog::EntityCatalog()
    {

        RegisterData(DataList::Entity::SnoozeButton, m_SnoozeButtonFactory);

        RegisterData(DataList::Entity::Alarm, m_AlarmFactory);

        RegisterData(DataList::Entity::AlarmScrew, m_AlarmScrewFactory);

        RegisterData(DataList::Entity::AlarmButtonNeutral, m_AlarmButtonNeutralFactory);

    }

    //----------------------------------------------------------------------------
    EntityCatalog::~EntityCatalog()
    {
        m_Factories.clear();
    }
