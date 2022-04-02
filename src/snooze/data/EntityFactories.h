
    #pragma once
    #include <forge/engine/data/DataFactory.h>

    #include <forge/Project.h>

    #include <forge/engine/ecs/Entity.h>

    #include <forge/builtin/3Cs/PlayableCharacterComponent.h>

    #include <forge/builtin/physics/PhysicableComponent.h>

    #include <forge/builtin/rendering/RenderableComponent.h>

    #include <snooze/data/SpriteCatalog.h>

    namespace forge { namespace generated { namespace EntityFactories {

    //----------------------------------------------------------------------------
    class PlayableCharacterFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Entity* Create() const override;

    };    

    }}}
