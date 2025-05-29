#include <iostream>
#include <cmath>
class Vector {
public:
    float length() const;
    float lengthsqr() const;
    Vector Dot() const;
    Vector Cross() const;

    float x, y, z;
};

class Point {
public:
    Point AddVector(Vector v);

    float x, y, z;
};

float Vector::length() const {
    return sqrt(x * x + y * y + z * z);
}

float Vector::lengthsqr() const {
    return (x * x + y * y + z * z);
}
Vector Vector::Dot(const Vector& v)const {
    return x*v.x + y*v.y +z*v.z;
}
Vector Vector::Cross(const Vector& v)const {
    Vector c;
    c.x =y*v.z - z*v.y;
    c.y =z*v.x - x*v.z;
    c.z =x*v.y - y*v.x;

    return c;

}


// for combining the camera with the movement keys using cross product