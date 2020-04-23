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
        IntVector2(const DataContainer &In) : x(In.GetIntValue(0)), y(In.GetIntValue(1)) {}

		int X() const { return x; }
		int Y() const { return y; }
        int Width() const { return width; }
        int Height() const { return height; }
		void SetX(int X) { x = X; }
		void SetY(int Y) { y = Y; }
        void SetWidth(int Width) { width = Width; }
        void SetHeight(int Height) { height = Height; }

        int Size() const { return x*y; }

		// Operators
		bool operator == (const IntVector2 &In) const { return In.X() == x && In.Y() == y; }
        IntVector2& operator += (const IntVector2 &In) {
            x += In.X();
            y += In.Y();
            return *this;
        }
        IntVector2 operator + (const IntVector2 &In) const {
            return IntVector2(x + In.X(), y + In.Y());
        }
        IntVector2& operator -= (const IntVector2 &In) {
            x -= In.X();
            y -= In.Y();
            return *this;
        }
        IntVector2 operator - (const IntVector2 &In) const {
            return IntVector2(x - In.X(), y - In.Y());
        }
        IntVector2& operator *= (const IntVector2 &In) {
            x *= In.X();
            y *= In.Y();
            return *this;
        }
        IntVector2 operator * (const IntVector2 &In) const {
            return IntVector2(x * In.X(), y * In.Y());
        }
        IntVector2& operator /= (const IntVector2 &In) {
            x /= In.X();
            y /= In.Y();
            return *this;
        }
        IntVector2 operator / (const IntVector2 &In) const {
            return IntVector2(x / In.X(), y / In.Y());
        }
        operator DataContainer() const {
            DataContainer output;

            output.Type = DataContainer::DataType::Integer;
            output.iData[0] = x;
            output.iData[1] = y;
            output.DataCount = 2;

            return output;
        }

        static const IntVector2 Zero;
        static const IntVector2 One;
	private:
		DataContainer& GenerateDataContainer(DataContainer &Output) const {
			Output.DataCount = 2;
			Output.Type = DataContainer::DataType::Integer;
			Output.iData[0] = x;
			Output.iData[0] = y;
			
			return Output;
		}
    };
    typedef IntVector2 IntSize;
    typedef IntVector2 IntPoint;
}