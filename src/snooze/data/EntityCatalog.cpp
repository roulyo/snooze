
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

        RegisterData(DataList::Entity::CleaningBroom, m_CleaningBroomFactory);

        RegisterData(DataList::Entity::CleaningWeb, m_CleaningWebFactory);

        RegisterData(DataList::Entity::CleaningFire, m_CleaningFireFactory);

        RegisterData(DataList::Entity::CleaningIce, m_CleaningIceFactory);

        RegisterData(DataList::Entity::CleaningSponge, m_CleaningSpongeFactory);

        RegisterData(DataList::Entity::CleaningGoo, m_CleaningGooFactory);

        RegisterData(DataList::Entity::LockKey, m_LockKeyFactory);

        RegisterData(DataList::Entity::LockLock, m_LockLockFactory);

        RegisterData(DataList::Entity::LockChainBack, m_LockChainBackFactory);

        RegisterData(DataList::Entity::LockChainFront, m_LockChainFrontFactory);

        RegisterData(DataList::Entity::MouseAttackOpenAlarm, m_MouseAttackOpenAlarmFactory);

        RegisterData(DataList::Entity::MouseAttackSmoke, m_MouseAttackSmokeFactory);

        RegisterData(DataList::Entity::MouseAttackBbqMouse, m_MouseAttackBbqMouseFactory);

        RegisterData(DataList::Entity::MouseAttackWetMouse, m_MouseAttackWetMouseFactory);

        RegisterData(DataList::Entity::MouseAttackWaterGlass, m_MouseAttackWaterGlassFactory);

    }

    //----------------------------------------------------------------------------
    EntityCatalog::~EntityCatalog()
    {
        m_Factories.clear();
    }
