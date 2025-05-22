#include <iostream>


//refer to this github -> ![](https://github.com/BSVino/MathForGameDevelopers/tree/lerping) //

#pragma once

float Approach(float flGoal, float flCurrent ,float dt) {
    float flDifference = flGoal - flCurrent;

    if(flDifference > dt) {
        return flCurrent + dt;
    }
    if(flDifference<-dt) {
        return flCurrent - dt;
    }
    return flGoal;
}
// the more the multiplication with dt in the Approach function the more responsive it be

//key input
bool CGame::KeyPress(int c)
{
    if (c == 'W')
    {
        box.vecVelocityGoal.z = 15;
        return true;
    }
    else if (c == 'A')
    {
        box.vecVelocityGoal.x = 15;
        return true;
    }
    else if (c == 'S')
    {
        box.vecVelocityGoal.z = -15;
        return true;
    }
    else if (c == 'D')
    {
        box.vecVelocityGoal.x = -15;
        return true;
    }
    else if (c == ' ')
    {
        box.vecVelocity.y = 2;
        return true;
    }
    else
        return CApplication::KeyPress(c);
}

