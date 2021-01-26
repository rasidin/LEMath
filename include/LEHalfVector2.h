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
@file LEHalfVector2.h
@brief 2 dimensions half vector
@author minseob (leeminseob@outlook.com)
**********************************************************************/
#ifndef LEMATH_LEHALFVECTOR2_H_
#define LEMATH_LEHALFVECTOR2_H_

#include "LEMathUtil.h"
#include "LEMathDataContainer.h"

namespace LEMath {
	class HalfVector2 {
		union {
			struct { half x, y; };
		};
	public:
		HalfVector2() : x(0u), y(0u) {}
		HalfVector2(half X, half Y) : x(X), y(Y) {}
		HalfVector2(float X, float Y) 
		{
			x = ToHalf(X);
			y = ToHalf(Y);
		}
		HalfVector2(const DataContainer &In)
		{
			x = ToHalf(In.GetFloatValue(0));
			y = ToHalf(In.GetFloatValue(1));
		}
		
		inline float X() const { return ToFloat(x); }
		inline float Y() const { return ToFloat(y); }
		
		HalfVector2& SetX(float X) { x = ToHalf(X); return *this; }
		HalfVector2& SetY(float Y) { y = ToHalf(Y); return *this; }
		
		bool operator == (const HalfVector2 &In) const {
			return x == In.x && y == In.y;
		}
		bool operator != (const HalfVector2 &In) const {
			return x != In.x || y != In.y;
		}
		operator DataContainer() const {
			DataContainer output;
			output.DataCount = 2;
			output.Type = DataContainer::DataType::Float;
			output.fData[0] = ToFloat(x);
			output.fData[1] = ToFloat(y);
			return output;
		}
	};
}

#endif // LEMATH_LEHALFVECTOR2_H_