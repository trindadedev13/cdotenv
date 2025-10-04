cmake_minimum_required (VERSION 3.22)

project (cdotenv_java)

set (CDOTENV_SHARED TRUE)

add_library (cdotenv_java
             SHARED
             cdotenv_java.c)

set (CMAKE_C_STANDARD 90)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")

add_subdirectory (../lib
                  ${CMAKE_CURRENT_BINARY_DIR}/lib)

target_include_directories (cdotenv_java
                            PRIVATE
                            ../lib)

target_link_libraries (cdotenv_java
                       PRIVATE
                       cdotenv)