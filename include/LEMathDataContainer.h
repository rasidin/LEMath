/*********************************************************************
Copyright(c) 2020 LIMITGAME
Permission is hereby granted, free of charge, to any person
obtaining a copy of this softwareand associated documentation
files(the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify,
merge, publish, distribute, sublicense, and /or sell copies of
the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :
The above copyright noticeand this permission notice shall be
included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
----------------------------------------------------------------------
@file LEMathDataContainer.h
@brief Data containers
@author minseob (https://github.com/rasidin)
**********************************************************************/
#ifndef LEMATH_LEMATHDATACONTAINER_H_
#define LEMATH_LEMATHDATACONTAINER_H_

#include <LEMath>

namespace LEMath {
    struct DataContainer
    {
        union {
            struct { int iData[4]; };
            struct { float fData[4]; };
        };
        enum class DataType {
            Unknown = 0,
            Integer,
            Float
        } Type = DataType::Unknown;
        int DataCount = 0;

        bool IsValid() const { return Type != DataType::Unknown && DataCount > 0; }

        int GetIntValue(int Index) const {
            if (IsValid() == false || Index >= DataCount) return 0;
            if (Type == DataType::Integer) {
                return iData[Index];
            }
            else if (Type == DataType::Float) {
                return static_cast<int>(fData[Index]);
            }
			return 0;
        }
        float GetFloatValue(int Index) const {
            if (IsValid() == false || Index >= DataCount) return 0.0f;
            if (Type == DataType::Integer) {
                return static_cast<float>(iData[Index]);
            }
            else if (Type == DataType::Float) {
                return fData[Index];
            }
			return 0;
        }

		template<typename T> operator T() const;
    };
}

#endif // LEMATH_LEMATHDATACONTAINER_H_