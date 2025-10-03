cmake_minimum_required (VERSION 3.22)

project (cdotenv_test)

add_executable (cdotenv_test
                main.c)

set (CMAKE_C_STANDARD 90)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fno-omit-frame-pointer -Wall -Wextra -pedantic")

add_subdirectory (../lib
                  ${CMAKE_CURRENT_BINARY_DIR}/lib)

target_include_directories (cdotenv_test
                            PRIVATE
                            ../lib)

target_link_libraries (cdotenv_test
                       PRIVATE
                       cdotenv)