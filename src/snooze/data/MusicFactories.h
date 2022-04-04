
    #pragma once
    #include <forge/engine/data/DataFactory.h>

    #include <forge/Project.h>

    #include <forge/engine/audio/resource/Music.h>

    namespace forge { namespace generated { namespace MusicFactories {

    //----------------------------------------------------------------------------
    class AmbientFactory : public forge::AbstractDataFactory
    {
    public:
        forge::Music* Create() const override;

    private:
        static forge::Music* m_Data;

    };

    }}}
