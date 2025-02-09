
#include <iostream>
//moving the character from one postion to another

//moves our character to the next position
class vector{
public:
    double x{}, y{}, z{};
};

//position vector of the character
class point{
public:
    point addvector(vector v);
    double x{}, y{}, z{};
};
//adding both the vector
point point::addvector(vector v) {
    point new_position;
    new_position.x = x + v.x;
    new_position.y = y + v.y;
    new_position.z = z + v.z;

    return new_position;
}


int main() {
    point p;//default position
    p.x = 1;
    p.y = 0;
    p.z = 1;

    vector v;//move by this
    v.x = 1;
    v.y = 2;
    v.z = 1;

    point new_position = p.addvector(v);
    std :: cout << "New position of the vector are: "
                   "[x: " << new_position.x << ", y: " << new_position.y << ", z: " << new_position.z << "]" << std :: endl;

}


