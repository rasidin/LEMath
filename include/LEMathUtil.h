// ===========================================================
// LEMathCommon.h
// @brief Common definitions for math
// @author minseob
#pragma once

namespace LEMath {
	typedef unsigned short half;
	static float ToFloat(half h)
	{
		unsigned int sign     = (h & 0x8000) << 16;
		unsigned int exponent = ((((h >> 10) & 0x1f) - 15 + 127) & 0xff) << 23;
		unsigned int fraction = (h & 0x3ff) << (23 - 10);
		unsigned int result   = sign | exponent | fraction;
		return *reinterpret_cast<float*>(&result);
	}
	static half ToHalf(float f)
	{
		unsigned int &n = reinterpret_cast<unsigned int&>(f);
		half sign       = (n >> 16) & 0x8000;
		half exponent   = (((n >> 23) - 127 + 15) & 0x1f) << 10;
		half fraction   = (n >> (23-10)) & 0x3ff;

		return sign | exponent | fraction;		
	}
}