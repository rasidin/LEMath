// ===========================================================
// LEFloatVector3.cpp
// @brief 4Dimensions Float Vector 
// @author minseob
#include "LEFloatVector3.h"

namespace LEMath {
    const FloatVector3 FloatVector3::Zero = FloatVector3(0.0f, 0.0f, 0.0f);
    const FloatVector3 FloatVector3::One  = FloatVector3(1.0f, 1.0f, 1.0f);
    FloatVector3* DataContainer::ToFloatVector3(FloatVector3 *Output) const {
        Output->SetX(GetFloatValue(0));
        Output->SetY(GetFloatValue(1));
        Output->SetZ(GetFloatValue(2));
        return Output;
    }
} 