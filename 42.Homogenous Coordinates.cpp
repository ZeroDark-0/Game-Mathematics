Vector Matrix4x4::operator*(const Vector& v) const
{
    // [ a b c x ][X]
    // [ d e f y ][Y] = [aX+bY+cZ+x  dX+eY+fZ+y  gX+hY+iZ+z]
    // [ g h i z ][Z]
    //            [1]

    Vector vecResult;
    vecResult.x = m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z + m[3][0];
    vecResult.y = m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z + m[3][1];
    vecResult.z = m[0][2] * v.x + m[1][2] * v.y + m[2][2] * v.z + m[3][2];
    return vecResult;
}

Vector Matrix4x4::TransformDirection(const Vector& v) const
{
    // [ a b c ][X]
    // [ d e f ][Y] = [aX+bY+cZ  dX+eY+fZ  gX+hY+iZ]
    // [ g h i ][Z]

    Vector vecResult;
    vecResult.x = m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z;
    vecResult.y = m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z;
    vecResult.z = m[0][2] * v.x + m[1][2] * v.y + m[2][2] * v.z;
    return vecResult;
}
