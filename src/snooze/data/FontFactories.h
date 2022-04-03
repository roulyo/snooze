
    #pragma once
    #include <forge/engine/data/DataFactory.h>

    #include <forge/engine/rendering/resource/Font.h>

    namespace forge { namespace generated { namespace FontFactories {

    //----------------------------------------------------------------------------
    class AlarmClockFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Font* Create() const override;

    private:
        static forge::Font* m_Data;

    };

    //----------------------------------------------------------------------------
    class StoryFontFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Font* Create() const override;

    private:
        static forge::Font* m_Data;

    };

    }}}
