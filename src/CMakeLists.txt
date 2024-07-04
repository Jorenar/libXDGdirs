set(CMAKE_C_OUTPUT_EXTENSION_REPLACE YES)
add_library("${XDGDIRS}" STATIC xdgdirs.c)

add_custom_target(version
  ${CMAKE_COMMAND}
  -D SRC=${CMAKE_CURRENT_SOURCE_DIR}/xdgdirs_ver.h.in
  -D DST=${CMAKE_CURRENT_SOURCE_DIR}/xdgdirs_ver.h
  -P ${CMAKE_CURRENT_SOURCE_DIR}/GenerateVersion.cmake
)
add_dependencies(${XDGDIRS} version)

set_target_properties("${XDGDIRS}" PROPERTIES PUBLIC_HEADER "src/xdgdirs.h")
set_target_properties("${XDGDIRS}" PROPERTIES PUBLIC_HEADER "src/xdgdirs_ver.h")
