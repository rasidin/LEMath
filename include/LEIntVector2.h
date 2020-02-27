// ===========================================================
// LEIntVector2.h
// @brief 2Dimensions Integer Vector 
// @author minseob
#pragma once

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

		int X() const { return x; }
		int Y() const { return y; }
		void SetX(int X) { x = X; }
		void SetY(int Y) { y = Y; }
	};
	typedef IntVector2 IntSize;
}