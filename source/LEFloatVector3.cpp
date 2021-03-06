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
@file LEFloatVector3.cpp
@brief 3 dimensions float vector
@author minseob (https://github.com/rasidin)
**********************************************************************/
#include "LEFloatVector3.h"

namespace LEMath {
	const FloatVector3 FloatVector3::Zero = FloatVector3(0.0f, 0.0f, 0.0f);
	const FloatVector3 FloatVector3::One  = FloatVector3(1.0f, 1.0f, 1.0f);
	template<> DataContainer::operator FloatVector3() const {
		return FloatVector3(
			GetFloatValue(0),
			GetFloatValue(1),
			GetFloatValue(2)
		);
	}
} 