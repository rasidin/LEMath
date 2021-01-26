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
@file LEIntVector2.cpp
@brief 2 dimensions integer vector
@author minseob (leeminseob@outlook.com)
**********************************************************************/
#include "LEIntVector2.h"

namespace LEMath {
    const IntVector2 IntVector2::Zero = IntVector2(0, 0);
    const IntVector2 IntVector2::One = IntVector2(1, 1);

	template<> DataContainer::operator IntVector2() const {
		return IntVector2(GetIntValue(0), GetIntValue(1));
	}
}