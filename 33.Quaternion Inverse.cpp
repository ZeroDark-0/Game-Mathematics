#include <iostream>

const Quaternion Quaternion::Inverse() const {
    Quaternion q;
    q.w = w;
    q.x = -x;
    q.y = -y;
    q.z = -z;
    return q;
}