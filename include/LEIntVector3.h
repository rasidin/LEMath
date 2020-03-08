// ===========================================================
// LEIntVector3.h
// @brief 3Dimensions Integer Vector 
// @author minseob
#pragma once

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

            output.Type = output.Type = DataContainer::DataType::Integer;
            output.iData[0] = x;
            output.iData[1] = y;
            output.iData[2] = z;
            output.DataCount = 3;

            return output;
        }
	};
}