
    #pragma once
    #include <forge/engine/data/DataFactory.h>

    #include <forge/Project.h>

    #include <forge/engine/ecs/Entity.h>

    #include <forge/builtin/rendering/RenderableComponent.h>

    #include <snooze/data/SpriteCatalog.h>

    #include <snooze/ecs/SnoozableComponent.h>

    namespace forge { namespace generated { namespace EntityFactories {

    //----------------------------------------------------------------------------
    class SnoozeButtonFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    }}}
