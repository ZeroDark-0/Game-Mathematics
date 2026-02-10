// The easy way to do it. We're going to do it the hard way!
// m_hMerryGoRound->SetRotation(EAngle(0, Game()->GetTime() * 20, 0));

// How much do we want to spin the merry go round?
Matrix4x4 mSpin;
mSpin.SetRotation(dt * 50, Vector(0, 1, 0));

// The location of the merry go round.
Matrix4x4 mTranslation;
mTranslation.SetTranslation(
    m_hMerryGoRound->m_mTransform.GetTranslation()
);

// The rotation of the merry go round will be the transform matrix,
// with the translation part zeroed out.
Matrix4x4 mRotation = m_hMerryGoRound->m_mTransform;
mRotation.SetTranslation(Vector(0, 0, 0));

Matrix4x4 mNewMGRTransform = mTranslation * mSpin * mRotation;
Matrix4x4 mNewToyBoxTransform = m_hMerryGoRound->m_mTransform * mTransform
    * mSpin *m_hMerryGoRound->m_mTransform.InvertedTR() * m_hToyBox->m_mTransform;

m_hMerryGoRound->m_mTransform = mNewMGRTransform;
m_hToyBox->m_mTransform = mNewToyBoxTransform;
