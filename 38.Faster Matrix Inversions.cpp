
Matrix4x4 Matrix4x4::InvertedTR() const
{
    // This method can only be used if the matrix is a translation/rotation matrix.
    // The below asserts will trigger if this is not the case.
    TAssert(fabs(GetForwardVector().LengthSqr() - 1) < 0.00001f); // Each basis vector should be length 1.
    TAssert(fabs(GetUpVector().LengthSqr() - 1) < 0.00001f);
    TAssert(fabs(GetRightVector().LengthSqr() - 1) < 0.00001f);

    TAssert(fabs(GetForwardVector().Dot(GetUpVector())) < 0.0001f);   // All vectors should be orthogonal.
    TAssert(fabs(GetForwardVector().Dot(GetRightVector())) < 0.0001f);
    TAssert(fabs(GetRightVector().Dot(GetUpVector())) < 0.0001f);

    Matrix4x4 M;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            M.m[i][j] = m[j][i];

    M.SetTranslation(-(M * GetTranslation()));

    return M;
}
