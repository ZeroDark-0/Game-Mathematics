#include <cmath>
#include <iostream>
#include <math.h>

const Vector RotateVectorAroundAxisAngle(const Vector& n, float a, const Vector& v) {
// a is your theta
    return v*cos(a) + (v.Dot(n)*n) * (1 - cos(a) + (n.Cross(v)*sin(a)));
}