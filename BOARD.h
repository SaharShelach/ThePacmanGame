#ifndef _BOARD_H_
#define _BOARD_H_
#include "io_utils.h"
using namespace std;

class board
{
    enum {WIDTH=80, HEIGHT=24};
    char Board[HEIGHT][WIDTH];

public:
    void buildboard();
    void printboard();
    char getSymbol(int x, int y)
    {
        return Board[y][x];
    };
    void updatePos(int x, int y)
    {
        Board[y][x] = ' ';
    };

};
#endif
