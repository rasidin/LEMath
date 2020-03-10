// ===========================================================
// LEFloatMatrix4x4.h
// @brief Float Matrix 4x4
// @author minseob
#pragma once

#include "LEFloatVector4.h"

namespace LEMath {
	class FloatMatrix4x4
	{
		union {
			float m16[16];
			float m4x4[4][4];
			struct {
				FloatVector4 row[4];
			};
		};
	public:
		FloatMatrix4x4();
		FloatMatrix4x4(const float *In);
		FloatMatrix4x4(const FloatVector4 &Row0, const FloatVector4 &Row1, const FloatVector4 &Row2, const FloatVector4 &Row3);
		FloatMatrix4x4(float M00, float M01, float M02, float M03, float M10, float M11, float M12, float M13, float M20, float M21, float M22, float M23, float M30, float M31, float M32, float M33);
		FloatMatrix4x4(float In);
		
		// Interface
		        void                     Set(int Y, int X, float Value)       { m4x4[Y][X] = Value; }
		inline float                     Get(int Y, int X) const              { return m4x4[Y][X]; }
		                      void    SetRow(int Row, const FloatVector4 &In) { row[Row] = In; }
		inline const FloatVector4&    GetRow(int Row) const                   { return row[Row]; }
		FloatVector4               GetColumn(int Column) {
			return FloatVector4(m4x4[0][Column], m4x4[1][Column], m4x4[2][Column], m4x4[3][Column]);
		}

		float Determinant() const;

		FloatMatrix4x4 Inverse() const;
		FloatMatrix4x4 Transpose() const;
		
		FloatVector4 Translate(const FloatVector4 &In) const;
		
		// Generator
		static FloatMatrix4x4 GenerateViewMatrix(const FloatVector4 &Position, const FloatVector4 &Direction, const FloatVector4 &Up);
		static FloatMatrix4x4 GenerateViewMatrix(const FloatVector4 &Position, const FloatVector4 &Rotation);
		static FloatMatrix4x4 GeneratePerpectiveProjectionMatrix(float Near, float Far, float Width, float Height);
		static FloatMatrix4x4 GenerateOrthographicProjectionMatrix();
		
		static FloatMatrix4x4 GenerateRotationX(float X);
		static FloatMatrix4x4 GenerateRotationY(float Y);
		static FloatMatrix4x4 GenerateRotationZ(float Z);
		static FloatMatrix4x4 GenerateRotationXYZ(float RadianX, float RadianY, float RadianZ);
		static FloatMatrix4x4 GenerateRotationXYZ(const FloatVector4 &Radian);
        static FloatMatrix4x4 GenerateRotationXYZ(const DataContainer &Radian);
        static FloatMatrix4x4 GenerateInverseRotationX(float X);
		static FloatMatrix4x4 GenerateInverseRotationY(float Y);
		static FloatMatrix4x4 GenerateInverseRotationZ(float Z);
		static FloatMatrix4x4 GenerateInverseRotationXYZ(float X, float Y, float Z);
		static FloatMatrix4x4 GenerateInverseRotationXYZ(const FloatVector4 &Radian);
		static FloatMatrix4x4 GenerateTransform(float X, float Y, float Z);
		static FloatMatrix4x4 GenerateTransform(const FloatVector4 &Position);
        static FloatMatrix4x4 GenerateTransform(const DataContainer &Data);
		static FloatMatrix4x4 GenerateScaling(float X, float Y, float Z);
		static FloatMatrix4x4 GenerateScaling(const FloatVector4 &Scaling);
        static FloatMatrix4x4 GenerateScaling(const DataContainer &Data);

		// Operators
		bool 			operator == (const FloatMatrix4x4 &In) const;
		FloatMatrix4x4  operator +  (const FloatMatrix4x4 &In) const;
		FloatMatrix4x4& operator += (const FloatMatrix4x4 &In);
		FloatMatrix4x4  operator -  (const FloatMatrix4x4 &In) const;
		FloatMatrix4x4& operator -= (const FloatMatrix4x4 &In);
		FloatMatrix4x4  operator *  (const FloatMatrix4x4 &In) const;
		FloatMatrix4x4& operator *= (const FloatMatrix4x4 &In);
		FloatVector4    operator *  (const FloatVector4 &In) const;
		FloatMatrix4x4  operator *  (float In) const {
			return FloatMatrix4x4(
				row[0] * In, row[1] * In, row[2] * In, row[3] * In
			);
		}
		FloatMatrix4x4& operator *= (float In) {
			row[0] *= In;
			row[1] *= In;
			row[2] *= In;
			row[3] *= In;
			return *this;
		}
		FloatMatrix4x4  operator /  (float In) const {
			return FloatMatrix4x4(
				row[0] / In, row[1] / In, row[2] / In, row[3] / In
			);
		}
		FloatMatrix4x4& operator /= (float In) {
			row[0] /= In;
			row[1] /= In;
			row[2] /= In;
			row[3] /= In;
			return *this;
		}
		
		// for Debugging
		void PrintLog() const;
		
		// Default value
		static const FloatMatrix4x4 Zero;
		static const FloatMatrix4x4 One;
		static const FloatMatrix4x4 Identity;
	};
}