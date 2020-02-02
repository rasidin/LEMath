// ===========================================================
// LEFloatMatrix4x4.h
// @brief Float Matrix 4x4
// @author minseob
#include <iostream>
#include <memory.h>

#include "LEFloatMatrix4x4.h"

namespace LEMath {
	// Default value
	const FloatMatrix4x4 FloatMatrix4x4::Zero = FloatMatrix4x4(
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	);
	const FloatMatrix4x4 FloatMatrix4x4::One = FloatMatrix4x4(
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f
	);
	const FloatMatrix4x4 FloatMatrix4x4::Identity = FloatMatrix4x4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	
	// Constructors
	FloatMatrix4x4::FloatMatrix4x4() {
		memset(&m16[0], 0, sizeof(float) * 16);
	}
	FloatMatrix4x4::FloatMatrix4x4(const float *In) {
		memcpy(&m16[0], In, sizeof(float) * 16);
	}
	FloatMatrix4x4::FloatMatrix4x4(
		const FloatVector4 &Row0, 
		const FloatVector4 &Row1, 
		const FloatVector4 &Row2, 
		const FloatVector4 &Row3) {
		row[0] = Row0;
		row[1] = Row1;
		row[2] = Row2;
		row[3] = Row3;
	}
	FloatMatrix4x4::FloatMatrix4x4(
		float M00, float M01, float M02, float M03, 
		float M10, float M11, float M12, float M13, 
		float M20, float M21, float M22, float M23, 
		float M30, float M31, float M32, float M33) {
		m4x4[0][0] = M00;
		m4x4[0][1] = M01;
		m4x4[0][2] = M02;
		m4x4[0][3] = M03;
		m4x4[1][0] = M10;
		m4x4[1][1] = M11;
		m4x4[1][2] = M12;
		m4x4[1][3] = M13;
		m4x4[2][0] = M20;
		m4x4[2][1] = M21;
		m4x4[2][2] = M22;
		m4x4[2][3] = M23;
		m4x4[3][0] = M30;
		m4x4[3][1] = M31;
		m4x4[3][2] = M32;
		m4x4[3][3] = M33;
	}
	FloatMatrix4x4::FloatMatrix4x4(float In) {
		m16[ 0] = In; m16[ 1] = In; m16[ 2] = In; m16[ 3] = In;
		m16[ 4] = In; m16[ 5] = In; m16[ 6] = In; m16[ 7] = In;
		m16[ 8] = In; m16[ 9] = In; m16[10] = In; m16[11] = In;
		m16[12] = In; m16[13] = In; m16[14] = In; m16[15] = In;
	}
	
	float FloatMatrix4x4::Determinant() const {
		float Det0 = m4x4[1][1] * (m4x4[2][2] * m4x4[3][3] - m4x4[2][3] * m4x4[3][2]) - m4x4[1][2] * (m4x4[2][1] * m4x4[3][3] - m4x4[2][3] * m4x4[3][1]) + m4x4[1][3] * (m4x4[2][1] * m4x4[3][2] - m4x4[2][2] * m4x4[3][1]);
		float Det1 = m4x4[1][0] * (m4x4[2][2] * m4x4[3][3] - m4x4[2][3] * m4x4[3][2]) - m4x4[1][2] * (m4x4[2][0] * m4x4[3][3] - m4x4[2][3] * m4x4[3][0]) + m4x4[1][3] * (m4x4[2][0] * m4x4[3][2] - m4x4[2][2] * m4x4[3][0]);
		float Det2 = m4x4[1][0] * (m4x4[2][1] * m4x4[3][3] - m4x4[2][3] * m4x4[3][1]) - m4x4[1][1] * (m4x4[2][0] * m4x4[3][3] - m4x4[2][3] * m4x4[3][0]) + m4x4[1][3] * (m4x4[2][0] * m4x4[3][1] - m4x4[2][1] * m4x4[3][0]);
		float Det3 = m4x4[1][0] * (m4x4[2][1] * m4x4[3][2] - m4x4[2][2] * m4x4[3][1]) - m4x4[1][1] * (m4x4[2][0] * m4x4[3][2] - m4x4[2][2] * m4x4[3][0]) + m4x4[1][2] * (m4x4[2][0] * m4x4[3][1] - m4x4[2][1] * m4x4[3][0]);
		
		return m4x4[0][0] * Det0 - m4x4[0][1] * Det1 + m4x4[0][2] * Det2 - m4x4[0][3] * Det3;
	}
	
	FloatMatrix4x4 FloatMatrix4x4::Inverse() const {
		FloatMatrix4x4 DetMatrix;

		DetMatrix.Set(0, 0,  m4x4[1][1] * (m4x4[2][2] * m4x4[3][3] - m4x4[2][3] * m4x4[3][2]) - m4x4[1][2] * (m4x4[2][1] * m4x4[3][3] - m4x4[2][3] * m4x4[3][1]) + m4x4[1][3] * (m4x4[2][1] * m4x4[3][2] - m4x4[2][2] * m4x4[3][1]));
		DetMatrix.Set(0, 1,-(m4x4[1][0] * (m4x4[2][2] * m4x4[3][3] - m4x4[2][3] * m4x4[3][2]) - m4x4[1][2] * (m4x4[2][0] * m4x4[3][3] - m4x4[2][3] * m4x4[3][0]) + m4x4[1][3] * (m4x4[2][0] * m4x4[3][2] - m4x4[2][2] * m4x4[3][0])));
		DetMatrix.Set(0, 2,  m4x4[1][0] * (m4x4[2][1] * m4x4[3][3] - m4x4[2][3] * m4x4[3][1]) - m4x4[1][1] * (m4x4[2][0] * m4x4[3][3] - m4x4[2][3] * m4x4[3][0]) + m4x4[1][3] * (m4x4[2][0] * m4x4[3][1] - m4x4[2][1] * m4x4[3][0]));
		DetMatrix.Set(0, 3,-(m4x4[1][0] * (m4x4[2][1] * m4x4[3][2] - m4x4[2][2] * m4x4[3][1]) - m4x4[1][1] * (m4x4[2][0] * m4x4[3][2] - m4x4[2][2] * m4x4[3][0]) + m4x4[1][2] * (m4x4[2][0] * m4x4[3][1] - m4x4[2][1] * m4x4[3][0])));
		
		DetMatrix.Set(1, 0,-(m4x4[0][1] * (m4x4[2][2] * m4x4[3][3] - m4x4[2][3] * m4x4[3][2]) - m4x4[0][2] * (m4x4[2][1] * m4x4[3][3] - m4x4[2][3] * m4x4[3][1]) + m4x4[0][3] * (m4x4[2][1] * m4x4[3][2] - m4x4[2][2] * m4x4[3][1])));
		DetMatrix.Set(1, 1,  m4x4[0][0] * (m4x4[2][2] * m4x4[3][3] - m4x4[2][3] * m4x4[3][2]) - m4x4[0][2] * (m4x4[2][0] * m4x4[3][3] - m4x4[2][3] * m4x4[3][0]) + m4x4[0][3] * (m4x4[2][0] * m4x4[3][2] - m4x4[2][2] * m4x4[3][0]));
		DetMatrix.Set(1, 2,-(m4x4[0][0] * (m4x4[2][1] * m4x4[3][3] - m4x4[2][3] * m4x4[3][1]) - m4x4[0][1] * (m4x4[2][0] * m4x4[3][3] - m4x4[2][3] * m4x4[3][0]) + m4x4[0][3] * (m4x4[2][0] * m4x4[3][1] - m4x4[2][1] * m4x4[3][0])));
		DetMatrix.Set(1, 3,  m4x4[0][0] * (m4x4[2][1] * m4x4[3][2] - m4x4[2][2] * m4x4[3][1]) - m4x4[0][1] * (m4x4[2][0] * m4x4[3][2] - m4x4[2][2] * m4x4[3][0]) + m4x4[0][2] * (m4x4[2][0] * m4x4[3][1] - m4x4[2][1] * m4x4[3][0]));
		
		DetMatrix.Set(2, 0,  m4x4[0][1] * (m4x4[1][2] * m4x4[3][3] - m4x4[1][3] * m4x4[3][2]) - m4x4[0][2] * (m4x4[1][1] * m4x4[3][3] - m4x4[1][3] * m4x4[3][1]) + m4x4[0][3] * (m4x4[1][1] * m4x4[3][2] - m4x4[1][2] * m4x4[3][1]));
		DetMatrix.Set(2, 1,-(m4x4[0][0] * (m4x4[1][2] * m4x4[3][3] - m4x4[1][3] * m4x4[3][2]) - m4x4[0][2] * (m4x4[1][0] * m4x4[3][3] - m4x4[1][3] * m4x4[3][0]) + m4x4[0][3] * (m4x4[1][0] * m4x4[3][2] - m4x4[1][2] * m4x4[3][0])));
		DetMatrix.Set(2, 2,  m4x4[0][0] * (m4x4[1][1] * m4x4[3][3] - m4x4[1][3] * m4x4[3][1]) - m4x4[0][1] * (m4x4[1][0] * m4x4[3][3] - m4x4[1][3] * m4x4[3][0]) + m4x4[0][3] * (m4x4[1][0] * m4x4[3][1] - m4x4[1][1] * m4x4[3][0]));
		DetMatrix.Set(2, 3,-(m4x4[0][0] * (m4x4[1][1] * m4x4[3][2] - m4x4[1][2] * m4x4[3][1]) - m4x4[0][1] * (m4x4[1][0] * m4x4[3][2] - m4x4[1][2] * m4x4[3][0]) + m4x4[0][2] * (m4x4[1][0] * m4x4[3][1] - m4x4[1][1] * m4x4[3][0])));
		
		DetMatrix.Set(3, 0,-(m4x4[0][1] * (m4x4[1][2] * m4x4[2][3] - m4x4[1][3] * m4x4[2][2]) - m4x4[0][2] * (m4x4[1][1] * m4x4[2][3] - m4x4[1][3] * m4x4[2][1]) + m4x4[0][3] * (m4x4[1][1] * m4x4[2][3] - m4x4[1][2] * m4x4[2][1])));
		DetMatrix.Set(3, 1,  m4x4[0][0] * (m4x4[1][2] * m4x4[2][3] - m4x4[1][3] * m4x4[2][2]) - m4x4[0][2] * (m4x4[1][0] * m4x4[2][3] - m4x4[1][3] * m4x4[2][0]) + m4x4[0][3] * (m4x4[1][0] * m4x4[2][3] - m4x4[1][2] * m4x4[2][0]));
		DetMatrix.Set(3, 2,-(m4x4[0][0] * (m4x4[1][1] * m4x4[2][3] - m4x4[1][3] * m4x4[2][1]) - m4x4[0][1] * (m4x4[1][0] * m4x4[2][3] - m4x4[1][3] * m4x4[2][0]) + m4x4[0][3] * (m4x4[1][0] * m4x4[2][1] - m4x4[1][1] * m4x4[2][0])));
		DetMatrix.Set(3, 3,  m4x4[0][0] * (m4x4[1][1] * m4x4[2][2] - m4x4[1][2] * m4x4[2][1]) - m4x4[0][1] * (m4x4[1][0] * m4x4[2][2] - m4x4[1][2] * m4x4[2][0]) + m4x4[0][2] * (m4x4[1][0] * m4x4[2][1] - m4x4[1][1] * m4x4[2][0]));
		
		float Determinant = m4x4[0][0] * DetMatrix.Get(0, 0) + m4x4[0][1] * DetMatrix.Get(0, 1) + m4x4[0][2] * DetMatrix.Get(0, 2) + m4x4[0][3] * DetMatrix.Get(0, 3);
		DetMatrix /= Determinant;
		
		return DetMatrix;
	}
	FloatMatrix4x4 FloatMatrix4x4::Transpose() const {
		return FloatMatrix4x4(
			m4x4[0][0], m4x4[1][0], m4x4[2][0], m4x4[3][0],
			m4x4[0][1], m4x4[1][1], m4x4[2][1], m4x4[3][1],
			m4x4[0][2], m4x4[1][2], m4x4[2][2], m4x4[3][2],
			m4x4[0][3], m4x4[1][3], m4x4[2][3], m4x4[3][3]
		);
	}
	
	FloatVector4 FloatMatrix4x4::Translate(const FloatVector4 &In) const {
		return FloatVector4(
		In.X() * m4x4[0][0] + In.Y() * m4x4[1][0] + In.Z() * m4x4[2][0] + In.W() * m4x4[3][0],
		In.X() * m4x4[0][1] + In.Y() * m4x4[1][1] + In.Z() * m4x4[2][1] + In.W() * m4x4[3][1],
		In.X() * m4x4[0][2] + In.Y() * m4x4[1][2] + In.Z() * m4x4[2][2] + In.W() * m4x4[3][2],
		In.X() * m4x4[0][3] + In.Y() * m4x4[1][3] + In.Z() * m4x4[2][3] + In.W() * m4x4[3][3]
		);
	}
	
	// Generators
	FloatMatrix4x4 FloatMatrix4x4::GenerateViewMatrix(const FloatVector4 &Position, const FloatVector4 &Direction, const FloatVector4 &Up) {
		const FloatVector4 ZAxis = Direction;
		const FloatVector4 XAxis = (Up ^ ZAxis).Normalize();
		const FloatVector4 YAxis = ZAxis ^ XAxis;
		const FloatVector4 AxisPosition(-Position | XAxis, -Position | YAxis, -Position | ZAxis, 1.0f);
		return FloatMatrix4x4(
			       XAxis.X(),        YAxis.X(),        ZAxis.X(), 0.0f,
			       XAxis.Y(),        YAxis.Y(),        ZAxis.Y(), 0.0f,
			       XAxis.Z(),        YAxis.Z(),        ZAxis.Z(), 0.0f,
			AxisPosition.X(), AxisPosition.Y(), AxisPosition.Z(), 1.0f
		);
	}
	FloatMatrix4x4 FloatMatrix4x4::GenerateViewMatrix(const FloatVector4 &Position, const FloatVector4 &Rotation) {
		return GenerateTransform(-Position) * GenerateInverseRotationXYZ(Rotation);
	}
	FloatMatrix4x4 FloatMatrix4x4::GenerateRotationX(float RadianX) {
		float SinX = sinf(RadianX);
		float CosX = cosf(RadianX);
		return FloatMatrix4x4(
			 1.0f, 0.0f, 0.0f, 0.0f,
			 0.0f, CosX,-SinX, 0.0f,
			 0.0f, SinX, CosX, 0.0f,
			 0.0f, 0.0f, 0.0f, 1.0f);
	}
	FloatMatrix4x4 FloatMatrix4x4::GenerateRotationY(float RadianY) {
		float SinY = sinf(RadianY);
		float CosY = cosf(RadianY);
		return FloatMatrix4x4(
			 CosY, 0.0f, SinY, 0.0f,
			 0.0f, 1.0f, 0.0f, 0.0f,
			-SinY, 0.0f, CosY, 0.0f,
			 0.0f, 0.0f, 0.0f, 1.0f);
	}
	FloatMatrix4x4 FloatMatrix4x4::GenerateRotationZ(float RadianZ) {
		float SinZ = sinf(RadianZ);
		float CosZ = cosf(RadianZ);
		return FloatMatrix4x4(
			 CosZ,-SinZ, 0.0f, 0.0f,
			 SinZ, CosZ, 0.0f, 0.0f,
			 0.0f, 0.0f, 1.0f, 0.0f,
			 0.0f, 0.0f, 0.0f, 1.0f);
	}
	FloatMatrix4x4 FloatMatrix4x4::GenerateRotationXYZ(float RadianX, float RadianY, float RadianZ) {
		return GenerateRotationX(RadianX) * GenerateRotationY(RadianY) * GenerateRotationZ(RadianZ);
	}
	FloatMatrix4x4 FloatMatrix4x4::GenerateRotationXYZ(const FloatVector4 &Radian) {
		return GenerateRotationXYZ(Radian.X(), Radian.Y(), Radian.Z());
	}
	FloatMatrix4x4 FloatMatrix4x4::GenerateInverseRotationX(float RadianX) {
		float SinX = sinf(RadianX);
		float CosX = cosf(RadianX);
		return FloatMatrix4x4(
			 1.0f, 0.0f, 0.0f, 0.0f,
			 0.0f, CosX, SinX, 0.0f,
			 0.0f,-SinX, CosX, 0.0f,
			 0.0f, 0.0f, 0.0f, 1.0f);
	}
	FloatMatrix4x4 FloatMatrix4x4::GenerateInverseRotationY(float RadianY) {
		float SinY = sinf(RadianY);
		float CosY = cosf(RadianY);
		return FloatMatrix4x4(
			 CosY, 0.0f,-SinY, 0.0f,
			 0.0f, 1.0f, 0.0f, 0.0f,
			 SinY, 0.0f, CosY, 0.0f,
			 0.0f, 0.0f, 0.0f, 1.0f);
	}
	FloatMatrix4x4 FloatMatrix4x4::GenerateInverseRotationZ(float RadianZ) {
		float SinZ = sinf(RadianZ);
		float CosZ = cosf(RadianZ);
		return FloatMatrix4x4(
			 CosZ, SinZ, 0.0f, 0.0f,
			-SinZ, CosZ, 0.0f, 0.0f,
			 0.0f, 0.0f, 1.0f, 0.0f,
			 0.0f, 0.0f, 0.0f, 1.0f);
	}
	FloatMatrix4x4 FloatMatrix4x4::GenerateInverseRotationXYZ(float RadianX, float RadianY, float RadianZ) {
		return GenerateInverseRotationZ(RadianZ) * GenerateInverseRotationY(RadianY) * GenerateInverseRotationX(RadianX);
	}
	FloatMatrix4x4 FloatMatrix4x4::GenerateInverseRotationXYZ(const FloatVector4 &Radian) {
		return GenerateInverseRotationXYZ(Radian.X(), Radian.Y(), Radian.Z());
	}
	FloatMatrix4x4 FloatMatrix4x4::GenerateTransform(float X, float Y, float Z) {
		return FloatMatrix4x4(
			 1.0f, 0.0f, 0.0f, 0.0f,
			 0.0f, 1.0f, 0.0f, 0.0f,
			 0.0f, 0.0f, 1.0f, 0.0f,
			    X,    Y,    Z, 1.0f);
	}
	FloatMatrix4x4 FloatMatrix4x4::GenerateTransform(const FloatVector4 &In) {
		return GenerateTransform(In.X(), In.Y(), In.Z());
	}
	FloatMatrix4x4 FloatMatrix4x4::GenerateScaling(float X, float Y, float Z) {
		return FloatMatrix4x4(
			   X, 0.0f, 0.0f, 0.0f,
			0.0f,    Y, 0.0f, 0.0f,
			0.0f, 0.0f,    Z, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		);
	}
	FloatMatrix4x4 FloatMatrix4x4::GenerateScaling(const FloatVector4 &Scaling) {
		return GenerateScaling(Scaling.X(), Scaling.Y(), Scaling.Z());
	}
	
	// Operators
	bool FloatMatrix4x4::operator == (const FloatMatrix4x4 &In) const {
		return memcmp(this, &In, sizeof(float) * 16) == 0;
	}
	FloatMatrix4x4 FloatMatrix4x4::operator + (const FloatMatrix4x4 &In) const {
		return FloatMatrix4x4(
			m4x4[0][0] + In.Get(0, 0), m4x4[0][1] + In.Get(0, 1), m4x4[0][2] + In.Get(0, 2), m4x4[0][3] + In.Get(0, 3),
			m4x4[1][0] + In.Get(1, 0), m4x4[1][1] + In.Get(1, 1), m4x4[1][2] + In.Get(1, 2), m4x4[1][3] + In.Get(1, 3),
			m4x4[2][0] + In.Get(2, 0), m4x4[2][1] + In.Get(2, 1), m4x4[2][2] + In.Get(2, 2), m4x4[2][3] + In.Get(2, 3),
			m4x4[3][0] + In.Get(3, 0), m4x4[3][1] + In.Get(3, 1), m4x4[3][2] + In.Get(3, 2), m4x4[3][3] + In.Get(3, 3)
		);
	}
	FloatMatrix4x4& FloatMatrix4x4::operator += (const FloatMatrix4x4 &In) {
		m4x4[0][0] += In.Get(0, 0); m4x4[0][1] += In.Get(0, 1); m4x4[0][2] += In.Get(0, 2); m4x4[0][3] += In.Get(0, 3);
		m4x4[1][0] += In.Get(1, 0); m4x4[1][1] += In.Get(1, 1); m4x4[1][2] += In.Get(1, 2); m4x4[1][3] += In.Get(1, 3);
		m4x4[2][0] += In.Get(2, 0); m4x4[2][1] += In.Get(2, 1); m4x4[2][2] += In.Get(2, 2); m4x4[2][3] += In.Get(2, 3);
		m4x4[3][0] += In.Get(3, 0); m4x4[3][1] += In.Get(3, 1); m4x4[3][2] += In.Get(3, 2); m4x4[3][3] += In.Get(3, 3);
		return *this;
	}
	FloatMatrix4x4 FloatMatrix4x4::operator - (const FloatMatrix4x4 &In) const {
		return FloatMatrix4x4(
			m4x4[0][0] - In.Get(0, 0), m4x4[0][1] - In.Get(0, 1), m4x4[0][2] - In.Get(0, 2), m4x4[0][3] - In.Get(0, 3),
			m4x4[1][0] - In.Get(1, 0), m4x4[1][1] - In.Get(1, 1), m4x4[1][2] - In.Get(1, 2), m4x4[1][3] - In.Get(1, 3),
			m4x4[2][0] - In.Get(2, 0), m4x4[2][1] - In.Get(2, 1), m4x4[2][2] - In.Get(2, 2), m4x4[2][3] - In.Get(2, 3),
			m4x4[3][0] - In.Get(3, 0), m4x4[3][1] - In.Get(3, 1), m4x4[3][2] - In.Get(3, 2), m4x4[3][3] - In.Get(3, 3)
		);
	}
	FloatMatrix4x4& FloatMatrix4x4::operator -= (const FloatMatrix4x4 &In) {
		m16[ 0] -= In.Get(0, 0);
		m16[ 1] -= In.Get(0, 1);
		m16[ 2] -= In.Get(0, 2);
		m16[ 3] -= In.Get(0, 3);
		m16[ 4] -= In.Get(1, 0);
		m16[ 5] -= In.Get(1, 1);
		m16[ 6] -= In.Get(1, 2);
		m16[ 7] -= In.Get(1, 3);
		m16[ 8] -= In.Get(2, 0);
		m16[ 9] -= In.Get(2, 1);
		m16[10] -= In.Get(2, 2);
		m16[11] -= In.Get(2, 3);
		m16[12] -= In.Get(3, 0);
		m16[13] -= In.Get(3, 1);
		m16[14] -= In.Get(3, 2);
		m16[15] -= In.Get(3, 3);
		return *this;
	}
	FloatMatrix4x4 FloatMatrix4x4::operator *  (const FloatMatrix4x4 &In) const {
		return FloatMatrix4x4(
			m4x4[0][0] * In.Get(0, 0) + m4x4[0][1] * In.Get(1, 0) + m4x4[0][2] * In.Get(2, 0) + m4x4[0][3] * In.Get(3, 0),
			m4x4[0][0] * In.Get(0, 1) + m4x4[0][1] * In.Get(1, 1) + m4x4[0][2] * In.Get(2, 1) + m4x4[0][3] * In.Get(3, 1),
			m4x4[0][0] * In.Get(0, 2) + m4x4[0][1] * In.Get(1, 2) + m4x4[0][2] * In.Get(2, 2) + m4x4[0][3] * In.Get(3, 2),
			m4x4[0][0] * In.Get(0, 3) + m4x4[0][1] * In.Get(1, 3) + m4x4[0][2] * In.Get(2, 3) + m4x4[0][3] * In.Get(3, 3),
			m4x4[1][0] * In.Get(0, 0) + m4x4[1][1] * In.Get(1, 0) + m4x4[1][2] * In.Get(2, 0) + m4x4[1][3] * In.Get(3, 0),
			m4x4[1][0] * In.Get(0, 1) + m4x4[1][1] * In.Get(1, 1) + m4x4[1][2] * In.Get(2, 1) + m4x4[1][3] * In.Get(3, 1),
			m4x4[1][0] * In.Get(0, 2) + m4x4[1][1] * In.Get(1, 2) + m4x4[1][2] * In.Get(2, 2) + m4x4[1][3] * In.Get(3, 2),
			m4x4[1][0] * In.Get(0, 3) + m4x4[1][1] * In.Get(1, 3) + m4x4[1][2] * In.Get(2, 3) + m4x4[1][3] * In.Get(3, 3),
			m4x4[2][0] * In.Get(0, 0) + m4x4[2][1] * In.Get(1, 0) + m4x4[2][2] * In.Get(2, 0) + m4x4[2][3] * In.Get(3, 0),
			m4x4[2][0] * In.Get(0, 1) + m4x4[2][1] * In.Get(1, 1) + m4x4[2][2] * In.Get(2, 1) + m4x4[2][3] * In.Get(3, 1),
			m4x4[2][0] * In.Get(0, 2) + m4x4[2][1] * In.Get(1, 2) + m4x4[2][2] * In.Get(2, 2) + m4x4[2][3] * In.Get(3, 2),
			m4x4[2][0] * In.Get(0, 3) + m4x4[2][1] * In.Get(1, 3) + m4x4[2][2] * In.Get(2, 3) + m4x4[2][3] * In.Get(3, 3),
			m4x4[3][0] * In.Get(0, 0) + m4x4[3][1] * In.Get(1, 0) + m4x4[3][2] * In.Get(2, 0) + m4x4[3][3] * In.Get(3, 0),
			m4x4[3][0] * In.Get(0, 1) + m4x4[3][1] * In.Get(1, 1) + m4x4[3][2] * In.Get(2, 1) + m4x4[3][3] * In.Get(3, 1),
			m4x4[3][0] * In.Get(0, 2) + m4x4[3][1] * In.Get(1, 2) + m4x4[3][2] * In.Get(2, 2) + m4x4[3][3] * In.Get(3, 2),
			m4x4[3][0] * In.Get(0, 3) + m4x4[3][1] * In.Get(1, 3) + m4x4[3][2] * In.Get(2, 3) + m4x4[3][3] * In.Get(3, 3)
		);
	}
	FloatMatrix4x4& FloatMatrix4x4::operator *= (const FloatMatrix4x4 &In) {
		FloatMatrix4x4 Output = (*this) * In;
		*this = Output;
		return *this;
	}
	FloatVector4 FloatMatrix4x4::operator *  (const FloatVector4 &In) const {
		return FloatVector4(
			In.X() * m4x4[0][0] + In.Y() * m4x4[0][1] + In.Z() * m4x4[0][2] + In.W() * m4x4[0][3],
			In.X() * m4x4[1][0] + In.Y() * m4x4[1][1] + In.Z() * m4x4[1][2] + In.W() * m4x4[1][3],
			In.X() * m4x4[2][0] + In.Y() * m4x4[2][1] + In.Z() * m4x4[2][2] + In.W() * m4x4[2][3],
			In.X() * m4x4[3][0] + In.Y() * m4x4[3][1] + In.Z() * m4x4[3][2] + In.W() * m4x4[3][3]
		);
	}
	void FloatMatrix4x4::PrintLog() const {
		std::cout << m4x4[0][0] << "," << m4x4[0][1] << "," << m4x4[0][2] << "," << m4x4[0][3] << std::endl;
		std::cout << m4x4[1][0] << "," << m4x4[1][1] << "," << m4x4[1][2] << "," << m4x4[1][3] << std::endl;
		std::cout << m4x4[2][0] << "," << m4x4[2][1] << "," << m4x4[2][2] << "," << m4x4[2][3] << std::endl;
		std::cout << m4x4[3][0] << "," << m4x4[3][1] << "," << m4x4[3][2] << "," << m4x4[3][3] << std::endl;
	}
}