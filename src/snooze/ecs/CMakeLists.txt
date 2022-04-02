# CMakeLists.txt for src/snooze/ecs
ADD_SUBDIRECTORY(minigame)

MACRO_ADD_SOURCES(EXE_SRC
RefereeSystem.cpp RefereeSystem.h SnoozableComponent.cpp SnoozableComponent.h SnoozeSystem.cpp SnoozeSystem.h
)
