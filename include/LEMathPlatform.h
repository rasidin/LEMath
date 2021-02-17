/*********************************************************************
Copyright(c) 2020 LIMITGAME
Permission is hereby granted, free of charge, to any person
obtaining a copy of this softwareand associated documentation
files(the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify,
merge, publish, distribute, sublicense, and /or sell copies of
the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :
The above copyright noticeand this permission notice shall be
included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
----------------------------------------------------------------------
@file LEMathPlatform.h
@brief Platform definitions
@author minseob (https://github.com/rasidin)
**********************************************************************/
#ifndef LEMATH_LEMATHPLATFORM_H_
#define LEMATH_LEMATHPLATFORM_H_

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

#endif // LEMATH_LEMATHPLATFORM_H_