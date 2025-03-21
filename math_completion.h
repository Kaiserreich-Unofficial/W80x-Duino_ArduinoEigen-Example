#ifndef _MATH_COMPLETION_H_
#define _MATH_COMPLETION_H_
#include <Arduino.h>
#undef max
#undef min
#include <math.h>
#include <cmath>

#undef fabsl
inline long double fabsl(long double x)
{
  return (long double)fabs((double)x);
}

#undef signbit
namespace std
{
  inline bool signbit(float x) { return x < 0.0f; }
  inline bool signbit(double x) { return x < 0.0; }
  inline bool signbit(long double x) { return x < 0.0L; }
}

#undef isinf
namespace std
{
  inline bool isinf(float x) { return __builtin_isinf(x); }
  inline bool isinf(double x) { return __builtin_isinf(x); }
  inline bool isinf(long double x) { return __builtin_isinf(x); }
}

#undef isnan
namespace std
{
  inline bool isnan(float x) { return __builtin_isnan(x); }
  inline bool isnan(double x) { return __builtin_isnan(x); }
  inline bool isnan(long double x) { return __builtin_isnan(x); }
}

#undef isfinite
namespace std
{
  inline bool isfinite(float x) { return __builtin_isfinite(x); }
  inline bool isfinite(double x) { return __builtin_isfinite(x); }
  inline bool isfinite(long double x) { return __builtin_isfinite(x); }
}

#endif // _MATH_COMPLETION_H_
