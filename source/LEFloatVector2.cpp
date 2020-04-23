// ===========================================================
// LEFloatVector2.cpp
// @brief 2Dimensions Float Vector 
// @author minseob
#include "LEFloatVector2.h"

namespace LEMath {
	const FloatVector2 FloatVector2::Zero = FloatVector2(0.0f, 0.0f);
	const FloatVector2 FloatVector2::One  = FloatVector2(1.0f, 1.0f);
	template<> DataContainer::operator FloatVector2() const {
		return FloatVector2(
			GetFloatValue(0),
			GetFloatValue(1)
		);
	}
}