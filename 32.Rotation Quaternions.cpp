#include <cmath>
#include <iostream>

Quaternions :: Quaternions(const Vector& n, float a) {
    //a is the theta
    //degree must be changed to radians
    a = a /360;

    w=cos(a/2);

    x = n.x * sin(a/2);
    y = n.y * sin(a/2);
    z = n.z * sin(a/2);
}