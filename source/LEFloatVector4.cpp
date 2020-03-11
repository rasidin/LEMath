// ===========================================================
// LEFloatVector4.h
// @brief 4Dimensions Float Vector 
// @author minseob
#include "LEFloatVector4.h"

namespace LEMath {
	const FloatVector4 FloatVector4::Zero = FloatVector4(0.0f, 0.0f, 0.0f, 0.0f);
	const FloatVector4 FloatVector4::One  = FloatVector4(1.0f, 1.0f, 1.0f, 1.0f);

    FloatVector4* DataContainer::ToFloatVector4(FloatVector4 *Output) const {
        Output->SetX(GetFloatValue(0));
        Output->SetY(GetFloatValue(1));
        Output->SetZ(GetFloatValue(2));
        Output->SetW(GetFloatValue(3));
        return Output;
    }
} 