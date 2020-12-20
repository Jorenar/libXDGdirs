set(CMAKE_C_OUTPUT_EXTENSION_REPLACE YES)
add_library("${LIB_NAME}" STATIC xdgdirs.c)
set_target_properties("${LIB_NAME}" PROPERTIES PUBLIC_HEADER "src/xdgdirs.h")
