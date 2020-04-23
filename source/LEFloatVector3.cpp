// ===========================================================
// LEFloatVector3.cpp
// @brief 4Dimensions Float Vector 
// @author minseob
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