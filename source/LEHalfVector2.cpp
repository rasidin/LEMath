// ===========================================================
// LEHalfVector2.cpp
// @brief 2Dimensions Half Vector 
// @author minseob
#include "LEHalfVector2.h"

namespace LEMath {
	template<> DataContainer::operator HalfVector2() const {
		return HalfVector2(
			GetFloatValue(0),
			GetFloatValue(1)
		);
	}
}