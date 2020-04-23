// ===========================================================
// LEIntVector3.cpp
// @brief 3Dimensions Int Vector 
// @author minseob
#include "LEIntVector3.h"

namespace LEMath {
	template<> DataContainer::operator IntVector3() const {
		return IntVector3(
		GetIntValue(0),
		GetIntValue(1),
		GetIntValue(2)
		);
	}
} 