#include "Ghost.h"

void Ghost::move(char curr,char next)
{
    if (body[1].getX() == 1)
    {
        body[1] = body[0];
        direction = 6;
        body[1].move(direction);
        setTextColor(RED);
        body[0].draw('&');
    }
    if (body[1].getX() == 78)
    {
        body[1] = body[0];
        direction = 5;
        body[1].move(direction);
        setTextColor(RED);
        body[0].draw('&');
    }
    if (body[1].getY() == 1)
    {
        body[1] = body[0];
        direction = 2;
        body[1].move(direction);
        setTextColor(RED);
        body[0].draw('&');
    }
    if (body[1].getY() == 23)
    {
        body[1] = body[0];
        direction = 1;
        body[1].move(direction);
        setTextColor(RED);
        body[0].draw('&');
    }
    if (curr == '*')
    {
        setTextColor(BLUE);
        body[0].draw('*');
        body[0] = body[1];
        body[1].move(direction);
        setTextColor(color);
        body[0].draw('&');
    }
    else
    {
        setTextColor(BLUE);
        body[0].draw(' ');
        body[0] = body[1];
        body[0].move(direction);
        setTextColor(color);
        body[0].draw('&');
    }
}
