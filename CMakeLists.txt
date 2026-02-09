cmake_minimum_required(VERSION 3.28)
project(Game_Mathematics)

set(CMAKE_CXX_STANDARD 23)

add_executable(Game_Mathematics main.cpp
        "01.Character movement-1(using vector and physics).cpp"
        "02.Character movement-2 (between two individual vectors).cpp"
        "03.Character movement-3(Distance between the two character in vector).cpp"
        "04. Distance Comparison.cpp"
        "05. Character Movement-4(Vector Scaling).cpp"
        "06.Character movement-5(Unit-Length Vectors).cpp"
        "07.Character movement-6(Adding Vector).cpp"
        "08.DoubleAction Source Code.txt"
        "09. - 10 Backstabbing (Dot Product).cpp"
        "09. - 10 Backstabbing (Dot Product).cpp"
        "11.Jumping and Gravity (Time Delta, Game Loop).cpp"
        "12.Smooth Move(ment) (Linear Interpolation).cpp"
        "13.Mouse Control (Euler Angles).cpp"
        "14.Character Movement 7 (Cross Product).cpp"
        "15-16.Bullet Collision (Vector-AABB Intersection).cpp"
        "17. Explosions! (The Remap Function).cpp"
        "18.Bullet Whizzes (Projections)"
        "19. Billboarding (Basis Vectors).cpp"
        "20. Character Movement 8 (Matrices).cpp"
        "21. Big Boss Enemy (Matrix Scaling).cpp"
        "22.Rotating Characters (Matrix Rotation).cpp"
        "23.Character Movement 9 (Matrix Translation).cpp"
        "24.Prop Positioning (TRS Matrices).cpp"
        "25-26.Updated Bullet Collisions 1-2 (Coordinate Systems).cpp"
        "27.Bullet Collision Part 3 (Line-Plane Intersection).cpp"
        "28.Adding and Removing Character (Entity List).cpp"
        "29.Frustum Culling.cpp"
        "30.Drawing Transparent Character {Mergesort}.cpp"
        "31.Axis-Angle Rotation.cpp"
        "32.Rotation Quaternions.cpp"
        "33.Quaternion Inverse.cpp"
        "34.Multiplying Quaternion - 35.Quaternion and Vectors.cpp"
        "36.Slerping Quaternions - 37.Quaternion Wrapup and Review.cpp"
        "38.Faster Matrix Inversions.cpp"
        "39.The Camera View Transform Matrix.cpp"

)

