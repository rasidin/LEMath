// ===========================================================
// LEIntVector4.h
// @brief 4Dimensions Integer Vector 
// @author minseob

#pragma once

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
		IntVector4(const DataContainer &In) : x(0), y(0), z(0), w(0) {
			In.ToIntVector4(this);
		}

        // Get & Set
        int X() const { return x; }
        int Y() const { return y; }
        int Z() const { return z; }
        int W() const { return w; }
        int Width() const { return z; }
        int Height() const { return w; }

        void SetX(int X) { x = X; }
        void SetY(int Y) { y = Y; }
        void SetZ(int Z) { z = Z; }
        void SetW(int W) { w = W; }
        void SetWidth(int Width) { z = Width; }
        void SetHeight(int Height) { w = Height; }

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