
    #pragma once
    #include <forge/engine/data/DataFactory.h>

    #include <forge/Project.h>

    #include <forge/engine/rendering/drawable/Sprite.h>

    namespace forge { namespace generated { namespace SpriteFactories {

    //----------------------------------------------------------------------------
    class ForgeSpriteFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Sprite* Create() const override;

    };    

    }}}
