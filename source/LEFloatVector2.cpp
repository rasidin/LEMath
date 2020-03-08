// ===========================================================
// LEFloatVector2.cpp
// @brief 2Dimensions Float Vector 
// @author minseob
#include "LEFloatVector2.h"

namespace LEMath {
    bool DataContainer::ToFloatVector2(FloatVector2 *Output) {
        Output->x = GetFloatValue(0);
        Output->y = GetFloatValue(1);
        return true;
    }
}