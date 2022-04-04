# CMakeLists.txt for src/snooze/data
ADD_SUBDIRECTORY(def)

MACRO_ADD_SOURCES(EXE_SRC
DataList.cpp DataList.h EntityCatalog.cpp EntityCatalog.h EntityFactories.cpp EntityFactories.h FontCatalog.cpp FontCatalog.h FontFactories.cpp FontFactories.h MusicCatalog.cpp MusicCatalog.h MusicFactories.cpp MusicFactories.h SoundBufferCatalog.cpp SoundBufferCatalog.h SoundBufferFactories.cpp SoundBufferFactories.h SoundCatalog.cpp SoundCatalog.h SoundFactories.cpp SoundFactories.h SpriteCatalog.cpp SpriteCatalog.h SpriteFactories.cpp SpriteFactories.h TextureCatalog.cpp TextureCatalog.h TextureFactories.cpp TextureFactories.h
)
