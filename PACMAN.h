#ifndef _PACMAN_H_
#define _PACMAN_H_

#include "Point.h"
#include "board.h"

class Pacman
{
    char figure = '@';//צריך?
    int direction = 1;
    char arrowkeys[10];
    Point body[2];
    Color color;

public:
    int getDirection(char key);
    void move();
    void setArrowKeys(const char* keys)
    { // "wWxXaAdDsS
        arrowkeys[0] = keys[0];
        arrowkeys[1] = keys[1];
        arrowkeys[2] = keys[2];
        arrowkeys[3] = keys[3];
        arrowkeys[4] = keys[4];
        arrowkeys[5] = keys[5];
        arrowkeys[6] = keys[6];
        arrowkeys[7] = keys[7];
        arrowkeys[8] = keys[8];
        arrowkeys[9] = keys[9];
    }
    void setDirection(int dir)
    {
        direction = dir;
    }
    void setFigure(const char c)
    {
        figure = c;
    }
    void setColor(Color c)
    {
        color = c;
    }
    int getXbody(int i)
    {
        return body[i].getX();
    }
    int getYbody(int i)
    {
        return body[i].getY();
    }
    void SetYbody( int y)
    {
        body[1].setY(y);
    }
    void SetXbody(int x)
    {
        body[1].setX(x);
    }
};

#endif
