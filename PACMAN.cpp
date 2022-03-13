#include "Pacman.h"

int Pacman::getDirection(char key)
{
    for (int i = 0; i < 10; i++)
    {
        if (key == arrowkeys[i])
            return i;
    }
    return -1;
}

void Pacman::move()
{
    if (body[1].getX() == 0 || body[1].getX() == 79 )
    {
        if (body[1].getY() != 6 && body[1].getY() != 16)
            body[1] = body[0];
    }
    if (body[1].getY()==0 || body[1].getY()==23)
    {
        body[1] = body[0];
    }
    if (body[1].getY() == 2 && (body[1].getX() < 19 && body[1].getX() > 5))
    {
        body[1] = body[0];
    }
    if (body[1].getY() == 12 && (body[1].getX() < 24 && body[1].getX() > 1))
    {
        body[1] = body[0];
    }
    if (body[1].getY() == 8 && (body[1].getX() < 79 && body[1].getX() > 62))
    {
        body[1] = body[0];
    }
    if (body[1].getY() == 20 && (body[1].getX() < 54 && body[1].getX() > 30))
    {
        body[1] = body[0];
    }
    else
    {
        body[0].draw(' ');
        body[0] = body[1];
    }
    body[1].move(direction);
    setTextColor(color);
    body[0].draw('@');
}


