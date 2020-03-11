// ===========================================================
// LEIntVector3.cpp
// @brief 3Dimensions Int Vector 
// @author minseob
#include "LEIntVector3.h"

namespace LEMath {
    IntVector3* DataContainer::ToIntVector3(IntVector3 *Output) const {
        Output->SetX(GetIntValue(0));
        Output->SetY(GetIntValue(1));
        Output->SetZ(GetIntValue(2));
        return Output;
    }
} 