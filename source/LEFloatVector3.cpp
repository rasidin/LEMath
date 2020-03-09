// ===========================================================
// LEFloatVector3.cpp
// @brief 4Dimensions Float Vector 
// @author minseob
#include "LEFloatVector3.h"

namespace LEMath {
    static const FloatVector3::Zero = FloatVector3(0.0f, 0.0f, 0.0f);
    static const FloatVector3::One  = FloatVector3(1.0f, 1.0f, 1.0f);
    bool DataContainer::ToFloatVector3(FloatVector3 *Output) const {
        Output->SetX(GetFloatValue(0));
        Output->SetY(GetFloatValue(1));
        Output->SetZ(GetFloatValue(2));
        return true;
    }
} 