// ===========================================================
// LEMathDataContainer.h
// @brief Data container for cast
// @author minseob
#include <LEMath>
#pragma once

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
        }
        float GetFloatValue(int Index) const {
            if (IsValid() == false || Index >= DataCount) return 0.0f;
            if (Type == DataType::Integer) {
                return static_cast<float>(iData[Index]);
            }
            else if (Type == DataType::Float) {
                return fData[Index];
            }
        }

		template<typename T> operator T() const;
    };
}