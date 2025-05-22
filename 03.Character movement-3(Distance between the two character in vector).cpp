#include <iostream>
#include <cmath>

class vector {
public:
    float Length() const; // this function help us to calculate the length between the two character or vectors

    float x, y, z;
};

class point{
public:
    point addvector(vector v);

    float x, y, z;
};

float vector::Length() const {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}


vector operator-(point a,point b) {
    vector v;
    v.x = a.x - b.x;
    v.y = a.y - b.y;
    v.z = a.z - b.z;

    return v;
}

int main() {
    point p; //point of first character
    p.x = 0;
    p.y = -1;
    p.z = 0;

    point i; //point of second character
    i.x = 1;
    i.y = 1;
    i.z = 0;

    vector v;
    v = i - p; //overloading operator which calculate the difference

    float length = v.Length();
    std :: cout << "Length: " << length << std :: endl;
}