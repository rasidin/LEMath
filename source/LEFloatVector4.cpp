// ===========================================================
// LEFloatVector4.h
// @brief 4Dimensions Float Vector 
// @author minseob
#include "LEFloatVector4.h"

namespace LEMath {
	const FloatVector4 FloatVector4::Zero = FloatVector4(0.0f, 0.0f, 0.0f, 0.0f);
	const FloatVector4 FloatVector4::One  = FloatVector4(1.0f, 1.0f, 1.0f, 1.0f);

    bool DataContainer::ToFloatVector4(FloatVector4 *Output) {
        Output.x = GetFloatValue(0);
        Output.y = GetFloatValue(1);
        Output.z = GetFloatValue(2);
        Output.w = GetFloatValue(3);
        return true;
    }
} 