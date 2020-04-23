// ===========================================================
// LEFloatVector3.h
// @brief 3Dimensions Float Vector 
// @author minseob
#pragma once
#include "LEMathDataContainer.h"

namespace LEMath {
    class FloatVector3
    {
        union {
            struct { float x, y, z; };
            struct { float r, g, b; };
        };
    public:
        FloatVector3() : x(0.0f), y(0.0f), z(0.0f) {}
        FloatVector3(float In) : x(In), y(In), z(In) {}
        FloatVector3(float X, float Y, float Z) : x(X), y(Y), z(Z) {}
		FloatVector3(const DataContainer &In) : x(0.0f), y(0.0f), z(0.0f) {
			*this = (FloatVector3)In;
		}

		// Get
        inline float X() const { return x; }
        inline float Y() const { return y; }
        inline float Z() const { return z; }

		// Set
        FloatVector3& SetX(float X) { x = X; return *this; }
        FloatVector3& SetY(float Y) { y = Y; return *this; }
        FloatVector3& SetZ(float Z) { z = Z; return *this; }

		// Casters
		DataContainer ToFloatVector2() const {
			DataContainer output;
			return GenerateDataContainer(output);
		}
		DataContainer ToFloatVector4() const {
			DataContainer output;
			return GenerateDataContainer(output);
		}
		DataContainer ToIntVector2() const {
			DataContainer output;
			return GenerateDataContainer(output);
		}
		DataContainer ToIntVector3() const {
			DataContainer output;
			return GenerateDataContainer(output);
		}
		DataContainer ToIntVector4() const {
			DataContainer output;
			return GenerateDataContainer(output);
		}

		// Operators
		bool operator == (const FloatVector3 &In) const { In.X() == x && In.Y() == y && In.Z() == z; }
        operator DataContainer() const {
            DataContainer output;
			return GenerateDataContainer(output);
        }
		
		// Default values
		static const FloatVector3 Zero;
		static const FloatVector3 One;
	private:
		DataContainer& GenerateDataContainer(DataContainer &Output) const {
            Output.Type = DataContainer::DataType::Float;
            Output.DataCount = 3;
            Output.fData[0] = x;
            Output.fData[1] = y;
            Output.fData[2] = z;
            return Output;
		}
    };
    typedef FloatVector3 FloatColorRGB;
}