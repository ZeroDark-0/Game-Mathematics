#include<iostream>
#include <vector>

using namespace std;

class CCharcater {
public:
    CCharcater(){
        flShotTime = -1;
    }
    void ShotEffect(CRenderingContext*c) {
        float flTime = (Game()->GetTime - flTime)*10;
        if(flShotTime < 0 || flTime>2*M_PI)
            return;

        Vector vecRotateX(cos(flTime), 0 , sin(flTime));
        Vector vecRotateY(0,1,0);
        Vector vecRotateZ(-sin(flTime),0,cos(flTime));

        Matrix4x4.mRotate(vecRotateX,vecRotateY,vecRotateZ);
        c->Transform(mRotation);
    }
public:
    Point vecPosition;
    Vector vecVelocity;
    float flSpeed;
    float flShotTime;
};