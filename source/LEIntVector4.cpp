// ===========================================================
// LEIntVector4.cpp
// @brief 4Dimensions Integer Vector 
// @author minseob

#include "LEIntVector4.h"

namespace LEMath
{
	template<> DataContainer::operator IntVector4() const {
		return IntVector4(
			GetIntValue(0),
			GetIntValue(1),
			GetIntValue(2),
			GetIntValue(3)
		);
	}
}