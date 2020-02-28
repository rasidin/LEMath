cmake_minimum_required(VERSION 3.1)
project(LEMath)
enable_testing()

add_subdirectory(source)
option(USE_TEST "Use gtest" OFF)
if(USE_TEST)
	add_subdirectory(test)
endif()