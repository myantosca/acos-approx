#ifndef __ACOS_NVIDIA_H
#define __ACOS_NVIDIA_H

#include <stdlib.h>
#include <math.h>

/// Source: https://developer.download.nvidia.com/cg/acos.html
///
/// | Handbook of Mathematical Functions
/// | M. Abramowitz and I.A. Stegun, Ed.
/// |
/// | Absolute error <= 6.7e-5
float acos_nvidia0(float x);

/// Iteration 1: Used self-multiply/add/subtract operators.
float acos_nvidia1(float x);

/// Iteration 2: Converted literals to single-precision.
float acos_nvidia2(float x);

/// Iteration 3: Reduced arithmetic by merging last subtraction and return operation.
float acos_nvidia3(float x);

/// Iteration 4: Try to induce the compiler to use FMA. Requires -march=native.
/// With -march=native, the assembly is the same as generated for acos_nvidia3.
float acos_nvidia4(float x);

/// Iteration 5: Move rotation predicate to end after storing the initial value of x.
float acos_nvidia5(float x);

#endif
