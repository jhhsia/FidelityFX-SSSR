/**********************************************************************
Copyright (c) 2020 Advanced Micro Devices, Inc. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
********************************************************************/
#pragma once

#include <cmath>
#include <cstdint>

namespace ffx_sssr
{
    /**
        The tfloat3 class represents a generic 3-wide vector.
    */
    template<typename TYPE>
    class tfloat3
    {
    public:
        inline tfloat3();
        inline tfloat3(TYPE v);
        inline tfloat3(TYPE x, TYPE y, TYPE z, TYPE w = static_cast<TYPE>(0));
        template<typename OTHER_TYPE>
        inline tfloat3(tfloat3<OTHER_TYPE> const& other);

        inline tfloat3 operator -() const;
        inline tfloat3 operator /(TYPE f) const;
        inline TYPE& operator [](std::uint32_t i);
        inline TYPE operator [](std::uint32_t i) const;

        inline TYPE sqnorm() const;
        inline TYPE norm() const;

        static inline tfloat3 normalize(tfloat3 const& v);

        // The vector X component.
        TYPE x;
        // The vector Y component.
        TYPE y;
        // The vector Z component.
        TYPE z;
        // The vector W component.
        TYPE w;
    };

    /**
        A type definition for a single precision floating-point 3-wide vector.
    */
    typedef tfloat3<float> float3;

    /**
        A type definition for a double precision floating-point 3-wide vector.
    */
    typedef tfloat3<double> double3;

    /**
        A type definition for a single precision floating-point 4-wide vector.
    */
    typedef float3  float4;

    /**
        A type definition for a double precision floating-point 4-wide vector.
    */
    typedef double3 double4;
}

#include "float3.inl"
