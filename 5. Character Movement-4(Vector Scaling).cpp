#include <iostream>
#include <cmath>
using namespace std;

class Vector {
public:
    Vector() : x(0), y(0), z(0) {}
    Vector(float X, float Y, float Z) { //constructor
        x = X;
        y = Y;
        z = Z;
    }
    float Length() const;
    float Lengthsqr() const;

    Vector operator*(float s) const;  //overload
    Vector operator/(float s) const;  //overload

    float x,y,z;
};

class Point{
public:
    Point AddVector(Vector v);

    float x,y,z;
};

Vector Vector::operator*(float s) const {
    Vector scaled;
    scaled.x = x*s;
    scaled.y = y*s;
    scaled.z = z*s;
    return scaled;
}

Vector Vector::operator/(float s) const {
    Vector scaled;
    scaled.x = x/s;
    scaled.y = y/s;
    scaled.z = z/s;
    return scaled;
}
float Vector::Length() const {
    float length;
    length =  sqrt(x * x + y * y + z * z);
    return length;
}
float Vector::Lengthsqr() const {
    float length;
    length = (x * x + y * y + z * z);
    return length;
}
Vector operator-(Point a, Point b) {
    Vector v;
    v.x = a.x - b.x;
    v.y = a.y - b.y;
    v.z = a.z - b.z;
    return v;
}
Point Point::AddVector(Vector v) {
    Point p2;
    p2.x = x + v.x;
    p2.y = y + v.y;
    p2.z = z + v.z;
    return p2;
}

int main(int argc, char** args) {
    Vector v(3,4,5);
    std::cout<<"intinial speed: " << v.Length() <<  '\n';
    Vector doubled;
    doubled = v*2;
    std :: cout << "doubled speed: " << doubled.Length() << '\n';
    Vector halved;
    halved = v/2;
    std::cout << "halved speed: "<<halved.Length() << '\n';

}