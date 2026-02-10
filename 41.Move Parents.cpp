void CCharacter::SetMoveParent(CCharacter* pParent)
{
    if (m_hMoveParent.Get() == pParent)
        return;
    if (m_hMoveParent.Get()) {
        m_mGlobalTransform = GetGlobalTransform();
    }

    m_hMoveParent = pParent;
    if (!pParent)
        return;
    m_mLocalTranform = m_hMoveParent->GetGlobalTransform().InvertedTR() * m_mGlobalTransform;
}

const Matrix4x4 CCharacter::GetGlobalTransform() const
{
    if (m_hMoveParent.Get())
        return m_hMoveParent->GetGlobalTransform() * m_mLocalTransform;

    return m_mGlobalTransform;
}

void CCharacter::SetGlobalTransform(const Matrix4x4& mGlobal)
{
    if (m_hMoveParent.Get())
    {
        m_mLocalTransform =
            m_hMoveParent->GetGlobalTransform().InvertedTR() * mGlobal;
        return;
    }

    m_mGlobalTransform = mGlobal;
}
