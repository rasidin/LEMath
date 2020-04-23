// ===========================================================
// LEHalfVector2.h
// @brief 2Dimensions Half Vector 
// @author minseob
#pragma once

#include "LEMathUtil.h"
#include "LEMathDataContainer.h"

namespace LEMath {
	class HalfVector4 {
		union {
			struct { half x, y, z, w; };
		};
	public:
		HalfVector4() : x(0u), y(0u), z(0u), w(0u) {}
		HalfVector4(half X, half Y, half Z, half W) : x(X), y(Y), z(Z), w(W) {}
		HalfVector4(float X, float Y, float Z, float W) 
		{
			x = ToHalf(X);
			y = ToHalf(Y);
			z = ToHalf(Z);
			w = ToHalf(W);
		}
		HalfVector4(const DataContainer &Container)
		{
			*this = (HalfVector4)Container;
		}
		
		inline float X() const { return ToFloat(x); }
		inline float Y() const { return ToFloat(y); }
		inline float Z() const { return ToFloat(z); }
		inline float W() const { return ToFloat(w); }
		
		HalfVector4& SetX(float X) { x = ToHalf(X); return *this; }
		HalfVector4& SetY(float Y) { y = ToHalf(Y); return *this; }
		HalfVector4& SetZ(float Z) { z = ToHalf(Z); return *this; }
		HalfVector4& SetW(float W) { w = ToHalf(W); return *this; }
		
		bool operator == (const HalfVector4 &In) const {
			return x == In.x && y == In.y && z == In.z && w == In.w;
		}
		bool operator != (const HalfVector4 &In) const {
			return x != In.x || y != In.y || z != In.z || w != In.w;
		}
		operator DataContainer() const {
			DataContainer output;
			output.DataCount = 4;
			output.Type = DataContainer::DataType::Float;
			output.fData[0] = ToFloat(x);
			output.fData[1] = ToFloat(y);
			output.fData[2] = ToFloat(z);
			output.fData[3] = ToFloat(w);
			return output;
		}
	};
}