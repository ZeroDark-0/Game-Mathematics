using namespace std;
#pragma once
#include <iostream>

Vector.vecXBasis(1,0,0);
Vector.vecYBasis(0,1,0);
Vector.vecZBasis(0,0,1);

Matrix4x4.mBossMatrix(vecxBasis*3, vecYBasis&*3, vecZBasis*3);

target3.vecPosition = Point(-5,0,0);
target3.aabbSize.vecMin = mBossMatrix*vecMonsterMin;
taget.aabbSize.vecMax = mBossMatrix*vecMonsterMax;
