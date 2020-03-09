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

        int Size() const { return x*y; }

		// Casters
		DataContainer ToIntVector3() const {
			DataContainer output;
			return GenerateDataContainer(output);
		}
		DataContainer ToIntVector4() const {
			DataContainer output;
			return GenerateDataContainer(output);
		}
		DataContainer ToFloatVector2() const {
			DataContainer output;
			return GenerateDataContainer(output);
		}
		DataContainer ToFloatVector3() const {
			DataContainer output;
			return GenerateDataContainer(output);
		}
		DataContainer ToFloatVector4() const {
			DataContainer output;
			return GenerateDataContainer(output);
		}

		// Operators
		bool operator == (const IntVector2 &In) const { return In.X() == x && In.Y() == y; }
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