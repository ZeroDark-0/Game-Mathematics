#include <iostream>
using namespace std;

class CCharacter {
public:
    CCharacter() {

    }
    Matrix4x4 mTransform;

    CRenderingContext c(pRenderer, true);



    c.SetUniform("vecColor", Vector4D(0.8f,0.4f,0.2,,1));
    //we are using one trnsform matrix to tranform every vector for the character
    c.Transform(box.Transform);

};