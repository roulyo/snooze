 
# Here should go compiler specific flags and stuff.

# This project uses C++17.
IF(WIN32)
    SET(CMAKE_CXX_FLAGS "/Zc:externConstexpr /W3")
ELSE(WIN32)
    SET(CMAKE_CXX_FLAGS "-std=c++17 -pthread")
ENDIF(WIN32)

# Debug has -D_DEBUG
IF(WIN32)
    SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -D_DEBUG /Od /Zi /MDd")
ELSE(WIN32)
    SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -D_DEBUG -g -ggdb")
ENDIF(WIN32)

# Release
IF(WIN32)
    SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} /O2 /Ob2 /Oi /MD /fp:fast")
ELSE(WIN32)
    SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
ENDIF(WIN32)
