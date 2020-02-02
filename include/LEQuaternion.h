// ===========================================================
// LEQuaternion.h
// @brief Quaternion
// @author minseob
#include "LEMathPlatform.h"
#include "LEMathCommon.h"

#include "LEFloatVector4.h"
#include "LEFloatMatrix4x4.h"

namespace LEMath {
	class Quaternion
	{
		union {
			struct { float x, y, z, w; };
		};
	public:
		// Constructor
		Quaternion() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
		Quaternion(float X, float Y, float Z, float W) : x(X), y(Y), z(Z), w(W) {}
		Quaternion(const FloatVector4 &In) : x(In.X()), y(In.Y()), z(In.Z()), w(In.W()) {}
		Quaternion(const FloatVector4 &Axis, float Radian);
		
		// Interfaces
		float X() const { return x; }
		float Y() const { return y; }
		float Z() const { return z; }
		float W() const { return w; }
		Quaternion Inverse() const { return Quaternion(-x, -y, -z, w); }
		FloatVector4 Translate(const FloatVector4 &In) const;
		FloatVector4 ToFloatVector4() const { return FloatVector4(x, y, z, w); }
		
		// Operators
		bool           operator == (const Quaternion &In) const { return x == In.X() && y == In.Y() && z == In.Z() && w == In.W(); }
		Quaternion     operator +  (const Quaternion &In) const;
		Quaternion&    operator += (const Quaternion &In);
		Quaternion     operator -  (const Quaternion &In) const;
		Quaternion&    operator -= (const Quaternion &In);
		Quaternion     operator *  (const Quaternion &In) const;
		Quaternion&    operator *= (const Quaternion &In);
		FloatMatrix4x4 operator *  (const FloatMatrix4x4 &In) const;
		FloatVector4   operator *  (const FloatVector4 &In) const;
		Quaternion     operator *  (float In) const;
		Quaternion&    operator *= (float In);
		Quaternion     operator /  (float In) const;
		Quaternion&    operator /= (float In);
		
		void PrintLog() const;
		
		// Default Values
		static const Quaternion Zero;
		static const Quaternion One;
		static const Quaternion Identity;
	};
}