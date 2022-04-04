
    #pragma once
    #include <forge/engine/data/DataFactory.h>

    #include <forge/Project.h>

    #include <forge/engine/rendering/resource/Texture.h>

    namespace forge { namespace generated { namespace TextureFactories {

    //----------------------------------------------------------------------------
    class ForgeSheetFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Texture* Create() const override;

    private:
        static forge::Texture* m_Data;

    };

    //----------------------------------------------------------------------------
    class AlarmSheetFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Texture* Create() const override;

    private:
        static forge::Texture* m_Data;

    };

    //----------------------------------------------------------------------------
    class SampleSheetFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Texture* Create() const override;

    private:
        static forge::Texture* m_Data;

    };

    //----------------------------------------------------------------------------
    class ConfigSheetFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Texture* Create() const override;

    private:
        static forge::Texture* m_Data;

    };

    }}}
