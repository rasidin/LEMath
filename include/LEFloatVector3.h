// ===========================================================
// LEFloatVector3.h
// @brief 3Dimensions Float Vector 
// @author minseob
#pragma once

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

        inline float X() const { return x; }
        inline float Y() const { return y; }

        FloatVector3& SetX(float X) { x = X; return *this; }
        FloatVector3& SetY(float Y) { y = Y; return *this; }
        FloatVector3& SetZ(float Z) { z = Z; return *this; }
    };
    typedef FloatVector3 FloatColorRGB;
}