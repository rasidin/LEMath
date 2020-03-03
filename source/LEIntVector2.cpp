// ===========================================================
// LEIntVector2.cpp
// @brief 2Dimensions Integer Vector 
// @author minseob
#include "LEIntVector2.h"

namespace LEMath {
    const IntVector2 IntVector2::Zero = IntVector2(0, 0);
    const IntVector2 IntVector2::One = IntVector2(1, 1);

    bool DataContainer::ToIntVector2(IntVector2 *Output) {
        if (!Output || !IsValid()) return false;
        Output->x = (*this)[0];
        Output->y = (*this)[1];
    }
}