#ifndef _GHOST_H_
#define _GHOST_H_

#include "Point.h"
#include "board.h"

class Ghost
{
    char figure = '&';
    int direction ;
    Point body[2];
    Color color;
    board b;

public:
    void move(char curr, char next);
    void setFigure(const char c)
    {
        figure = c;
    }
    void setColor(Color c)
    {
        color = c;
    }
    void setDirection(int dir)
    {
        direction = dir;
    }
    int getXbody(int i)
    {
        return body[i].getX();
    }
    int getYbody(int i)
    {
        return body[i].getY();
    }
    void setLocation(int i)
    {
        if (i == 0)
        {
            body[0].setX(60);
            body[0].setY(12);
            body[1].setX(60);
            body[1].setY(13);
        }
        else
        {
            body[0].setX(61);
            body[0].setY(19);
            body[1].setX(62);
            body[1].setY(19);
        }
    }

};

#endif
