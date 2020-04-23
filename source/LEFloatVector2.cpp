// ===========================================================
// LEFloatVector2.cpp
// @brief 2Dimensions Float Vector 
// @author minseob
#include "LEFloatVector2.h"

namespace LEMath {
	template<> DataContainer::operator FloatVector2() const {
		return FloatVector2(
			GetFloatValue(0),
			GetFloatValue(1)
		);
	}
}