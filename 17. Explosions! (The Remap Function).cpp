#include <iostream>

float Approach(float flGoal,float flCurrent, float dt) {
    float flDifference = flGoal - flCurrent;

    if(flDifference > dt) {
        return flCurrent + dt;
    }
    if(flDifference < -dt) {
        return flCurrent;
    }
    return flGoal;
}

float Remap(float x, float t1, float t2, float s1, float s2) {
    float yellow = (x-t1)/(t2-t1);

    float green = yellow*(s2-s1) + s1;
    return green;
}