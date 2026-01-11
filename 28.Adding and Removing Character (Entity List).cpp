#include <iostream>


bool CGame::TraceLine(const Vector& v0, const Vector& v1, Vector& vecIntersection, CCharacter*& pHit) {
    float flLowestFraction = 1;

    Vector vecTestIntersection;
    float flTestFraction;
    pHit = nullptr;

    for (size_t i = 0; i < MAX_CHARACTERS; i++)
    {
        CCharacter* pCharacter = GetCharacterIndex(i);
        if (!pCharacter)
            continue;

        // Only monsters and boxes get hit by traces. The player doesn't, he's immune to his own attacks.
        if (!pCharacter->m_bHitByTraces)
            continue;

        // The v0 and v1 are in the global coordinate system and we need to transform it to the target's
        // local coordinate system to use axis-aligned intersection. We do so using the inverse transform matrix.
        // http://youtu.be/-Fn4atv2NsQ
        if (LineAABBIntersection(pCharacter->m_aabbSize, pCharacter->m_mTransformInverse*v0, pCharacter->m_mTransformInverse*v1, vecTestIntersection, flTestFraction) && flTestFraction < flLowestFraction)
        {
            // Once we have the result we can use the regular transform matrix to get it back in
            // global coordinates. http://youtu.be/-Fn4atv2NsQ
            vecIntersection = pCharacter->m_mTransform*vecTestIntersection;
            flLowestFraction = flTestFraction;
            pHit = pCharacter;
        }
    }
}

// -----------------------------------

// now we see who can we create a Character, allocating in the array and then setting the parity number

CCharacter* CGame::CreateCharacter() {
    size_t iSpot = ~0;

    // Find a spot in my entity list that's empty.
    for (size_t i = 0; i < MAX_CHARACTERS; i++)
    {
        if (!m_apEntityList[i])
        {
            iSpot = i;
            break;
        }
    }

    if (iSpot == ~0)
        // Couldn't find a spot for the new guy! Return null instead.
            return nullptr;

    m_apEntityList[iSpot] = new CCharacter();

    static int iParity = 0;
    m_apEntityList[iSpot]->m_iParity = iParity++;
    m_apEntityList[iSpot]->m_iIndex = iSpot;

    return m_apEntityList[iSpot];
}

//------------------------------------------

//and here we can see who wee can delete the character and from the arrya and the parity number

void CGame::RemoveCharacter(CCharacter* pCharacter)
{
    size_t iSpot = ~0;

    // Find a spot in my entity list that's empty.
    for (size_t i = 0; i < MAX_CHARACTERS; i++)
    {
        if (m_apEntityList[i] == pCharacter)
        {
            iSpot = i;
            break;
        }
    }

    if (iSpot == ~0)
        // Couldn't find this guy in our entity list! Do nothing.
            return;

    delete m_apEntityList[iSpot];
    m_apEntityList[iSpot] = nullptr;
}
