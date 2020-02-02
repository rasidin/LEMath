// ===========================================================
// LEIntVector3.h
// @brief 3Dimensions Integer Vector 
// @author minseob
#pragma once

#include "LEMathPlatform.h"

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
	};
}