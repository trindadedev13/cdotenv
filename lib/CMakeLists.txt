cmake_minimum_required (VERSION 3.22)

project (cdotenv)

set (CMAKE_C_STANDARD 90)

set (SOURCES
     cdotenv.c)

add_library (cdotenv
             STATIC
             ${SOURCES})