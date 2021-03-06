
    #pragma once
    #include <forge/engine/data/DataFactory.h>

    #include <forge/Project.h>

    #include <forge/engine/ecs/Entity.h>

    #include <forge/builtin/rendering/RenderableComponent.h>

    #include <forge/builtin/3Cs/ScreenMappableComponent.h>

    #include <snooze/data/SpriteCatalog.h>

    #include <snooze/data/SoundCatalog.h>

    #include <snooze/ecs/SnoozableComponent.h>

    #include <snooze/ecs/HoverableComponent.h>

    #include <snooze/ecs/SoundClickableComponent.h>

    namespace forge { namespace generated { namespace EntityFactories {

    //----------------------------------------------------------------------------
    class AlarmFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class AlarmScrewFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class AlarmButtonFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class ScrewdriverFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class CleaningBroomFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class CleaningWebFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class CleaningFireFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class CleaningIceFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class CleaningSpongeFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class CleaningGooFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class LockKeyFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class LockLockFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class LockMetalBoxFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class MouseAttackOpenAlarmFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class MouseAttackSmokeFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class MouseAttackBbqMouseFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class MouseAttackWetMouseFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class MouseAttackWaterGlassFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class VerminEnemyFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class BatteryContainerFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class BatteryMouseFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class BatteryItemFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    }}}
