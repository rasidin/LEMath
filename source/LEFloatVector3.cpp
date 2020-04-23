// ===========================================================
// LEFloatVector3.cpp
// @brief 4Dimensions Float Vector 
// @author minseob
#include "LEFloatVector3.h"

namespace LEMath {
	template<> DataContainer::operator FloatVector3() const {
		return FloatVector3(
			GetFloatValue(0),
			GetFloatValue(1),
			GetFloatValue(2)
		);
	}
} 