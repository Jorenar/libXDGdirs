set(CMAKE_C_OUTPUT_EXTENSION_REPLACE YES)
add_library("${XDGDIRS}" STATIC xdgdirs.c)
set_target_properties("${XDGDIRS}" PROPERTIES PUBLIC_HEADER "src/xdgdirs.h")
