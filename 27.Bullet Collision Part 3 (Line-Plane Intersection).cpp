#include <iostream>
class Vector {

};
bool LinePlaneItersection(const Vector& n,const Vector& c,const Vector& x0,const Vector& x1, Vector& vecIntersect) {
    Vector v =x1-x0;
    Vector w=c-x0;

    float k =w.Dot(n)/v.Dot(n);

    vecInterrestion = x0+k*v;

    flFraction = k;
    return k >= 0 && <=1;
}