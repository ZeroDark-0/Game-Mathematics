#include<iostream>

//#include "quaternion.n"
// #pragma once
//
// #include "vector.h"
//
// class Quaternion
// {
// public:
//     Quaternion() {};
//     Quaternion(const Vector& n, float a);
//
// public:
//     const Quaternion Inverted() const;
//     const Quaternion operator*(const Quaternion& q) const;
//     const Vector operator*(const Vector& p) const;
//
// public:
//     float w;
//     Vector v; // x, y, z
// };


int main(int argc, char* argv[])
{
    Quaternion q1 = Quaternion(Vector(0, -1, 0), 90);
    Quaternion q2 = Quaternion(Vector(1, 0, 0), 45);
    Quaternion q3 = q2 * q1; // The first rotation should go last.

    printf("Quaternion 1: (%f, %f, %f, %f)\n", q1.w, q1.v.x, q1.v.y, q1.v.z);
    printf("Quaternion 2: (%f, %f, %f, %f)\n", q2.w, q2.v.x, q2.v.y, q2.v.z);
    printf("Quaternion 3, q2 * q1: (%f, %f, %f, %f)\n", q3.w, q3.v.x, q3.v.y, q3.v.z);

    std::string s;
    std::getline(std::cin, s);

    Vector vecRotated = q3 * Vector(1, 0, 0);
    printf("Rotating (1, 0, 0) with q3: (%f, %f, %f)\n",
           vecRotated.x, vecRotated.y, vecRotated.z);

    std::getline(std::cin, s);

    vecRotated = q1 * Vector(1, 0, 0);
    printf("Rotating (1, 0, 0) with q1: (%f, %f, %f)\n",
           vecRotated.x, vecRotated.y, vecRotated.z);

    std::getline(std::cin, s);

    vecRotated = q2 * vecRotated;
    printf("Rotating (0, 0, -1) with q2: (%f, %f, %f)\n",
           vecRotated.x, vecRotated.y, vecRotated.z);

    std::getline(std::cin, s);
}
