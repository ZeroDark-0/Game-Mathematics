#pragma once

class Vector;

class EAngle {
public:
    EAngle() {
         p = y = r = 0;
    }

    EAngle(float pitch, float yaw, float roll) {
        p = pitch;
        y = yaw;
        r = roll;
    }

public:
    Vector ToVector() const;

    void Normalize();

    float p,y,r;
};

//--------------------------

#include<cmath>

Vector EAngle::ToVector() const {
    Vector result;
    result.x = cos(y) * cos(p);
    result.y = sin(p);
    result.z = sin(y);

    return result;
}

void EAngle::Normalize() {
    if(p>89) {
        p = 89;
    }
    if(p<-89) {
        p = -89;
    }

    while(y<-180) {
        y+=360;
    }
    while(y>180) {
        y-=360;
    }
}

