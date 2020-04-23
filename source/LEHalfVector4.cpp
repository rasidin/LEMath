// ===========================================================
// LEHalfVector2.h
// @brief 2Dimensions Half Vector 
// @author minseob
#include "LEHalfVector4.h"

namespace LEMath {
	template<> DataContainer::operator HalfVector4() const {
		return HalfVector4(
			GetFloatValue(0),
			GetFloatValue(1),
			GetFloatValue(2),
			GetFloatValue(3)
		);
	}
}