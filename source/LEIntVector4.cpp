// ===========================================================
// LEIntVector4.cpp
// @brief 4Dimensions Integer Vector 
// @author minseob

#include "LEIntVector4.h"

namespace LEMath
{
	IntVector4* DataContainer::ToIntVector4(IntVector4 *Output) const {
		Output->SetX(GetIntValue(0));
		Output->SetY(GetIntValue(1));
		Output->SetZ(GetIntValue(2));
		Output->SetW(GetIntValue(3));
        return Output;
	}
}