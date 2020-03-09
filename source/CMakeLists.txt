add_library(LEMath STATIC 
	LEIntVector2.cpp
	LEIntVector3.cpp
	LEIntVector4.cpp 
	LEFloatVector2.cpp
	LEFloatVector3.cpp
	LEFloatVector4.cpp 
	LEQuaternion.cpp 
	LEFloatMatrix4x4.cpp)

target_include_directories(LEMath PUBLIC ${PROJECT_SOURCE_DIR}/include)