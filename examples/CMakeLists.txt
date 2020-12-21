include_directories(${PROJECT_SOURCE_DIR}/src)

file(GLOB sources RELATIVE ${PROJECT_SOURCE_DIR}/examples *.c)
foreach(source ${sources})
  string(REPLACE ".c" "" bin ${source})
  add_executable(${bin} ${source})
  target_link_libraries(${bin} ${XDGDIRS})
endforeach()
