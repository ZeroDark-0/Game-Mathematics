#include <iostream>

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
float dotProduct(const Vector& a, const Vector& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector v; //the entity that is about to get hit (blue player)
Vector br; // br = (pPlayer -> GetAbsOrigin() - pHitEntity -> GetAbsOrigin());
//also pPlayer is the R player which gonna hit the blue player
//br is the vector from the hit object (B  player) the R player
// and after that we normalized it
//always use normalized vector for dot product
int main() {
    // main function
    if(dotProduct(v, br) < -0.5f) {
        float f1damage = 99999; // the dmg while backstabbing...
    }
    /* why -0.5 ? -> because when i vector pointing in opposite direction the product will be -1
     * but if the vectors are almost opposite direction then the dot product will be like -0.8(with the wiggle)
     */
}