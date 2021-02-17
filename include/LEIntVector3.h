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
@file LEIntVector3.h
@brief 3 dimensions integer vector
@author minseob (https://github.com/rasidin)
**********************************************************************/
#ifndef LEMATH_LEINTVECTOR3_H_
#define LEMATH_LEINTVECTOR3_H_

#include <LEMath>
#include "LEMathDataContainer.h"

namespace LEMath {
	class IntVector3 
	{
		union {
			struct {
				int x, y, z;
			};
		};

	public:
		IntVector3() : x(0), y(0), z(0) {}
		IntVector3(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
		IntVector3(const DataContainer &In) : x(In.GetIntValue(0)), y(In.GetIntValue(1)), z(In.GetIntValue(2)) {}

        DataContainer XY() const { DataContainer output; output.Type = DataContainer::DataType::Integer; output.iData[0] = x; output.iData[1] = y; output.DataCount = 2; return output; }
        DataContainer YZ() const { DataContainer output; output.Type = DataContainer::DataType::Integer; output.iData[0] = y; output.iData[1] = z; output.DataCount = 2; return output; }
        DataContainer XZ() const { DataContainer output; output.Type = DataContainer::DataType::Integer; output.iData[0] = x; output.iData[1] = z; output.DataCount = 2; return output; }

        int X() const { return x; }
        int Y() const { return y; }
        int Z() const { return z; }
        int Width() const { return x; }
        int Height() const { return y; }
        int Depth() const { return z; }

        void SetX(int X) { x = X; }
        void SetY(int Y) { y = Y; }
        void SetZ(int Z) { z = Z; }
        void SetWidth(int Width) { x = Width; }
        void SetHeight(int Height) { y = Height; }
        void SetDepth(int Depth) { z = Depth; }

		// Operators
		IntVector3 operator + (const IntVector3 &In) const {
			return IntVector3(x + In.x, y + In.y, z + In.z);
		}
		IntVector3 operator - (const IntVector3 &In) const {
			return IntVector3(x - In.x, y - In.y, z - In.z);
		}
		IntVector3 operator * (const IntVector3 &In) const {
			return IntVector3(x * In.x, y * In.y, z * In.z);
		}
		IntVector3 operator / (const IntVector3 &In) const {
			LEMATH_ASSERT(In.x != 0 && In.y != 0 && In.z != 0 && In.w != 0);
			return IntVector3(x / In.x, y / In.y, z / In.z);
		}
		int operator | (const IntVector3 &In) const {
			return x * In.x + y * In.y + z * In.z;
		}
		bool operator == (const IntVector3 &In) const {
			return x == In.x && y == In.y && z == In.z;
		}
        operator DataContainer() const {
			DataContainer output;
			return GenerateDataContainer(output);
		}
	private:
		DataContainer& GenerateDataContainer(DataContainer &Output) const {
            Output.DataCount = 3;
            Output.Type = DataContainer::DataType::Integer;
            Output.iData[0] = x;
            Output.iData[1] = y;
            Output.iData[2] = z;

            return Output;
        }
	};
}

#endif // LEMATH_LEINTVECTOR3_H_