
    #pragma once
    #include <forge/engine/data/DataFactory.h>

    #include <forge/Project.h>

    #include <forge/engine/ecs/Entity.h>

    #include <forge/builtin/rendering/RenderableComponent.h>

    #include <forge/builtin/3Cs/ScreenMappableComponent.h>

    #include <snooze/data/SpriteCatalog.h>

    #include <snooze/ecs/SnoozableComponent.h>

    namespace forge { namespace generated { namespace EntityFactories {

    //----------------------------------------------------------------------------
    class SnoozeButtonFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

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
    class LockChainBackFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class LockChainFrontFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    }}}
