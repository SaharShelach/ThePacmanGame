#ifndef _THEPACMANGAME_H_
#define _THEPACMANGAME_H_

#include "io_utils.h"
#include "Pacman.h"
#include "board.h"
#include "Ghost.h"

class ThePacmanGame
{
    enum { ESC = 27 };
    Pacman p;
    Ghost g[2];
    int score =0;
    int life = 3;
    board GameBoard;
    bool GhostSpeed = false;

public:
    void init();
    void run();
    void checkMeeting(char PacPos, char GPosCur1, char GposCur2, char GPosNext1, char GPosNext2);
};

#endif
