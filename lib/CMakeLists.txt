cmake_minimum_required (VERSION 3.22)

project (cdotenv)

set (CMAKE_C_STANDARD 90)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")

set (SOURCES
     cdotenv.c)

if (CDOTENV_SHARED)
  add_library (cdotenv
               SHARED
               ${SOURCES})
else ()
  add_library (cdotenv
               STATIC
               ${SOURCES})
endif ()