#include<iostream>

using namespace std;

class Vector{
public:
    Vector(){};
    Vector(float X,float Y,float Z) {
        x= X;
        y= Y;
        z= Z;
    }

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

float GetCurrentTime() {

}
void Update(float dt) {
    m.position + m.velocity * dt;
    m.velocity = m.velocity + m.gravity * dt;

    // KeepMWithinBorders(); just to keep in the border of the window
}
void main() {
    m.position = Point(0,0,0);
    m.velocity = Vector(2,2,0);
    m.gravity = Vector(0,-2,0);

    float flPreviousTime = 0;
    float flCurrentTime = GetCurrentTime();
    while(true){
        flPreviousTime = flCurrentTime;
        flCurrentTime = GetCurrentTime();

        float dt = flCurrentTime - flPreviousTime;

        if(dt > 0.15f) {
            dt = 0.15f;
        }
        Update(dt);
        Draw();
    }
}