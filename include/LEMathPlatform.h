// ===========================================================
// LEMathPlatform.h
// @brief Platform setting for LEMath
// @author minseob

#pragma once

#ifndef LEMATH_USE_SIMD
#define LEMATH_USE_SIMD 0
#endif

#ifndef LEMATH_ASSERT
#if LEMATH_BUILD_DEBUG
#define LEMATH_ASSERT(x) assert(x)
#else
#define LEMATH_ASSERT(x)
#endif
#endif