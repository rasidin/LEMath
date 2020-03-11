// ===========================================================
// LEMathDataContainer.h
// @brief Data container for cast
// @author minseob
#include <LEMath>
#pragma once

namespace LEMath {
    struct DataContainer
    {
        friend IntVector2;
        friend IntVector3;
        friend IntVector4;
        friend FloatVector2;
        friend FloatVector3;
        friend FloatVector4;

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
            return 0.0f;
        }

        IntVector2*   ToIntVector2(IntVector2 *Output) const;
        IntVector3*   ToIntVector3(IntVector3 *Output) const;
        IntVector4*   ToIntVector4(IntVector4 *Output) const;
        FloatVector2* ToFloatVector2(FloatVector2 *Output) const;
        FloatVector3* ToFloatVector3(FloatVector3 *Output) const;
        FloatVector4* ToFloatVector4(FloatVector4 *Output) const;
    };
}