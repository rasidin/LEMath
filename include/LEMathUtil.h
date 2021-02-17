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
@file LEMathUtil.h
@brief Utilities
@author minseob (https://github.com/rasidin)
**********************************************************************/
#ifndef LEMATH_LEMATHUTIL_H_
#define LEMATH_LEMATHUTIL_H_

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

#endif // LEMATH_LEMATHUTIL_H_