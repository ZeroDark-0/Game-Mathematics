DrawCharacters(m_apRenderOpaqueList, false);

for (size_t i = 0; i < MAX_CHARACTERIndex(i)) {
    CCharacter* pCharacter = GetCharacterIndex(i);
    if (!pCharacter)
        continue;
    if (!pCharacter -> m_bEnemyAI)
        continue;
    float flRadius = 3.5f;

    Vector vecIndicatorOrigin = NearestPointOnSphere(m_hPlayer->GetGlobalOrigin(), flRadius, PCharcater -> GetGlobal)

    float flBoxSi = 0.1f;

    r.SetUniform("vectorColor", Color(255,0,0,255));
    r.RenderBox(vecIndicatorOrigin - Vector(1,1,1)*flBoxSize, vecIndicatorOrigin + Vector(1,1,1)*flBoxSize);
}

// Collision Function

bool LinePlaneIntersection(
    const Vector& n,      // plane normal
    const Vector& c,      // any point on the plane
    const Vector& x0,     // line start
    const Vector& x1,     // line end
    Vector& vecIntersection,
    float& fraction
) {
    Vector v = x1 - x0;
    Vector w = c - x0;

    float denom = v.Dot(n);
    if (denom == 0.0f)    // line parallel to plane
        return false;

    float k = w.Dot(n) / denom;

    vecIntersection = x0 + k * v;
    fraction = k;

    return k >= 0.0f && k <= 1.0f;
}
