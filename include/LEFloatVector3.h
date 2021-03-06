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
@file LEFloatVector3.h
@brief 3 dimensions float vector
@author minseob (https://github.com/rasidin)
**********************************************************************/
#ifndef LEMATH_LEFLOATVECTOR3_H_
#define LEMATH_LEFLOATVECTOR3_H_
#include <math.h>

#include "LEMathDataContainer.h"

namespace LEMath {
    class FloatVector3
    {
        union {
            struct { float x, y, z; };
            struct { float r, g, b; };
        };
    public:
        FloatVector3() : x(0.0f), y(0.0f), z(0.0f) {}
        FloatVector3(float In) : x(In), y(In), z(In) {}
        FloatVector3(float X, float Y, float Z) : x(X), y(Y), z(Z) {}
		FloatVector3(const DataContainer &In) : x(In.GetFloatValue(0)), y(In.GetFloatValue(1)), z(In.GetFloatValue(2)) {}

		// Get
        inline float X() const { return x; }
        inline float Y() const { return y; }
        inline float Z() const { return z; }

		// Set
        FloatVector3& SetX(float X) { x = X; return *this; }
        FloatVector3& SetY(float Y) { y = Y; return *this; }
        FloatVector3& SetZ(float Z) { z = Z; return *this; }

		// Calculator
		FloatVector3& Normalize() {
			float length = Length();
			LEMATH_ASSERT(length > 0.0f);
			x /= length;
			y /= length;
			z /= length;
			return *this;
		}
		float Length() const {
			LEMATH_ASSERT(!IsZero());
			return sqrtf((*this) | (*this));
		}		
		FloatVector3 Minimum(const FloatVector3 &In) { 
			return FloatVector3(
				(x < In.x)?x:In.x,
				(y < In.y)?y:In.y,
				(z < In.z)?z:In.z
			);
		}
		FloatVector3 Maximum(const FloatVector3 &In) { 
			return FloatVector3(
				(x > In.x)?x:In.x,
				(y > In.y)?y:In.y,
				(z > In.z)?z:In.z
			);
		}
		inline FloatVector3 CrossProduct(const FloatVector3& In) const {
			return CrossProduct(*this, In);
		}
		inline float DotProduct(const FloatVector3& In) const {
			return DotProduct(*this, In);
		}

		// Checkers
		bool IsZero() const { return x == 0 && y == 0 && z == 0; }

		// Calculators (static)
		static inline FloatVector3 CrossProduct(const FloatVector3& A, const FloatVector3& B) {
			return FloatVector3(A.Y() * B.Z() - A.Z() * B.Y(), A.Z() * B.X() - A.X() * B.Z(), A.X() * B.Y() - A.Y() * B.X());
		}
		static inline float DotProduct(const FloatVector3& A, const FloatVector3& B) {
			return A.X() * B.X() + A.Y() * B.Y() + A.Z() * B.Z();
		}

		// Operators
		bool operator == (const FloatVector3 &In) const { return In.X() == x && In.Y() == y && In.Z() == z; }
		bool operator != (const FloatVector3 &In) const {
			return x != In.X() || y != In.Y() || z != In.Z();
		}
		bool operator < (const FloatVector3 &In) const { return x < In.X() && y < In.Y() && z < In.Z(); }
		bool operator > (const FloatVector3 &In) const { return x > In.X() && y > In.Y() && z > In.Z(); }
		float operator [] (int n) const {
			if (n==0) return x;
			else if (n==1) return y;
			else if (n==2) return z;
			else return 0;
		}
		FloatVector3 operator + (const FloatVector3 &In) const {
			return FloatVector3(x + In.X(), y + In.Y(), z + In.Z());
		}
		FloatVector3& operator += (const FloatVector3 &In) {
			x += In.X();
			y += In.Y();
			z += In.Z();
			return *this;
		}
		FloatVector3 operator - () const {
			return FloatVector3(-x, -y, -z);
		}
		FloatVector3 operator - (const FloatVector3 &In) const {
			return FloatVector3(x - In.X(), y - In.Y(), z - In.Z());
		}
		FloatVector3& operator -= (const FloatVector3 &In) {
			x -= In.X();
			y -= In.Y();
			z -= In.Z();
			return *this;
		}
		FloatVector3 operator * (const FloatVector3 &In) const {
			return FloatVector3(x * In.X(), y * In.Y(), z * In.Z());
		}
		FloatVector3& operator *= (const FloatVector3 &In) {
			x *= In.X();
			y *= In.Y();
			z *= In.Z();
			return *this;
		}
		FloatVector3 operator * (float In) const {
			return FloatVector3(x * In, y * In, z * In);
		}
		FloatVector3& operator *= (float In) {
			x *= In;
			y *= In;
			z *= In;
			return *this;
		}
		friend FloatVector3 operator * (float Scale, const FloatVector3 &In) {
			return In.operator*(Scale);
		}
		FloatVector3 operator / (const FloatVector3 &In) const {
			LEMATH_ASSERT(In.X() != 0 && In.Y() != 0 && In.Z() != 0);
			return FloatVector3(x / In.X(), y / In.Y(), z / In.Z());
		}
		FloatVector3& operator /= (const FloatVector3 &In) {
			LEMATH_ASSERT(In.X() != 0 && In.Y() != 0 && In.Z() != 0);
			x /= In.X();
			y /= In.Y();
			z /= In.Z();
			return *this;
		}
		FloatVector3 operator / (float In) const {
			LEMATH_ASSERT(In != 0);
			return FloatVector3(x / In, y / In, z / In);
		}
		FloatVector3& operator /= (float In) {
			LEMATH_ASSERT(In != 0);
			x /= In;
			y /= In;
			z /= In;
			return *this;
		}
		float operator | (const FloatVector3 &In) const {
			return x * In.x + y * In.y + z * In.z;
		}
		FloatVector3 operator ^ (const FloatVector3 &In) const {
			return CrossProduct(*this, In);
		}
        operator DataContainer() const {
            DataContainer output;
			return GenerateDataContainer(output);
        }
		
		// Default values
		static const FloatVector3 Zero;
		static const FloatVector3 One;
	private:
		DataContainer& GenerateDataContainer(DataContainer &Output) const {
            Output.Type = DataContainer::DataType::Float;
            Output.DataCount = 3;
            Output.fData[0] = x;
            Output.fData[1] = y;
            Output.fData[2] = z;
            return Output;
		}
    };
    typedef FloatVector3 FloatColorRGB;
}

#endif // LEMATH_LEFLOATVECTOR3_H_