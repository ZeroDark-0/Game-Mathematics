#include<iostream>
#include <vector>

using namespace std;
class Vector {

};

class box {
public:
    void SetTransform(const Vector& vecScaling, float flTheta,const Vector& vecRotationAxis, const Vector& vecTranslation) {
        Matrix4x4 mScaling,mRotation, mTranslation;
        mScaling.SetScaling(vecScaling);
        mRotation.SetRotation(flTheta,vecRotationAxis);
        mTransform.SetTranslation(vecTranslation);
        mTransform = mTranslation*mRotation*mScaling;

        Matrix4x4 mScalingInverse, mRotationInverse, mTranslationInverse;
        mScalingInverse.SetScale(1/vecScaling);
        mRotationInverse = mRotation.Traposed();
        mTranslationInverse.SetTranslation(-vecTranslation);
        mTransformInverse = mScalingInverse * mRotationInverse *mTranslationInverse;
    }

    float mTransform;
    float mTransformInverse;
    float mRotationInverse;
    vector<int,int> Matrix4x4;
};