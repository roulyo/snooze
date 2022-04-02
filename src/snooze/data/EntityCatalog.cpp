
    #include <forge/Project.h>
    #include "EntityCatalog.h"
    #include "DataList.h"

    //----------------------------------------------------------------------------
    EntityCatalog::EntityCatalog()
    {

        RegisterData(DataList::Entity::PlayableCharacter, m_PlayableCharacterFactory);

    }

    //----------------------------------------------------------------------------
    EntityCatalog::~EntityCatalog()
    {
        m_Factories.clear();
    }
