cmake_minimum_required(VERSION 3.16)

# Get version from src/xdgdirs.h
file(READ src/xdgdirs.h foo)
string(REGEX MATCH "#define XDGDIRS_VER \"([0-9]+.[0-9]+.[0-9]+)\"" _ "${foo}")
set(XDGDIRS_VER "${CMAKE_MATCH_1}")

project(libXDGdirs
  VERSION "${XDGDIRS_VER}"
  LANGUAGES C)

set(XDGDIRS "XDGdirs")

set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/static)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/dynamic)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(NOT EXISTS "${CMAKE_SOURCE_DIR}/compile_commands.json")
  file(RELATIVE_PATH buildRelPath "${CMAKE_SOURCE_DIR}" "${CMAKE_BINARY_DIR}")
  execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink
    "${buildRelPath}/compile_commands.json"
    "${CMAKE_SOURCE_DIR}/compile_commands.json")
endif()

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS_DEBUG   "-O0 -g -Wall -Wextra -Wpedantic -DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")

add_subdirectory(src/)
add_subdirectory(docs/)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  include(CTest)
  add_subdirectory(tests/)
  add_subdirectory(examples/)
endif()

install(TARGETS "${XDGDIRS}")
