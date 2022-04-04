
    #pragma once
    #include <forge/engine/data/DataCatalog.h>
    #include "EntityFactories.h"

    #include <forge/Project.h>

    #include <forge/engine/ecs/Entity.h>

    #include <forge/builtin/rendering/RenderableComponent.h>

    #include <forge/builtin/3Cs/ScreenMappableComponent.h>

    #include <snooze/data/SpriteCatalog.h>

    #include <snooze/data/SoundCatalog.h>

    #include <snooze/ecs/SnoozableComponent.h>

    #include <snooze/ecs/HoverableComponent.h>

    #include <snooze/ecs/SoundClickableComponent.h>

    //----------------------------------------------------------------------------
    class EntityCatalog : public forge::DataCatalog<forge::Entity>
    {
        FRG__DECL_CATALOG(EntityCatalog);

    public:
        EntityCatalog();
        ~EntityCatalog();

    private:

        forge::generated::EntityFactories::AlarmFactory m_AlarmFactory;

        forge::generated::EntityFactories::AlarmScrewFactory m_AlarmScrewFactory;

        forge::generated::EntityFactories::AlarmButtonFactory m_AlarmButtonFactory;

        forge::generated::EntityFactories::CleaningBroomFactory m_CleaningBroomFactory;

        forge::generated::EntityFactories::CleaningWebFactory m_CleaningWebFactory;

        forge::generated::EntityFactories::CleaningFireFactory m_CleaningFireFactory;

        forge::generated::EntityFactories::CleaningIceFactory m_CleaningIceFactory;

        forge::generated::EntityFactories::CleaningSpongeFactory m_CleaningSpongeFactory;

        forge::generated::EntityFactories::CleaningGooFactory m_CleaningGooFactory;

        forge::generated::EntityFactories::LockKeyFactory m_LockKeyFactory;

        forge::generated::EntityFactories::LockLockFactory m_LockLockFactory;

        forge::generated::EntityFactories::LockChainBackFactory m_LockChainBackFactory;

        forge::generated::EntityFactories::LockChainFrontFactory m_LockChainFrontFactory;

        forge::generated::EntityFactories::MouseAttackOpenAlarmFactory m_MouseAttackOpenAlarmFactory;

        forge::generated::EntityFactories::MouseAttackSmokeFactory m_MouseAttackSmokeFactory;

        forge::generated::EntityFactories::MouseAttackBbqMouseFactory m_MouseAttackBbqMouseFactory;

        forge::generated::EntityFactories::MouseAttackWetMouseFactory m_MouseAttackWetMouseFactory;

        forge::generated::EntityFactories::MouseAttackWaterGlassFactory m_MouseAttackWaterGlassFactory;

        forge::generated::EntityFactories::VerminEnemyFactory m_VerminEnemyFactory;

    };
