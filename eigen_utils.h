#ifndef _EIGEN_UTILS_H
#define _EIGEN_UTILS_H
#include <ArduinoEigenDense.h>

namespace Eigen
{
  // Template function to print matrix elements for floating point types
  template <typename Derived>
  void printMatrix(const Eigen::DenseBase<Derived> &m)
  {
    for (int i = 0; i < m.rows(); ++i)
    {
      Serial.print(F("["));
      for (int j = 0; j < m.cols(); ++j)
      {
        Serial.print(m(i, j));
        Serial.print(F(" "));
      }
      Serial.println(F("]"));
    }
  }
}
#endif // _EIGEN_UTILS_H
