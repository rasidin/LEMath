// ===========================================================
// LEFloatVector3.cpp
// @brief 4Dimensions Float Vector 
// @author minseob
#include "LEFloatVector3.h"

namespace LEMath {
    bool DataContainer::ToFloatVector3(FloatVector3 *Output) const {
        Output->SetX(GetFloatValue(0));
        Output->SetY(GetFloatValue(1));
        Output->SetZ(GetFloatValue(2));
        return true;
    }
} 