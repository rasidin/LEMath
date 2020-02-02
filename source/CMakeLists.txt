add_library(LEMath STATIC LEIntVector4.cpp LEFloatVector4.cpp LEQuaternion.cpp LEFloatMatrix4x4.cpp)

target_include_directories(LEMath PUBLIC ${PROJECT_SOURCE_DIR}/include)