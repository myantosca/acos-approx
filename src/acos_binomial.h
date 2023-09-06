#ifndef __ACOS_BINOMIAL_H
#define __ACOS_BINOMIAL_H

#include <stdlib.h>
#include <math.h>

/// Source: https://en.wikipedia.org/wiki/Inverse_trigonometric_functions#Infinite_series
///
/// This function approximates acos using the identity π/2 - arcsin(x).
/// arcsin(x) is approximated with the binomial series described in the source:
///
///                 ( 1 )    x^3     ( 1 * 3 )    z^5    ( 1 * 3 * 5 )    z^7
/// arcsin(x) = x + ----- * -----  + --------- * ----- + ------------- * ----- + ...
///                 ( 2 )     3      ( 2 * 4 )     5     ( 2 * 4 * 6 )     7
///
/// The absolute error increases rapidly in the ranges [-1, -0.5] and [0.5, 1].
///
/// `rounds` indicates how many terms in the series to use besides the first `x` term.
/// `rounds` is clamped to [0, 30) since higher values yield NaN due to single-precision limits.
float acos_binomial(float x, int rounds);

#endif
