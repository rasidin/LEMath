// ===========================================================
// LEIntVector2.cpp
// @brief 2Dimensions Integer Vector 
// @author minseob
#include "LEIntVector2.h"

namespace LEMath {
    const IntVector2 IntVector2::Zero = IntVector2(0, 0);
    const IntVector2 IntVector2::One = IntVector2(1, 1);

	template<> DataContainer::operator IntVector2() const {
		return IntVector2(GetIntValue(0), GetIntValue(1));
	}
}