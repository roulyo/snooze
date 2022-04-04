# CMakeLists.txt for src/snooze/ecs
ADD_SUBDIRECTORY(minigame)

MACRO_ADD_SOURCES(EXE_SRC
HoverableComponent.cpp HoverableComponent.h HoveringSystem.cpp HoveringSystem.h RefereeSystem.cpp RefereeSystem.h SnoozableComponent.cpp SnoozableComponent.h SnoozeSystem.cpp SnoozeSystem.h SoundClickableComponent.cpp SoundClickableComponent.h SoundClickingSystem.cpp SoundClickingSystem.h
)
