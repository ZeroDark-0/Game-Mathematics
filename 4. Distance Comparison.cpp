#include <iostream>
#include <cmath>

//without the use of the squareroot function to find the length

class Vector {
public:
    float length() const;
    float lengthsqr() const;

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

Vector operator-(Point a, Point b) {
    Vector v;
    v.x = a.x - b.x;
    v.y = a.y - b.y;

    return v;
}

Point Point::AddVector(Vector v) {
    Point p2;
    p2.x = x + v.x;
    p2.y = y + v.y;
    p2.z = z + v.z;
    return p2;
}


int main (int argc, char** args) {
    Point p; // main point form we are calculating the distance
    p.x = 0;
    p.y = -1;
    p.z = 0;

    Point i; //position of i
    i.x = 1;
    i.y = 1;
    i.z = 0;

    Point c; //position of c
    c.x = 2;
    c.y = -1;
    c.z = 0;

    Vector cp;
    Vector ip;

    cp =p - c;
    ip = p - i;

    float length_sqr_cp = cp.lengthsqr();
    float length_sqr_ip = ip.lengthsqr();

    std :: cout <<"length squared of cp= "<< length_sqr_cp << std :: endl;
    std :: cout <<"length squared of ip= "<< length_sqr_ip << std :: endl;
}
