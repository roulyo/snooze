
    #pragma once
    #include <forge/engine/data/DataCatalog.h>
    #include "SpriteFactories.h"

    #include <forge/Project.h>

    #include <forge/engine/rendering/drawable/Sprite.h>

    //----------------------------------------------------------------------------
    class SpriteCatalog : public forge::DataCatalog<forge::Sprite>
    {
        FRG__DECL_CATALOG(SpriteCatalog);

    public:
        SpriteCatalog();
        ~SpriteCatalog();

    private:

        forge::generated::SpriteFactories::ForgeSpriteFactory m_ForgeSpriteFactory;

        forge::generated::SpriteFactories::AlarmNeutralSpriteFactory m_AlarmNeutralSpriteFactory;

        forge::generated::SpriteFactories::AlarmScrewSpriteFactory m_AlarmScrewSpriteFactory;

        forge::generated::SpriteFactories::AlarmButtonNeutralSpriteFactory m_AlarmButtonNeutralSpriteFactory;

        forge::generated::SpriteFactories::AlarmButtonPressedSpriteFactory m_AlarmButtonPressedSpriteFactory;

    };
