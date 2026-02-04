

const Quaternion Quaternion::Slerp(const Quaternion& other, float t) const {
    const Quaternion& q = *this;
    Quaternion r = other;

    return ((r * Inverted()) ^ t) * q;
}

