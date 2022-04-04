# CMakeLists.txt for src/snooze/ecs/minigame
ADD_SUBDIRECTORY(battery)
ADD_SUBDIRECTORY(mouseattack)
ADD_SUBDIRECTORY(padlock)
ADD_SUBDIRECTORY(sample)
ADD_SUBDIRECTORY(vermins)

MACRO_ADD_SOURCES(EXE_SRC
BaseMiniGame.cpp BaseMiniGame.h BaseMiniGameComponent.cpp BaseMiniGameComponent.h
)
