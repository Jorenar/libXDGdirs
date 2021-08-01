include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(test_bin test.c)
target_link_libraries(test_bin ${XDGDIRS})

file(GLOB ins RELATIVE ${PROJECT_SOURCE_DIR}/tests "test[0-9]*")

foreach(in ${ins})
  add_test(
    NAME "${in}"
    COMMAND sh ./${in} ${PROJECT_BINARY_DIR}/bin/test_bin
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tests)
endforeach()
