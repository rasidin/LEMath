// ===========================================================
// LEIntVector2.h
// @brief 2Dimensions Integer Vector 
// @author minseob
#pragma once

#include "LEMathDataContainer.h"
namespace LEMath {
	class IntVector2 {
		union {
			struct { int x, y; };
			struct { int width, height; };
		};
	public:
		IntVector2() : x(0), y(0) {}
		IntVector2(int In) : x(In), y(In) {}
		IntVector2(int X, int Y) : x(X), y(Y) {}
        IntVector2(const DataContainer &In) {
            In.ToIntVector2(this);
        }

		int X() const { return x; }
		int Y() const { return y; }
        int Width() const { return width; }
        int Height() const { return height; }
		void SetX(int X) { x = X; }
		void SetY(int Y) { y = Y; }
        void SetWidth(int Width) { width = Width; }
        void SetHeight(int Height) { height = Height; }

        static const IntVector2 Zero;
        static const IntVector2 One;
    };
}