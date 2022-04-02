
    #include <forge/Project.h>
    #include "EntityCatalog.h"
    #include "DataList.h"

    //----------------------------------------------------------------------------
    EntityCatalog::EntityCatalog()
    {

        RegisterData(DataList::Entity::SnoozeButton, m_SnoozeButtonFactory);

        RegisterData(DataList::Entity::Alarm, m_AlarmFactory);

        RegisterData(DataList::Entity::AlarmScrew, m_AlarmScrewFactory);

        RegisterData(DataList::Entity::AlarmButton, m_AlarmButtonFactory);

        RegisterData(DataList::Entity::Broom, m_BroomFactory);

        RegisterData(DataList::Entity::Web, m_WebFactory);

    }

    //----------------------------------------------------------------------------
    EntityCatalog::~EntityCatalog()
    {
        m_Factories.clear();
    }
