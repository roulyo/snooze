# CMakeLists.txt for src/snooze
ADD_SUBDIRECTORY(data)
ADD_SUBDIRECTORY(ecs)
ADD_SUBDIRECTORY(gamestate)

MACRO_ADD_SOURCES(EXE_SRC
GameEvents.h Precomp.h Snooze.cpp Snooze.h
)
