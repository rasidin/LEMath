cmake_minimum_required(VERSION 3.1)

set(GTEST_WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download")
file(REMOVE "${GTEST_WORKING_DIRECTORY}/CMakeCache.txt")
configure_file("${CMAKE_SOURCE_DIR}/googletest.cmake" "${GTEST_WORKING_DIRECTORY}/CMakeLists.txt")
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" -D "CMAKE_MAKE_PROGRAM:FILE=${CMAKE_MAKE_PROGRAM}" .
						WORKING_DIRECTORY "${GTEST_WORKING_DIRECTORY}")
execute_process(COMMAND ${CMAKE_COMMAND} --build .
						WORKING_DIRECTORY "${GTEST_WORKING_DIRECTORY}")

set(GTEST_SOURCE_DIR ${CMAKE_BINARY_DIR}/googletest-src)
set(GTEST_BINARY_DIR ${CMAKE_BINARY_DIR}/googletest-download)

add_subdirectory(${GTEST_SOURCE_DIR} ${GTEST_BINARY_DIR})

include(CTest)

add_executable(LEMathTest test.cpp)
target_link_libraries(LEMathTest LEMath gtest gmock_main)
include_directories(${PROJECT_SOURCE_DIR}/source)

add_test(NAME test COMMAND LEMathTest)
