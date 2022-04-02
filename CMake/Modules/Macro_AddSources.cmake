# Takes any amount of sources and propagates them up in hierarchy.
# Be aware that add_subdirectory must go before add_sources to propagate correctly.

MESSAGE(STATUS "Using ADD_SOURCES macros")

MACRO (MACRO_PREPARE_SOURCES)
  IF ("${ARGN}" STREQUAL "")
    SET (VARIABLE_NAME "SRCS")
  ELSE()
    SET (VARIABLE_NAME "${ARGN}")
  ENDIF()
  MESSAGE(STATUS "Filling variable ${VARIABLE_NAME} with source list")
  SET (CUMULATIVE_SRCS ${VARIABLE_NAME})
  SET (${CUMULATIVE_SRCS} "")
ENDMACRO()

MACRO (MACRO_ADD_SOURCES)
    FILE (RELATIVE_PATH _relPath "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}")
    FOREACH (_src ${ARGN})
        IF (NOT (${_src} STREQUAL ${ARGV0}))
			LIST (APPEND TMP_LIST "${CMAKE_CURRENT_SOURCE_DIR}/${_src}")
        ENDIF()
    ENDFOREACH()
	
	LIST (APPEND ${ARGV0} ${TMP_LIST})
	
    IF (_relPath)
        # Propagate CUMULATIVE_SRCS to parent directory
        # If this is not the root dir (by relative path)
        SET (${ARGV0} ${${ARGV0}} PARENT_SCOPE)
    ENDIF()
ENDMACRO()

MACRO (MACRO_SOURCE_GROUP)
    FOREACH(_source IN ITEMS ${${ARGV1}})
        GET_FILENAME_COMPONENT(_source_path "${_source}" PATH)
        FILE(RELATIVE_PATH _source_path_rel "${ARGV2}/${ARGV0}" "${_source_path}")
        
        STRING(FIND "${_source_path_rel}" ".." _find)
        IF (${_find} EQUAL 0)
            FILE(RELATIVE_PATH _source_path_rel "${ARGV3}/${ARGV0}" "${_source_path}")
        ENDIF()

        STRING(REPLACE "/" "\\" _group_path "${_source_path_rel}")
        SOURCE_GROUP("${_group_path}" FILES "${_source}")
    ENDFOREACH()
ENDMACRO()

MACRO (MACRO_PRINT_SOURCES)
  MESSAGE(STATUS "Current sources for ${ARGV0}: ")
  FOREACH (_src ${${ARGV0}})
    MESSAGE(STATUS "  " ${_src})
  ENDFOREACH()
ENDMACRO()
