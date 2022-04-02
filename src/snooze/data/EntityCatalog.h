
    #pragma once
    #include <forge/engine/data/DataCatalog.h>
    #include "EntityFactories.h"

    #include <forge/Project.h>

    #include <forge/engine/ecs/Entity.h>

    #include <forge/builtin/3Cs/PlayableCharacterComponent.h>

    #include <forge/builtin/physics/PhysicableComponent.h>

    #include <forge/builtin/rendering/RenderableComponent.h>

    #include <snooze/data/SpriteCatalog.h>

    //----------------------------------------------------------------------------
    class EntityCatalog : public forge::DataCatalog<forge::Entity>
    {
        FRG__DECL_CATALOG(EntityCatalog);

    public:
        EntityCatalog();
        ~EntityCatalog();

    private:

        forge::generated::EntityFactories::PlayableCharacterFactory m_PlayableCharacterFactory;

    };
