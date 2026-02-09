
Matrix4x4 Matrix4x4::ConstructCameraView(
    const Vector& vecPosition,
    const Vector& vecDirection,
    const Vector& vecUp)
{
    TAssert(fabs(vecDirection.LengthSqr() - 1) < 0.0001f);

    Vector vecCamRight = CrossProduct(vecDirection, vecUp).Normalized();
    Vector vecCamUp    = CrossProduct(vecCamRight, vecDirection);

    Matrix4x4 R(vecCamRight, vecCamUp, -vecDirection, vecPosition);
    Matrix4x4 T;
    T.SetTranslation(vecPosition);

    return V.InvertedTR();  // no need of (T * R).InvertedTR();
}

Matrix4x4 Matrix4x4::operator+=(const Vector& v)
{
    m[3][0] += v.x;
    m[3][1] += v.y;
    m[3][2] += v.z;

    return *this;
}
