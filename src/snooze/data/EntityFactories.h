
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
    class BroomFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    //----------------------------------------------------------------------------
    class WebFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    }}}
