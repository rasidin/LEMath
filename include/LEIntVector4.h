// ===========================================================
// LEIntVector4.h
// @brief 4Dimensions Integer Vector 
// @author minseob

#pragma once

#include "LEMathPlatform.h"

namespace LEMath {
	class IntVector4
	{
		union {
			struct {
				int x, y, z, w;
			};
#if LEMATH_USE_SIMD
#endif
		};
	public:
		// Constructors
		IntVector4() : x(0), y(0), z(0), w(0) {}
		IntVector4(int _x, int _y, int _z, int _w) : x(_x), y(_y), z(_z), w(_w) {}

		// Operators
		IntVector4 operator + (const IntVector4 &In) const {
			return IntVector4(x + In.x, y + In.y, z + In.z, w + In.w);
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
		int operator | (const IntVector4 &In) const {
			return x * In.x + y * In.y + z * In.z + w * In.w;
		}
		bool operator == (const IntVector4 &In) const {
			return x == In.x && y == In.y && z == In.z && w == In.w;
		}
	};
}