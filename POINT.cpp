#include "Point.h"

void Point::draw(char ch)
{
    gotoxy(x, y);
    cout << ch << endl;
}

void Point::move(int dir)
{
    switch (dir)
    {
        case 0: // UP
            --y;
            if (y < 1)
            {
                y = 23;
            }
            break;
        case 1: // UP
            --y;
            if (y < 1)
            {
                y = 23;
            }
            break;
        case 2: // DOWN
            ++y;
            if (y > 23)
            {
                y = 1;
            }
            break;
        case 3: // DOWN
            ++y;
            if (y > 23)
            {
                y = 1;
            }
            break;
        case 4: // LEFT
            --x;
            if (x < 1)
            {
                x = 79;
            }
            break;
        case 5: // LEFT
            --x;
            if (x < 1)
            {
                x = 79;
            }
            break;
        case 6: // RIGHT
            ++x;
            if (x > 79)
            {
                x = 1;
            }
            break;
        case 7: // RIGHT
            ++x;
            if (x > 79)
            {
                x = 1;
            }
            break;
        case 8: //stop
            break;
        case 9://stop
            break;
    }
}

