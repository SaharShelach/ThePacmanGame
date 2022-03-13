#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include "io_utils.h"
#include "board.h"

using namespace std;

class Point
{
    int x = 1, y = 1;
public:
    void draw(char ch);
    void move(int direction);
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void setY(int a)
    {
        y = a;
    }
    void setX(int a)
    {
        x = a;
    }
};

#endif
