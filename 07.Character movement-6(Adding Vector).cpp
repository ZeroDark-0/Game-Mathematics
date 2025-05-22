#include <iostream>

using namespace std;

class Vector {
public:
    Vector(){};
    Vector(float X,float Y,float Z) {
        x=X;
        y=Y;
        z=Z;
    }

    Vector operator+(const Vector& v)const;
    Vector operator-(const Vector& v)const;


    float x,y,z;
};

class Point {
public:
    Point() {};
    Point(float X,float Y,float Z) {
        x=X;
        y=Y;
        z=Z;
    }
    Point addVector(Vector v);
    float x,y,z;
};
Vector Vector::operator+(const Vector& v)const {
    Vector r;
    r.x = x + v.x;
    r.y = y + v.y;
    r.z = z + v.z;
    return r;
}
Vector Vector::operator-(const Vector& v)const {
    return Vector(x-v.x,y-v.y,z-v.z);
}

int main(int argc,char** agrs) {
    Vector r(4,0,5);
    Vector d(0,-5,1);
    Vector v = r+d;

    cout << "New velocity of character: "<< v.x << " : " << v.y << " : "<<v.z << endl;
}