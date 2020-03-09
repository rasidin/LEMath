#include "gtest/gtest.h"

#include "LEMathCommon.h"
#include "LEFloatVector2.h"
#include "LEFloatVector3.h"
#include "LEFloatVector4.h"
#include "LEQuaternion.h"
#include "LEIntVector2.h"
#include "LEIntVector3.h"
#include "LEIntVector4.h"
#include "LEFloatMatrix4x4.h"

#define EXPECT_MATRIX_NEAR(a, b)\
	EXPECT_NEAR(a.Get(0,0), b.Get(0,0), 1.0e-06);\
	EXPECT_NEAR(a.Get(0,1), b.Get(0,1), 1.0e-06);\
	EXPECT_NEAR(a.Get(0,2), b.Get(0,2), 1.0e-06);\
	EXPECT_NEAR(a.Get(0,3), b.Get(0,3), 1.0e-06);\
	EXPECT_NEAR(a.Get(1,0), b.Get(1,0), 1.0e-06);\
	EXPECT_NEAR(a.Get(1,1), b.Get(1,1), 1.0e-06);\
	EXPECT_NEAR(a.Get(1,2), b.Get(1,2), 1.0e-06);\
	EXPECT_NEAR(a.Get(1,3), b.Get(1,3), 1.0e-06);\
	EXPECT_NEAR(a.Get(2,0), b.Get(2,0), 1.0e-06);\
	EXPECT_NEAR(a.Get(2,1), b.Get(2,1), 1.0e-06);\
	EXPECT_NEAR(a.Get(2,2), b.Get(2,2), 1.0e-06);\
	EXPECT_NEAR(a.Get(2,3), b.Get(2,3), 1.0e-06);\
	EXPECT_NEAR(a.Get(3,0), b.Get(3,0), 1.0e-06);\
	EXPECT_NEAR(a.Get(3,1), b.Get(3,1), 1.0e-06);\
	EXPECT_NEAR(a.Get(3,2), b.Get(3,2), 1.0e-06);\
	EXPECT_NEAR(a.Get(3,3), b.Get(3,3), 1.0e-06);

#define EXPECT_VECTOR4_NEAR(a, b)\
	EXPECT_NEAR(a.X(), b.X(), 1.0e-06);\
	EXPECT_NEAR(a.Y(), b.Y(), 1.0e-06);\
	EXPECT_NEAR(a.Z(), b.Z(), 1.0e-06);\
	EXPECT_NEAR(a.W(), b.W(), 1.0e-06);

class testLEMath : public ::testing::Test{};
TEST_F(testLEMath, FloatVector4) {
	LEMath::FloatVector4 testFloatVector4_0(1.0f, 2.0f, 4.0f, 8.0f);
	LEMath::FloatVector4 testFloatVector4_1(2.0f, 4.0f, 8.0f, 1.0f);
	
	LEMath::FloatVector4 resultPlus(3.0f, 6.0f, 12.0f, 9.0f);
	LEMath::FloatVector4 resultMinus(-1.0f, -2.0f, -4.0f, 7.0f);
	LEMath::FloatVector4 resultMultiply(2.0f, 8.0f, 32.0f, 8.0f);
	LEMath::FloatVector4 resultMultiplyTwo(2.0f, 4.0f, 8.0f, 16.0f);
	LEMath::FloatVector4 resultDivide(0.5f, 0.5f, 0.5f, 8.0f);
	LEMath::FloatVector4 resultDivideTwo(0.5f, 1.0f, 2.0f, 4.0f);
	LEMath::FloatVector4 resultCross = LEMath::FloatVector4::Zero;
	float resultDot = 50.0f;
	float resultLength = sqrtf(1.0f + 4.0f + 16.0f + 64.0f);
	LEMath::FloatVector4 resultNormalize(1.0f / resultLength, 2.0f / resultLength, 4.0f / resultLength, 8.0f / resultLength);
	
	LEMath::FloatVector2 castResultFloatVector2(1.0f, 2.0f);
	LEMath::FloatVector3 castResultFloatVector3(1.0f, 2.0f, 4.0f);
	LEMath::IntVector2 castResultIntVector2(1, 2);
	LEMath::IntVector3 castResultIntVector3(1, 2, 4);
	LEMath::IntVector4 castResultIntVector4(1, 2, 4, 8);

	LEMath::FloatVector2 castFloatVector2(testFloatVector4_0.ToFloatVector2());
	LEMath::FloatVector3 castFloatVector3(testFloatVector4_0.ToFloatVector3());
	LEMath::IntVector2   castIntVector2  (testFloatVector4_0.ToIntVector2());
	LEMath::IntVector3   castIntVector3  (testFloatVector4_0.ToIntVector3());
	LEMath::IntVector4   castIntVector4  (testFloatVector4_0.ToIntVector4());
		
	EXPECT_EQ(resultPlus,     	testFloatVector4_0 + testFloatVector4_1);
	EXPECT_EQ(resultMinus,    	testFloatVector4_0 - testFloatVector4_1);
	EXPECT_EQ(resultMultiply, 	testFloatVector4_0 * testFloatVector4_1);
	EXPECT_EQ(resultMultiplyTwo,testFloatVector4_0 * 2.0f);
	EXPECT_EQ(resultDivide,   	testFloatVector4_0 / testFloatVector4_1);
	EXPECT_EQ(resultDivideTwo,  testFloatVector4_0 / 2.0f);
	EXPECT_EQ(resultCross,    	testFloatVector4_0 ^ testFloatVector4_1);
	EXPECT_EQ(resultDot,      	testFloatVector4_0 | testFloatVector4_1);
	EXPECT_EQ(resultLength,	  	testFloatVector4_0.Length());
	EXPECT_EQ(resultNormalize,	testFloatVector4_0.Normalize());
	
	EXPECT_EQ(castResultFloatVector2, castFloatVector2);
	EXPECT_EQ(castResultFloatVector3, castFloatVector3);
	EXPECT_EQ(castResultIntVector2,   castIntVector2  );
	EXPECT_EQ(castResultIntVector3,   castIntVector3  );
	EXPECT_EQ(castResultIntVector4,   castIntVector4  );
}

TEST_F(testLEMath, IntVector3) {
	LEMath::IntVector3 testIntVector3_0(10, 20, 40);
	LEMath::IntVector3 testIntVector3_1(2, 5, 8);
	
	LEMath::IntVector3 resultPlus(12, 25, 48);
	LEMath::IntVector3 resultMinus(8, 15, 32);
	LEMath::IntVector3 resultMultiply(20, 100, 320);
	LEMath::IntVector3 resultDivide(5, 4, 5);
	
	EXPECT_EQ(resultPlus, testIntVector3_0 + testIntVector3_1);
	EXPECT_EQ(resultMinus, testIntVector3_0 - testIntVector3_1);
	EXPECT_EQ(resultMultiply, testIntVector3_0 * testIntVector3_1);
	EXPECT_EQ(resultDivide, testIntVector3_0 / testIntVector3_1);	
}

TEST_F(testLEMath, IntVector4) {
	LEMath::IntVector4 testIntVector4_0(10, 20, 40, 60);
	LEMath::IntVector4 testIntVector4_1(2, 5, 8, 6);
		
	LEMath::IntVector4 resultPlus(12, 25, 48, 66);
	LEMath::IntVector4 resultMinus(8, 15, 32, 54);
	LEMath::IntVector4 resultMultiply(20, 100, 320, 360);
	LEMath::IntVector4 resultDivide(5, 4, 5, 10);
	
	EXPECT_EQ(resultPlus, testIntVector4_0 + testIntVector4_1);
	EXPECT_EQ(resultMinus, testIntVector4_0 - testIntVector4_1);
	EXPECT_EQ(resultMultiply, testIntVector4_0 * testIntVector4_1);
	EXPECT_EQ(resultDivide, testIntVector4_0 / testIntVector4_1);
}

TEST_F(testLEMath, Quaternion) {
	const LEMath::Quaternion testQuaternion_RotationY(LEMath::FloatVector4(0.0f, 1.0f, 0.0f, 1.0f), DEGREE2RADIAN(-90.0f));
	
	const LEMath::FloatVector4 testRotationY = testQuaternion_RotationY.Translate(LEMath::FloatVector4(1.0f, 0.0f, 0.0f, 1.0f));
	const LEMath::FloatVector4 resultRotationY(0.0f, 0.0f, 1.0f, 1.0f);
	const LEMath::FloatVector4 testRotationY2 = (testQuaternion_RotationY + testQuaternion_RotationY).Translate(LEMath::FloatVector4(1.0f, 0.0f, 0.0f, 1.0f));
	const LEMath::FloatVector4 resultRotationY2(-1.0f, 0.0f, 0.0f, 1.0f);
	
	EXPECT_VECTOR4_NEAR(resultRotationY, testRotationY);
	EXPECT_VECTOR4_NEAR(resultRotationY2, testRotationY2);
}

TEST_F(testLEMath, FloatMatrix4x4) {
	const LEMath::FloatMatrix4x4 testFloatMatrix4x4_0(
		 1.0f, 1.0f, 1.0f,-1.0f,
		 1.0f, 1.0f,-1.0f, 1.0f,
		 1.0f,-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f, 1.0f
	);
	const LEMath::FloatMatrix4x4 testFloatMatrix4x4_1(
		 0.0f, 1.0f, 2.0f, 3.0f,
		 4.0f, 5.0f, 6.0f, 7.0f,
		 8.0f, 9.0f,10.0f,11.0f,
		12.0f,13.0f,14.0f,15.0f
	);
	const LEMath::FloatVector4 testFloatVector4_0(1.0f, 2.0f, 3.0f, 1.0f);
	const LEMath::FloatVector4 testFloatVector4_X(1.0f, 0.0f, 0.0f, 1.0f);
	const LEMath::FloatVector4 testFloatVector4_Y(0.0f, 1.0f, 0.0f, 1.0f);
	const LEMath::FloatVector4 testFloatVector4_Z(0.0f, 0.0f, 1.0f, 1.0f);
	const LEMath::FloatMatrix4x4 testFloatMatrix4x4_Transform = LEMath::FloatMatrix4x4::GenerateTransform(testFloatVector4_0);
	const LEMath::FloatMatrix4x4 testFloatMatrix4x4_Scaling = LEMath::FloatMatrix4x4::GenerateScaling(2.0f, 3.0f, 4.0f);
	const LEMath::FloatMatrix4x4 testFloatMatrix4x4_RotationX = LEMath::FloatMatrix4x4::GenerateRotationX(-LEMath::LEMath_PI * 0.5f);
	const LEMath::FloatMatrix4x4 testFloatMatrix4x4_RotationY = LEMath::FloatMatrix4x4::GenerateRotationY(-LEMath::LEMath_PI * 0.5f);
	const LEMath::FloatMatrix4x4 testFloatMatrix4x4_RotationZ = LEMath::FloatMatrix4x4::GenerateRotationZ(-LEMath::LEMath_PI * 0.5f);
	
	const float resultDeterminant = -16.0f;
	const LEMath::FloatMatrix4x4 resultInverse(
		 0.25f, 0.25f, 0.25f,-0.25f,
		 0.25f, 0.25f,-0.25f, 0.25f,
		 0.25f,-0.25f, 0.25f, 0.25f,
		-0.25f, 0.25f, 0.25f, 0.25f
	);
	const LEMath::FloatMatrix4x4 resultTranspose(
		 0.0f, 4.0f, 8.0f,12.0f,
		 1.0f, 5.0f, 9.0f,13.0f,
		 2.0f, 6.0f,10.0f,14.0f,
		 3.0f, 7.0f,11.0f,15.0f
	);
	const LEMath::FloatMatrix4x4 resultScaling(
		 2.0f, 0.0f, 0.0f, 0.0f,
		 0.0f, 3.0f, 0.0f, 0.0f,
		 0.0f, 0.0f, 4.0f, 0.0f,
		 0.0f, 0.0f, 0.0f, 1.0f
	);
	const LEMath::FloatMatrix4x4 resultRotationX(
		 1.0f, 0.0f, 0.0f, 0.0f,
		 0.0f, 0.0f, 1.0f, 0.0f,
		 0.0f,-1.0f, 0.0f, 0.0f,
		 0.0f, 0.0f, 0.0f, 1.0f
	);
	const LEMath::FloatMatrix4x4 resultRotationY(
		 0.0f, 0.0f,-1.0f, 0.0f,
		 0.0f, 1.0f, 0.0f, 0.0f,
		 1.0f, 0.0f, 0.0f, 0.0f,
		 0.0f, 0.0f, 0.0f, 1.0f
	);
	const LEMath::FloatMatrix4x4 resultRotationZ(
		 0.0f, 1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f, 0.0f,
		 0.0f, 0.0f, 1.0f, 0.0f,
		 0.0f, 0.0f, 0.0f, 1.0f
	);
	const LEMath::FloatVector4 resultTransform(2.0f, 4.0f, 6.0f, 1.0f);
	const LEMath::FloatVector4 resultRotationTransformedX(0.0f, 0.0f, 1.0f, 1.0f);
	const LEMath::FloatVector4 resultRotationTransformedY(1.0f, 0.0f, 0.0f, 1.0f);
	const LEMath::FloatVector4 resultRotationTransformedZ(0.0f, 1.0f, 0.0f, 1.0f);
	
	const LEMath::FloatMatrix4x4 testInverse = testFloatMatrix4x4_0.Inverse();
	const LEMath::FloatVector4 testRotationX = testFloatMatrix4x4_RotationX.Translate(testFloatVector4_Y);
	const LEMath::FloatVector4 testRotationY = testFloatMatrix4x4_RotationY.Translate(testFloatVector4_Z);
	const LEMath::FloatVector4 testRotationZ = testFloatMatrix4x4_RotationZ.Translate(testFloatVector4_X);

	EXPECT_EQ(          resultDeterminant,          testFloatMatrix4x4_0.Determinant());
	EXPECT_EQ(          resultTransform,            testFloatMatrix4x4_Transform.Translate(testFloatVector4_0));
	EXPECT_EQ(          resultTranspose,            testFloatMatrix4x4_1.Transpose());
	EXPECT_MATRIX_NEAR( resultInverse,              testInverse);
	EXPECT_MATRIX_NEAR( resultScaling,              testFloatMatrix4x4_Scaling);
	EXPECT_MATRIX_NEAR( resultRotationX,            testFloatMatrix4x4_RotationX);
	EXPECT_MATRIX_NEAR( resultRotationY,            testFloatMatrix4x4_RotationY);
	EXPECT_MATRIX_NEAR( resultRotationZ,            testFloatMatrix4x4_RotationZ);
	EXPECT_VECTOR4_NEAR(resultRotationTransformedX, testRotationX);
	EXPECT_VECTOR4_NEAR(resultRotationTransformedY, testRotationY);
	EXPECT_VECTOR4_NEAR(resultRotationTransformedZ, testRotationZ);
}

TEST_F(testLEMath, PerformanceCheck) {
	const LEMath::FloatVector4 testFloatVector4_0(1.0f, 2.0f, 3.0f, 1.0f);
	const LEMath::FloatMatrix4x4 testFloatMatrix4x4_0 = LEMath::FloatMatrix4x4::GenerateTransform(10.0f, 50.0f, 120.0f) * LEMath::FloatMatrix4x4::GenerateScaling(LEMath::FloatVector4(2.0f, 3.0f, 4.0f, 1.0f));
	const LEMath::FloatMatrix4x4 testFloatMatrix4x4_1 = testFloatMatrix4x4_0.Inverse();
	
#ifdef LEMATH_TEST_VERBOSE
	std::cout << "testFloatMatrix4x4_0" << std::endl;
	testFloatMatrix4x4_0.PrintLog();
	std::cout << "testFloatMatrix4x4_1" << std::endl;
	testFloatMatrix4x4_1.PrintLog();
#endif

	static constexpr uint32_t ComputingCount = 1000000;
	LEMath::FloatVector4 result = testFloatVector4_0;
	for (uint32_t count=0;count<ComputingCount;count++) {
		result = testFloatMatrix4x4_0.Translate(result);
		result = testFloatMatrix4x4_1 * result;
#ifdef LEMATH_TEST_VERBOSE
		std::cout << result.X() << "," << result.Y() << "," << result.Z() << std::endl;
#endif
	}
	EXPECT_VECTOR4_NEAR(result, testFloatVector4_0);
}