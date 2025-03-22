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

#undef round
namespace std
{
  // round: 将 x 四舍五入到最近的整数
  inline double round(double x)
  {
    return (x >= 0.0) ? floor(x + 0.5) : ceil(x - 0.5);
  }
  inline float round(float x)
  {
    return (x >= 0.f) ? floorf(x + 0.5f) : ceilf(x - 0.5f);
  }
}

#undef rint
namespace std
{
  // rint: 返回与 x 最近的整数值（这里简单调用 round 实现）
  inline double rint(double x)
  {
    return round(x);
  }
  inline float rint(float x)
  {
    return round(x);
  }
}

#undef expm1
namespace std
{
  // expm1: 计算 exp(x) - 1，对小 x 时使用级数展开提高精度
  inline double expm1(double x)
  {
    if (fabs(x) < 1e-5)
      return x + 0.5 * x * x;
    else
      return exp(x) - 1.0;
  }
  inline float expm1(float x)
  {
    if (fabsf(x) < 1e-5f)
      return x + 0.5f * x * x;
    else
      return expf(x) - 1.0f;
  }
}

#undef log1p
namespace std
{
  // log1p: 计算 log(1 + x)，对小 x 时使用级数展开
  inline double log1p(double x)
  {
    if (fabs(x) < 1e-5)
      return x - 0.5 * x * x;
    else
      return log(1.0 + x);
  }
  inline float log1p(float x)
  {
    if (fabsf(x) < 1e-5f)
      return x - 0.5f * x * x;
    else
      return logf(1.0f + x);
  }
}

#endif // _MATH_COMPLETION_H_
