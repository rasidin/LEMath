cmake_minimum_required(VERSION 3.1)
cmake_policy(SET CMP0002 OLD)

project(LEMath)
enable_testing()

option(USE_TEST "Use gtest" OFF)
if(USE_TEST)
	add_subdirectory(test)
endif()

add_library(LEMath STATIC 
	source/LEIntVector2.cpp
	source/LEIntVector3.cpp
	source/LEIntVector4.cpp 
	source/LEFloatVector2.cpp
	source/LEFloatVector3.cpp
	source/LEFloatVector4.cpp 
	source/LEHalfVector2.cpp
	source/LEHalfVector4.cpp
	source/LEQuaternion.cpp 
	source/LEFloatMatrix4x4.cpp)

target_include_directories(LEMath PUBLIC ${PROJECT_SOURCE_DIR}/include)

install(TARGETS LEMath
		ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
		LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)