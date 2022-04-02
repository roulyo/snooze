
CMAKE_MINIMUM_REQUIRED(VERSION 3.10.2)

INCLUDE(CMake/Config.cmake)
INCLUDE(CMake/Version.cmake)
  
#Add Forge
ADD_SUBDIRECTORY(${FORGE_FOLDER_PATH} forge)

# See http://git.libssh.org/projects/libssh.git/tree/ for example of a good project configuration.
# Additional CMake modules, specific for this project
SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake/Modules)

# Load those modules
INCLUDE(Define_CMakeDefaults)
INCLUDE(Define_PlatformDefaults)
INCLUDE(Define_CompilerFlags)

INCLUDE(Macro_EnsureOutOfSourceBuild)
INCLUDE(Macro_AddSources)

# Project command is here, to set some values correctly.
SET(CMAKE_PROJECT_NAME "snooze")
PROJECT(${CMAKE_PROJECT_NAME})

# Nifty marco, which forbids in source build. (source: http://git.libssh.org/projects/libssh.git)
MACRO_ENSURE_OUT_OF_SOURCE_BUILD("${PROJECT_NAME}  requires an out of source build. Please create a separate build directory and run 'cmake /path/to/${CMAKE_PROJECT_NAME} [options]' there.")

SET(EXECUTABLE_VERSION "${EXECUTABLE_VERSION_MAJOR}.${EXECUTABLE_VERSION_MINOR}.${EXECUTABLE_VERSION_PATCH}")

# Global vars
SET(EXECUTABLE_NAME ${CMAKE_PROJECT_NAME})

SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

STRING(TOUPPER ${CMAKE_BUILD_TYPE} CMAKE_BUILD_TYPE_CAP)
MESSAGE(STATUS "Current built type: ${CMAKE_BUILD_TYPE}")
MESSAGE(STATUS "Current build type flags: ${CMAKE_CXX_FLAGS_${CMAKE_BUILD_TYPE_CAP}}")

MESSAGE(STATUS "Configuring application ${APPLICATION_NAME}")

SET ( EXE_SRC "" )

ADD_SUBDIRECTORY(${CMAKE_CURRENT_LIST_DIR}/src)

#Line below outputs all included source.
MACRO_PRINT_SOURCES( EXE_SRC )

ADD_EXECUTABLE(
    ${EXECUTABLE_NAME}
    ${EXE_SRC}
)

IF(WIN32)
    SET_TARGET_PROPERTIES(${EXECUTABLE_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}")
ENDIF(WIN32)

TARGET_INCLUDE_DIRECTORIES(
    ${EXECUTABLE_NAME}

    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src

)

TARGET_LINK_LIBRARIES(
    ${EXECUTABLE_NAME}

    forge
    forgebuiltin
    
    sfml-graphics
    sfml-system
    sfml-window

)

MACRO (_MACRO_SOURCE_GROUP)
    MACRO_SOURCE_GROUP(${ARGV0} ${ARGV1} "${CMAKE_CURRENT_LIST_DIR}/src")
ENDMACRO()

_MACRO_SOURCE_GROUP("."       EXE_SRC)

