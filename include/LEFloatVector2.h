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
@file LEFloatVector2.h
@brief 2 dimensions float vector
@author minseob (https://github.com/rasidin)
**********************************************************************/
#ifndef LEMATH_LEFLOATVECTOR2_H_
#define LEMATH_LEFLOATVECTOR2_H_
#include "LEMathDataContainer.h"

namespace LEMath {
    class FloatVector2
    {
        union {
            struct { float x, y; };
            struct { float width, height; };
        };
    public:
        FloatVector2() : x(0.0f), y(0.0f) {}
        FloatVector2(float In) : x(In), y(In) {}
        FloatVector2(float X, float Y) : x(X), y(Y) {}
        FloatVector2(const DataContainer &In) : x(In.GetFloatValue(0)), y(In.GetFloatValue(1)) {}

        inline float X() const { return x; }
        inline float Y() const { return y; }
        inline float Width() const { return width; }
        inline float Height() const { return height; }

        FloatVector2& SetX(float X) { x = X; return *this; }
        FloatVector2& SetY(float Y) { y = Y; return *this; }
		
		// Opeartors
		bool operator == (const FloatVector2 &In) const { return In.X() == x && In.Y() == y; }
		bool operator != (const FloatVector2 &In) const { return In.X() != x || In.Y() != y; }
		FloatVector2 operator + (const FloatVector2 &In) const {
			return FloatVector2(x + In.X(), y + In.Y());
		}
		FloatVector2& operator += (const FloatVector2 &In) {
			x += In.X();
			y += In.Y();
			return *this;
		}
		FloatVector2 operator - () const {
			return FloatVector2(-x, -y);
		}
		FloatVector2 operator - (const FloatVector2 &In) const {
			return FloatVector2(x - In.X(), y - In.Y());
		}
		FloatVector2& operator -= (const FloatVector2 &In) {
			x -= In.X();
			y -= In.Y();
			return *this;
		}
		FloatVector2 operator * (const FloatVector2 &In) const {
			return FloatVector2(x * In.X(), y * In.Y());
		}
		FloatVector2& operator *= (const FloatVector2 &In) {
			x *= In.X();
			y *= In.Y();
			return *this;
		}
		FloatVector2 operator * (float In) const {
			return FloatVector2(x * In, y * In);
		}
		FloatVector2& operator *= (float In) {
			x *= In;
			y *= In;
			return *this;
		}
		friend FloatVector2 operator * (float Scale, const FloatVector2 &In) {
			return In.operator*(Scale);
		}
		FloatVector2 operator / (const FloatVector2 &In) const {
			LEMATH_ASSERT(In.X() != 0 && In.Y() != 0);
			return FloatVector2(x / In.X(), y / In.Y());
		}
		FloatVector2& operator /= (const FloatVector2 &In) {
			LEMATH_ASSERT(In.X() != 0 && In.Y() != 0 && In.W() != 0);
			x /= In.X();
			y /= In.Y();
			return *this;
		}
		FloatVector2 operator / (float In) const {
			LEMATH_ASSERT(In != 0);
			return FloatVector2(x / In, y / In);
		}
		FloatVector2& operator /= (float In) {
			LEMATH_ASSERT(In != 0);
			x /= In;
			y /= In;
			return *this;
		}
		operator DataContainer() const 
		{
			DataContainer output;
			return GenerateDataContainer(output);
		}

		// Default values
		static const FloatVector2 Zero;
		static const FloatVector2 One;
	private:
		DataContainer& GenerateDataContainer(DataContainer &Output) const 
		{
			Output.DataCount = 2;
			Output.Type = DataContainer::DataType::Float;
			Output.fData[0] = x;
			Output.fData[1] = y;
			return Output;
		}
    };
    typedef FloatVector2 FloatPoint;
    typedef FloatVector2 FloatSize;
}

#endif // LEMATH_LEFLOATVECTOR2_H_