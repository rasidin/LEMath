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
		
		// Casters
		DataContainer ToFloatVector3() const 
		{
			DataContainer output;
			return GenerateDataContainer(output);
		}	
		DataContainer ToFloatVector4() const 
		{
			DataContainer output;
			return GenerateDataContainer(output);
		}	
		DataContainer ToIntVector2() const 
		{
			DataContainer output;
			return GenerateDataContainer(output);
		}	
		DataContainer ToIntVector3() const 
		{
			DataContainer output;
			return GenerateDataContainer(output);
		}	
		DataContainer ToIntVector4() const 
		{
			DataContainer output;
			return GenerateDataContainer(output);
		}	
		
		// Opeartors
		bool operator == (const FloatVector2 &In) const { return In.X() == x && In.Y() == y; }
        FloatVector2 operator + (const FloatVector2 &In) const {
            return FloatVector2(x + In.X(), y + In.Y());
        }
        FloatVector2& operator += (const FloatVector2 &In) {
            x += In.X();
            y += In.Y();
            return *this;
        }
        FloatVector2 operator - (const FloatVector2 &In) const {
            return FloatVector2(x - In.X(), y - In.Y());
        }
        FloatVector2& operator -= (const FloatVector2 &In) {
            x -= In.X();
            y -= In.Y();
            return *this;
        }
        FloatVector2 operator * (const FloatVector2 &In) const {
            return FloatVector2(x * In.X(), y * In.Y());
        }
        FloatVector2& operator *= (const FloatVector2 &In) {
            x *= In.X();
            y *= In.Y();
            return *this;
        }
        FloatVector2 operator / (const FloatVector2 &In) const {
            return FloatVector2(x / In.X(), y / In.Y());
        }
        FloatVector2& operator /= (const FloatVector2 &In) {
            x /= In.X();
            y /= In.Y();
            return *this;
        }
        operator DataContainer() const
		{
			DataContainer output;
			return GenerateDataContainer(output);
		}
	private:
		DataContainer& GenerateDataContainer(DataContainer &Output) const 
		{
			Output.DataCount = 2;
			Output.Type = DataContainer::DataType::Float;
			Output.fData[0] = x;
			Output.fData[1] = y;
			return Output;
		}
    };
    typedef FloatVector2 FloatPoint;
    typedef FloatVector2 FloatSize;
}