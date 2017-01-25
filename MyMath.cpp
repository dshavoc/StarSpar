#include "MyMath.h"
#include <cmath>
#include <cstdlib>

float randFloatBetween(float a, float b) {
    return randFloat() * (b - a) + a;
}

float randFloat() {
    return (float)rand() / (float)RAND_MAX;
}

float lerp(float a, float b, float p) {
    return a + (b-a) * p;
}
