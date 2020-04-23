// ===========================================================
// LEFloatVector4.h
// @brief 4Dimensions Float Vector 
// @author minseob
#include "LEFloatVector4.h"

namespace LEMath {
	const FloatVector4 FloatVector4::Zero = FloatVector4(0.0f, 0.0f, 0.0f, 0.0f);
	const FloatVector4 FloatVector4::One  = FloatVector4(1.0f, 1.0f, 1.0f, 1.0f);

	template<> DataContainer::operator FloatVector4() const {
		return FloatVector4(
			GetFloatValue(0),
			GetFloatValue(1),
			GetFloatValue(2),
			GetFloatValue(3)
		);
	}
} 