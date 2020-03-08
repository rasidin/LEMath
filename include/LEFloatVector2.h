// ===========================================================
// LEFloatVector2.h
// @brief 2Dimensions Float Vector 
// @author minseob
#pragma once
#include "LEMathDataContainer.h"

namespace LEMath {
    class FloatVector2
    {
        union {
            struct { float x, y; };
            struct { float width, height; };
        };
    public:
        FloatVector2() : x(0.0f), y(0.0f) {}
        FloatVector2(float In) : x(In), y(In) {}
        FloatVector2(float X, float Y) : x(X), y(Y) {}
        FloatVector2(const DataContainer &In) : x(0.0f), y(0.0f) {
            In.ToFloatVector2(this);
        }

        inline float X() const { return x; }
        inline float Y() const { return y; }
        inline float Width() const { return width; }
        inline float Height() const { return height; }

        FloatVector2& SetX(float X) { x = X; return *this; }
        FloatVector2& SetY(float Y) { y = Y; return *this; }
    };
    typedef FloatVector2 FloatPoint;
}