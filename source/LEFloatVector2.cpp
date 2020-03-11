// ===========================================================
// LEFloatVector2.cpp
// @brief 2Dimensions Float Vector 
// @author minseob
#include "LEFloatVector2.h"

namespace LEMath {
    FloatVector2* DataContainer::ToFloatVector2(FloatVector2 *Output) const {
        Output->SetX(GetFloatValue(0));
        Output->SetY(GetFloatValue(1));
        return Output;
    }
}