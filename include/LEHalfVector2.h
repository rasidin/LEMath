// ===========================================================
// LEHalfVector2.h
// @brief 2Dimensions Half Vector 
// @author minseob
#pragma once

#include "LEMathUtil.h"
#include "LEMathDataContainer.h"

namespace LEMath {
	class HalfVector2 {
		union {
			struct { half x, y; };
		};
	public:
		HalfVector2() : x(0u), y(0u) {}
		HalfVector2(half X, half Y) : x(X), y(Y) {}
		HalfVector2(float X, float Y) 
		{
			x = ToHalf(X);
			y = ToHalf(Y);
		}
		HalfVector2(const DataContainer &In)
		{
			x = ToHalf(In.GetFloatValue(0));
			y = ToHalf(In.GetFloatValue(1));
		}
		
		inline float X() const { return ToFloat(x); }
		inline float Y() const { return ToFloat(y); }
		
		HalfVector2& SetX(float X) { x = ToHalf(X); return *this; }
		HalfVector2& SetY(float Y) { y = ToHalf(Y); return *this; }
		
		bool operator == (const HalfVector2 &In) const {
			return x == In.x && y == In.y;
		}
		bool operator != (const HalfVector2 &In) const {
			return x != In.x || y != In.y;
		}
		operator DataContainer() const {
			DataContainer output;
			output.DataCount = 2;
			output.Type = DataContainer::DataType::Float;
			output.fData[0] = ToFloat(x);
			output.fData[1] = ToFloat(y);
			return output;
		}
	};
}