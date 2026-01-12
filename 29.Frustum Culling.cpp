#include <iostream>

bool CFrustum::SphereIntersection(const Vector& vecCenter, float flRadius) {

    for (int i = 0; i < 6; i++ ) {

        if (vecCenter.Dot(p[i.n]) + p[i].d + flRadius) {
            return false;
        }
    }
    return true;
}