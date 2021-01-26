/*********************************************************************
Copyright(c) 2020 LIMITGAME
Permission is hereby granted, free of charge, to any person
obtaining a copy of this softwareand associated documentation
files(the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify,
merge, publish, distribute, sublicense, and /or sell copies of
the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :
The above copyright noticeand this permission notice shall be
included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
----------------------------------------------------------------------
@file LEQuaternion.cpp
@brief quaternion
@author minseob (leeminseob@outlook.com)
**********************************************************************/
#include "LEQuaternion.h"

#include <iostream>

namespace LEMath {
	// Constructor
	Quaternion::Quaternion(const FloatVector4 &Axis, float Radian)
	{
		float sinAngle = sinf(Radian * 0.5f);
		float cosAngle = cosf(Radian * 0.5f);		
		x = sinAngle * Axis.X();
		y = sinAngle * Axis.Y();
		z = sinAngle * Axis.Z();
		w = cosAngle;
	}
	
	// Interfaces
	FloatVector4 Quaternion::Translate(const FloatVector4 &In) const {
		const FloatVector4 Q(x, y, z, 0.0f);
		const FloatVector4 T = 2.0f * Q.CrossProduct(In);
		return In + (T * w) + Q.CrossProduct(T);
	}
	Quaternion  Quaternion::operator + (const Quaternion &In) const {
		return Quaternion(x + In.X(), y + In.Y(), z + In.Z(), w + In.W());
	}
	Quaternion& Quaternion::operator +=(const Quaternion &In) {
		x += In.X();
		y += In.Y();
		z += In.Z();
		w += In.W();
		return *this;
	}
	Quaternion  Quaternion::operator - (const Quaternion &In) const {
		return Quaternion(y - In.Y(), y - In.Y(), z - In.Z(), w - In.W());
	}
	Quaternion& Quaternion::operator -=(const Quaternion &In) {
		x -= In.X();
		y -= In.Y();
		z -= In.Z();
		w -= In.W();
		return *this;
	}
	Quaternion  Quaternion::operator * (const Quaternion &In) const {
		return Quaternion(
			w * In.X() + x * In.W() + y * In.Z() - z * In.Y(),
			w * In.Y() + x * In.Z() + y * In.W() - z * In.X(),
			w * In.Z() + x * In.Y() + y * In.X() - z * In.W(),
			w * In.W() + x * In.X() + y * In.Y() - z * In.Z()
		);
	}
	Quaternion& Quaternion::operator *=(const Quaternion &In) {
		float X = w * In.X() + x * In.W() + y * In.Z() - z * In.Y();
		float Y = w * In.Y() + x * In.Z() + y * In.W() - z * In.X();
		float Z = w * In.Z() + x * In.Y() + y * In.X() - z * In.W();
		float W = w * In.W() + x * In.X() + y * In.Y() - z * In.Z();
		x = X;
		y = Y;
		z = Z;
		w = W;
		return *this;
	}
	FloatMatrix4x4 Quaternion::operator *  (const FloatMatrix4x4 &In) const {
		FloatMatrix4x4 Output;
		Quaternion quatInverse = Inverse();
		for (int row=0; row<4; ++row) {
			Output.SetRow(row, ((*this) * Quaternion(In.GetRow(row)) * quatInverse).ToFloatVector4());
		}
		return Output;
	}
	FloatVector4   Quaternion::operator *  (const FloatVector4 &In) const {
		return Translate(In);
	}
	Quaternion     Quaternion::operator *  (float In) const {
		return Quaternion(x * In, y * In, z * In, w * In);
	}
	Quaternion&    Quaternion::operator *= (float In) {
		x *= In;
		y *= In;
		z *= In;
		w *= In;
		return *this;
	}
	Quaternion  Quaternion::operator /  (float In) const {
		return Quaternion(x / In, y / In, z / In, w / In);
	}
	Quaternion& Quaternion::operator /= (float In) {
		x /= In;
		y /= In;
		z /= In;
		w /= In;
		return *this;
	}
	void Quaternion::PrintLog() const {
		std::cout << x << ", " << y << ", " << z << ", " << w << std::endl;
	}
}