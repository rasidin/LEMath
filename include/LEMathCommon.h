// ===========================================================
// LEMathCommon.h
// @brief Common definitions for math
// @author minseob
#pragma once

namespace LEMath {
	static constexpr float LEMath_PI = 3.1415926535897932f;
}

#define DEGREE2RADIAN(a) a * LEMath::LEMath_PI / 180.0f