#include "board.h"
#include <iostream>


void board::buildboard()
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (j == 0 || j == (WIDTH - 1))
                Board[i][j] = '|';
            if (i == 0 || i == (HEIGHT - 1))
                Board[i][j] = '-';
            if ((i == 16 && j == 0) || (i == 16 && j == WIDTH - 1))
                Board[i][j] = ' ';
            if ((i == 6 && j == 0) || (i == 6 && j == WIDTH - 1))
                Board[i][j] = ' ';
            //building walls
            if (i == 2 && (j > 5 && j < 19))
                Board[i][j] = '-';
            if (i == 12 && (j > 1 && j < 24))
                Board[i][j] = '-';
            if (i == 8 && (j > 62 && j < 79))
                Board[i][j] = '-';
            if (i == 20 && (j > 30 && j < 54))
                Board[i][j] = '-';
        }
    }
    //Adding food to the board
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (Board[i][j] != ' ' && Board[i][j] != '|' && Board[i][j] != '-')
            {
                Board[i][j] = '*';
            }
        }
    }
}

void board::printboard()
{
    buildboard();
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (Board[i][j] == '*')
            {
                setTextColor(Color::BLUE);
                cout << Board[i][j];
                setTextColor(Color::WHITE);
            }
            else
                cout << Board[i][j];
        }
        cout << endl;
    }
    cout << "LIFE:3";
    cout << "                     SCORE:0";
}
