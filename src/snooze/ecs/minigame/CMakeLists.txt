# CMakeLists.txt for src/snooze/ecs/minigame
ADD_SUBDIRECTORY(sample)
ADD_SUBDIRECTORY(padlock)
ADD_SUBDIRECTORY(mouseattack)

MACRO_ADD_SOURCES(EXE_SRC
BaseMiniGameComponent.cpp BaseMiniGameComponent.h BaseMiniGame.cpp BaseMiniGame.h
)
