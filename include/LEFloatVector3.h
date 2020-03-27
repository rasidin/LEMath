// ===========================================================
// LEFloatVector3.h
// @brief 3Dimensions Float Vector 
// @author minseob
#pragma once
#include <math.h>

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
        template<typename T>
		FloatVector3(T In) : x(0.0f), y(0.0f), z(0.0f) {
            ((DataContainer)In).ToFloatVector3(this);
		}

		// Get
        inline float& Get(int Index) { return (Index == 0) ? x : ((Index == 1) ? y : (Index == 2) ? z : x); }
        inline float Get(int Index) const { return (Index == 0) ? x : ((Index == 1) ? y : (Index == 2) ? z : x); }
        inline float X() const { return x; }
        inline float Y() const { return y; }
        inline float Z() const { return z; }
        float Length() const { return ::sqrtf(x * x + y * y + z * z); }
        FloatVector3& Normalize() {
            float length = Length();
            if (length > 1e-4) {
                x = x / length;
                y = y / length;
                z = z / length;
            }
            return *this;
        }
        FloatVector3 Minimum(const FloatVector3 &In) {
            return FloatVector3((x < In.X()) ? x : In.X(), (y < In.Y()) ? y : In.Y(), (z < In.Z()) ? z : In.Z());
        }
        FloatVector3 Maximum(const FloatVector3 &In) {
            return FloatVector3((x > In.X()) ? x : In.X(), (y > In.Y()) ? y : In.Y(), (z > In.Z()) ? z : In.Z());
        }

        // Caclulator (static)
        static FloatVector3 CrossProduct(const FloatVector3 &A, const FloatVector3 &B) {
            return FloatVector3(A.Y() * B.Z() - A.Z() * B.Y(), A.Z() * B.X() - A.X() * B.Z(), A.X() * B.Y() - A.Y() * B.X());
        }
        static float DotProduct(const FloatVector3 &A, const FloatVector3 &B) {
            return A.X() * B.X() + A.Y() * B.Y() + A.Z() * B.Z();
        }
        
        // Set
        FloatVector3& SetX(float X) { x = X; return *this; }
        FloatVector3& SetY(float Y) { y = Y; return *this; }
        FloatVector3& SetZ(float Z) { z = Z; return *this; }

		// Operators
		bool operator == (const FloatVector3 &In) const { return In.X() == x && In.Y() == y && In.Z() == z; }
        bool operator != (const FloatVector3 &In) const { return In.X() != x || In.Y() != y || In.Z() != z; }
        float& operator [] (int Index) { return Get(Index); }
        float operator [] (int Index) const { return Get(Index); }
        FloatVector3 operator + (const FloatVector3 &In) const {
            return FloatVector3(x + In.X(), y + In.Y(), z + In.Z());
        }
        FloatVector3& operator += (const FloatVector3 &In) {
            x += In.X();
            y += In.Y();
            z += In.Z();
            return *this;
        }
        FloatVector3 operator - () const {
            return FloatVector3(-x, -y, -z);
        }
        FloatVector3 operator - (const FloatVector3 &In) const {
            return FloatVector3(x - In.X(), y - In.Y(), z - In.Z());
        }
        FloatVector3& operator -= (const FloatVector3 &In) {
            x -= In.X();
            y -= In.Y();
            z -= In.Z();
            return *this;
        }
        FloatVector3 operator * (const FloatVector3 &In) const {
            return FloatVector3(x * In.X(), y * In.Y(), z * In.Z());
        }
        FloatVector3& operator *= (const FloatVector3 &In) {
            x *= In.X();
            y *= In.Y();
            z *= In.Z();
            return *this;
        }
        FloatVector3 operator / (const FloatVector3 &In) const {
            return FloatVector3(x / In.X(), y + In.Y(), z / In.Z());
        }
        FloatVector3& operator /= (const FloatVector3 &In) {
            x /= In.X();
            y /= In.Y();
            z /= In.Z();
            return *this;
        }
        FloatVector3 operator ^ (const FloatVector3 &In) const {
            return CrossProduct(*this, In);
        }
        FloatVector3& operator ^= (const FloatVector3 &In) {
            *this = CrossProduct(*this, In);
            return *this;
        }
        float operator | (const FloatVector3 &In) const {
            return DotProduct(*this, In);
        }
        bool operator < (const FloatVector3 &In) const {
            return x < In.X() && y < In.Y() && z < In.Z();
        }
        bool operator > (const FloatVector3 &In) const {
            return x > In.X() && y > In.Y() && z > In.Z();
        }
        operator DataContainer() const {
            DataContainer output;
			return GenerateDataContainer(output);
        }
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