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
@file LEIntVector4.h
@brief 4 dimensions integer vector
@author minseob (https://github.com/rasidin)
**********************************************************************/
#ifndef LEMATH_LEINTVECTOR4_H_
#define LEMATH_LEINTVECTOR4_H_

#include "LEMathPlatform.h"
#include "LEMathDataContainer.h"

namespace LEMath {
	class IntVector4
	{
		union {
			struct {
				int x, y, z, w;
			};
		};
	public:
		// Constructors
		IntVector4() : x(0), y(0), z(0), w(0) {}
		IntVector4(int _x, int _y, int _z, int _w) : x(_x), y(_y), z(_z), w(_w) {}
		IntVector4(const DataContainer &In) 
		: x(In.GetIntValue(0))
		, y(In.GetIntValue(1))
		, z(In.GetIntValue(2))
		, w(In.GetIntValue(3)) 
		{
		}

        // Get & Set
        int X() const { return x; }
        int Y() const { return y; }
        int Z() const { return z; }
        int W() const { return w; }
        int Width() const { return z; }
        int Height() const { return w; }
        DataContainer Size() const {
            DataContainer Output;
            Output.Type = DataContainer::DataType::Integer;
            Output.DataCount = 2;
            Output.iData[0] = z;
            Output.iData[1] = w;
            return Output;
        }

        void SetX(int X) { x = X; }
        void SetY(int Y) { y = Y; }
        void SetZ(int Z) { z = Z; }
        void SetW(int W) { w = W; }
        void SetWidth(int Width) { z = Width; }
        void SetHeight(int Height) { w = Height; }

        // Caster
        operator DataContainer() const {
            DataContainer Output;
            Output.DataCount = 4;
            Output.Type = DataContainer::DataType::Integer;
            Output.iData[0] = x;
            Output.iData[1] = y;
            Output.iData[2] = z;
            Output.iData[3] = w;

            return Output;
        }

		// Operators
		IntVector4 operator + (const IntVector4 &In) const {
			return IntVector4(x + In.x, y + In.y, z + In.z, w + In.w);
		}
        IntVector4 operator + (int In) const {
            return IntVector4(x + In, y + In, z + In, w + In);
        }
		IntVector4 operator - (const IntVector4 &In) const {
			return IntVector4(x - In.x, y - In.y, z - In.z, w - In.w);
		}
		IntVector4 operator * (const IntVector4 &In) const {
			return IntVector4(x * In.x, y * In.y, z * In.z, w * In.w);
		}
		IntVector4 operator / (const IntVector4 &In) const {
			LEMATH_ASSERT(In.x != 0 && In.y != 0 && In.z != 0 && In.w != 0);
			return IntVector4(x / In.x, y / In.y, z / In.z, w / In.w);
		}
        IntVector4 operator % (const IntVector4 &In) const {
            return IntVector4(x % In.x, y % In.y, z % In.z, w % In.w);
        }
		int operator | (const IntVector4 &In) const {
			return x * In.x + y * In.y + z * In.z + w * In.w;
		}
		bool operator == (const IntVector4 &In) const {
			return x == In.x && y == In.y && z == In.z && w == In.w;
		}
	};
    typedef IntVector4 IntRect;
}

#endif // LEMATH_LEINTVECTOR4_H_