
    #pragma once
    #include <forge/engine/data/DataCatalog.h>
    #include "EntityFactories.h"

    #include <forge/Project.h>

    #include <forge/engine/ecs/Entity.h>

    #include <forge/builtin/rendering/RenderableComponent.h>

    #include <forge/builtin/3Cs/ScreenMappableComponent.h>

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

        forge::generated::EntityFactories::CleaningBroomFactory m_CleaningBroomFactory;

        forge::generated::EntityFactories::CleaningWebFactory m_CleaningWebFactory;

        forge::generated::EntityFactories::CleaningFireFactory m_CleaningFireFactory;

        forge::generated::EntityFactories::CleaningIceFactory m_CleaningIceFactory;

        forge::generated::EntityFactories::LockKeyFactory m_LockKeyFactory;

        forge::generated::EntityFactories::LockLockFactory m_LockLockFactory;

        forge::generated::EntityFactories::LockChainBackFactory m_LockChainBackFactory;

        forge::generated::EntityFactories::LockChainFrontFactory m_LockChainFrontFactory;

    };
