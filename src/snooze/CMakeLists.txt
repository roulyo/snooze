# CMakeLists.txt for src/snooze
ADD_SUBDIRECTORY(data)

MACRO_ADD_SOURCES(EXE_SRC
Precomp.h Snooze.cpp Snooze.h
)
