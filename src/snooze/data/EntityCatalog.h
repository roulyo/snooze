
    #pragma once
    #include <forge/engine/data/DataCatalog.h>
    #include "EntityFactories.h"

    #include <forge/Project.h>

    #include <forge/engine/ecs/Entity.h>

    #include <forge/builtin/rendering/RenderableComponent.h>

    #include <snooze/data/SpriteCatalog.h>

    #include <snooze/ecs/SnoozableComponent.h>

    //----------------------------------------------------------------------------
    class EntityCatalog : public forge::DataCatalog<forge::Entity>
    {
        FRG__DECL_CATALOG(EntityCatalog);

    public:
        EntityCatalog();
        ~EntityCatalog();

    private:

        forge::generated::EntityFactories::SnoozeButtonFactory m_SnoozeButtonFactory;

        forge::generated::EntityFactories::AlarmFactory m_AlarmFactory;

        forge::generated::EntityFactories::AlarmScrewFactory m_AlarmScrewFactory;

        forge::generated::EntityFactories::AlarmButtonFactory m_AlarmButtonFactory;

    };
