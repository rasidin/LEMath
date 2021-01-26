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
@file LEHalfVector4.h
@brief 4 dimensions half vector
@author minseob (leeminseob@outlook.com)
**********************************************************************/
#ifndef LEMATH_LEHALFVECTOR4_H_
#define LEMATH_LEHALFVECTOR4_H_

#include "LEMathUtil.h"
#include "LEMathDataContainer.h"

namespace LEMath {
	class HalfVector4 {
		union {
			struct { half x, y, z, w; };
		};
	public:
		HalfVector4() : x(0u), y(0u), z(0u), w(0u) {}
		HalfVector4(half X, half Y, half Z, half W) : x(X), y(Y), z(Z), w(W) {}
		HalfVector4(float X, float Y, float Z, float W) 
		{
			x = ToHalf(X);
			y = ToHalf(Y);
			z = ToHalf(Z);
			w = ToHalf(W);
		}
		HalfVector4(const DataContainer &In)
		{
			x = ToHalf(In.GetFloatValue(0));
			y = ToHalf(In.GetFloatValue(1));
			z = ToHalf(In.GetFloatValue(2));
			w = ToHalf(In.GetFloatValue(3));
		}
		
		inline float X() const { return ToFloat(x); }
		inline float Y() const { return ToFloat(y); }
		inline float Z() const { return ToFloat(z); }
		inline float W() const { return ToFloat(w); }
		
		HalfVector4& SetX(float X) { x = ToHalf(X); return *this; }
		HalfVector4& SetY(float Y) { y = ToHalf(Y); return *this; }
		HalfVector4& SetZ(float Z) { z = ToHalf(Z); return *this; }
		HalfVector4& SetW(float W) { w = ToHalf(W); return *this; }
		
		bool operator == (const HalfVector4 &In) const {
			return x == In.x && y == In.y && z == In.z && w == In.w;
		}
		bool operator != (const HalfVector4 &In) const {
			return x != In.x || y != In.y || z != In.z || w != In.w;
		}
		operator DataContainer() const {
			DataContainer output;
			output.DataCount = 4;
			output.Type = DataContainer::DataType::Float;
			output.fData[0] = ToFloat(x);
			output.fData[1] = ToFloat(y);
			output.fData[2] = ToFloat(z);
			output.fData[3] = ToFloat(w);
			return output;
		}
	};
}

#endif // LEMATH_LEHALFVECTOR4_H_