// ===========================================================
// LEFloatVector4.h
// @brief 4Dimensions Float Vector 
// @author minseob
#pragma once

#include <math.h>
#include <iostream>

#include "LEMathPlatform.h"
#include "LEMathDataContainer.h"

namespace LEMath {
	class FloatVector4 
	{
		static constexpr float NearlyZeroValue = 1.0e-06f;

		union {
			struct { float x, y, z, w; };
			struct { float r, g, b, a; };
		};
	public:
		// Constructor
		FloatVector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
		FloatVector4(float In) : x(In), y(In), z(In), w(In) {}
		FloatVector4(float X, float Y, float Z, float W) : x(X), y(Y), z(Z), w(W) {}
        FloatVector4(const DataContainer &In) : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {
            In.ToFloatVector4(this);
        }

		// Properties
		inline float X() const { return x; }
		inline float Y() const { return y; }
		inline float Z() const { return z; }
		inline float W() const { return w; }
        inline float Red() const { return x; }
        inline float Green() const { return y; }
        inline float Blue() const { return z; }
        inline float Alpha() const { return w; }

		// Interface
		FloatVector4& SetX(float X) { x = X; return *this; }
		FloatVector4& SetY(float Y) { y = Y; return *this; }
		FloatVector4& SetZ(float Z) { z = Z; return *this; }
		FloatVector4& SetW(float W) { w = W; return *this; }
		
		// Calculator (self)
		FloatVector4& Abs() {
			x = abs(x);
			y = abs(y);
			z = abs(z);
			w = abs(w);
			return *this;
		}
		FloatVector4& Sqrt() {
			x = sqrt(x);
			y = sqrt(y);
			z = sqrt(z);
			w = sqrt(w);
			return *this;
		}
		FloatVector4& Normalize() {
			float length = Length();
			LEMATH_ASSERT(length > 0.0f);
			x /= length;
			y /= length;
			z /= length;
			w /= length;
			return *this;
		}
		float Length() const {
			LEMATH_ASSERT(!IsZero());
			return sqrtf((*this) | (*this));
		}
		FloatVector4 CrossProduct(const FloatVector4 &In) const {
			return CrossProduct(*this, In);
		}
		
		// Checkers
		bool IsZero() const { return x == 0 && y == 0 && z == 0 && w == 0; }
		bool IsNearlyZero() const { return abs(x) < NearlyZeroValue && abs(y) < NearlyZeroValue && abs(z) < NearlyZeroValue && abs(w) < NearlyZeroValue; }
		
		// Caclulator (static)
		static FloatVector4 CrossProduct(const FloatVector4 &A, const FloatVector4 &B) {
			return FloatVector4(A.Y() * B.Z() - A.Z() * B.Y(), A.Z() * B.X() - A.X() * B.Z(), A.X() * B.Y() - A.Y() * B.X(), 0.0f);
		}
		static float DotProduct(const FloatVector4 &A, const FloatVector4 &B) {
			return A.X() * B.X() + A.Y() * B.Y() + A.Z() * B.Z() + A.W() * B.W();
		}
		
		// Operators
		bool operator == (const FloatVector4 &In) const {
			return x == In.X() && y == In.Y() && z == In.Z() && w == In.W();
		}
		bool operator != (const FloatVector4 &In) const {
			return x != In.X() || y != In.Y() || z != In.Z() || w != In.W();
		}
		FloatVector4 operator + (const FloatVector4 &In) const {
			return FloatVector4(x + In.X(), y + In.Y(), z + In.Z(), w + In.W());
		}
		FloatVector4& operator += (const FloatVector4 &In) {
			x += In.X();
			y += In.Y();
			z += In.Z();
			w += In.W();
			return *this;
		}
		FloatVector4 operator - () const {
			return FloatVector4(-x, -y, -z, -w);
		}
		FloatVector4 operator - (const FloatVector4 &In) const {
			return FloatVector4(x - In.X(), y - In.Y(), z - In.Z(), w - In.W());
		}
		FloatVector4& operator -= (const FloatVector4 &In) {
			x -= In.X();
			y -= In.Y();
			z -= In.Z();
			w -= In.W();
			return *this;
		}
		FloatVector4 operator * (const FloatVector4 &In) const {
			return FloatVector4(x * In.X(), y * In.Y(), z * In.Z(), w * In.W());
		}
		FloatVector4& operator *= (const FloatVector4 &In) {
			x *= In.X();
			y *= In.Y();
			z *= In.Z();
			w *= In.W();
			return *this;
		}
		FloatVector4 operator * (float In) const {
			return FloatVector4(x * In, y * In, z * In, w * In);
		}
		FloatVector4& operator *= (float In) {
			x *= In;
			y *= In;
			z *= In;
			w *= In;
			return *this;
		}
		friend FloatVector4  operator * (float Scale, const FloatVector4 &In) {
			return In.operator*(Scale);
		}
		FloatVector4 operator / (const FloatVector4 &In) const {
			LEMATH_ASSERT(In.X() != 0 && In.Y() != 0 && In.Z() != 0 && In.W() != 0);
			return FloatVector4(x / In.X(), y / In.Y(), z / In.Z(), w / In.W());
		}
		FloatVector4& operator /= (const FloatVector4 &In) {
			LEMATH_ASSERT(In.X() != 0 && In.Y() != 0 && In.Z() != 0 && In.W() != 0);
			x /= In.X();
			y /= In.Y();
			z /= In.Z();
			w /= In.W();
			return *this;
		}
		FloatVector4 operator / (float In) const {
			LEMATH_ASSERT(In != 0);
			return FloatVector4(x / In, y / In, z / In, w / In);
		}
		FloatVector4& operator /= (float In) {
			LEMATH_ASSERT(In != 0);
			x /= In;
			y /= In;
			z /= In;
			w /= In;
			return *this;
		}
		FloatVector4 operator ^ (const FloatVector4 &In) const {
			return CrossProduct(*this, In);
		}
		FloatVector4& operator ^= (const FloatVector4 &In) {
			*this = CrossProduct(*this, In);
			return *this;
		}
		float operator | (const FloatVector4 &In) const {
			return DotProduct(*this, In);
		}
		
		void PrintLog() const { std::cout << x << ", " << y << ", " << z << ", " << w << std::endl; }
		
		// Default values
		static const FloatVector4 Zero;
		static const FloatVector4 One;
	};
	typedef FloatVector4 FloatColorRGBA;
}