#ifndef MYMATH_H
#define MYMATH_H

#include <cmath>

#define ROOT_3_BY_2     (0.866025404)
#define PI              (3.14159f)

extern const float DEG_TO_RAD;

float randFloat();
float randFloatBetween(float a, float b);
float sigmoid(float x, float k);
float lerp(float a, float b, float p);

#endif // MYMATH_H
