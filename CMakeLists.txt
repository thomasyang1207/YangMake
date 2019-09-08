cmake_minimum_required(VERSION 2.6)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")
project(ym)

file(GLOB_RECURSE TESTCASES test/*.cc)

add_executable(yangMake src/main.cc)
add_executable(testYangMake test/test.cc ${TESTCASES})

target_include_directories(yangMake PRIVATE src)
target_include_directories(testYangMake PRIVATE src test)

target_link_libraries(testYangMake gtest gtest_main pthread)
