#include <iostream>

//this code is for the second character approaching the first character with different position

//this will give the different between the two vector of the characters
class vector {
public:
    double x{}, y{}, z{};
};

//assigning the first and the second character to this class
class point{
public:
    point addvector(vector v);
    double x{}, y{}, z{};
};

vector operator-(point a,point b) {
    vector v;
    v.x = a.x - b.x;
    v.y = a.y - b.y;
    v.z = a.z - b.z;

    return v;
}

int main() {
    point p; //point of first character
    p.x = 2;
    p.y = 3;
    p.z = 4;

    point i; //point of second character
    i.x = 1;
    i.y = 2;
    i.z = 3;

    vector v; // this shows the direction of the second character to the first
    v = p - i; // the "-" sign is working as the overloading of the two function

    std :: cout << "[x: " << v.x <<", y: " << v.y << ", z: " << v.z <<"]" << std :: endl;

}