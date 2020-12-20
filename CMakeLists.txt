cmake_minimum_required(VERSION 3.16)

project(libXDGdirs
  VERSION 1.0.0
  LANGUAGES C)

set(LIB_NAME "XDGdirs")

add_definitions(-DXDGDIRS_VER="${CMAKE_PROJECT_VERSION}")

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

set(CMAKE_C_FLAGS_DEBUG   "-O0 -g -Wall -Wextra -pedantic -DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")

add_subdirectory(src/)
add_subdirectory(docs/)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_subdirectory(examples/)
endif()

install(
  TARGETS              "${LIB_NAME}"
  EXPORT               "${TARGETS_EXPORT_NAME}"
  LIBRARY DESTINATION  "${CMAKE_INSTALL_LIBDIR}"
  ARCHIVE DESTINATION  "${CMAKE_INSTALL_LIBDIR}"
  RUNTIME DESTINATION  "${CMAKE_INSTALL_BINDIR}"
  INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
  )
