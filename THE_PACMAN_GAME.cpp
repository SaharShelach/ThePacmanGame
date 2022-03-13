#include "THE_PACMAN_GAME.h"

void ThePacmanGame::init()
{
    GameBoard.printboard();
    p.setArrowKeys("wWzZaAdDsS");
    p.setColor(Color::YELLOW);
    p.setFigure('@');
    p.setDirection(1);
    g[0].setLocation(0);
    g[1].setLocation(1);
    g[0].setColor(Color::RED);
    g[0].setDirection(2);
    g[0].setFigure('&');
    g[1].setColor(Color::RED);
    g[1].setDirection(5);
    g[1].setFigure('&');
}

void ThePacmanGame::run()
{
    char key = 0;
    int dir=1;
    do {
        if (_kbhit())
        {
            key = _getch();
            if (key == ESC)
            {
                gotoxy(0, 26);
                setTextColor(GREEN);
                cout << "press ESC again to continue";
                key = _getch();
                while (key != ESC)
                {
                    key = _getch();
                }
            }
            gotoxy(0, 26);
            cout << "                                  ";
            if ((dir = p.getDirection(key)) != -1)
                p.setDirection(dir);
        }

        int nextPosX = p.getXbody(1);
        int nextPosY = p.getYbody(1);
        char PacPos = GameBoard.getSymbol(nextPosX,nextPosY);
        char GPosCur1 = GameBoard.getSymbol(g[0].getXbody(0), g[0].getYbody(0));
        char GposCur2 = GameBoard.getSymbol(g[1].getXbody(0), g[1].getYbody(0));
        char GPosNext1 = GameBoard.getSymbol(g[0].getXbody(1), g[0].getYbody(1));
        char GposNext2 = GameBoard.getSymbol(g[1].getXbody(1), g[1].getYbody(1));
        if (PacPos == '*')
        {
            score++;
            gotoxy(33, 24);
            setTextColor(WHITE);
            cout << score;
            GameBoard.updatePos(p.getXbody(0), p.getYbody(0));
        }
        else if (PacPos == '-' || PacPos == '|')
        {
            dir = 4;
            p.setDirection(dir);
            key = _getch();
            if ((dir = p.getDirection(key)) != -1)
                p.setDirection(dir);

        }
        p.move();
        if (GhostSpeed == true)
        {
            g[0].move(GPosCur1, GPosNext1);
            g[1].move(GposCur2, GposNext2);
            GhostSpeed = false;
            checkMeeting(PacPos, GPosCur1, GposCur2,GPosNext1,GposNext2);
        }
        else
            GhostSpeed = true;

        checkMeeting(PacPos, GPosCur1, GposCur2, GPosNext1, GposNext2);
        Sleep(200);
    } while (score!=1624 && life!=0);

    setTextColor(Color::WHITE);
    if (score == 1624)
    {
        system("CLS");
        cout << "YOU WON! CONGRATULATIONS!";
    }
    if (life == 0)
    {
        setTextColor(Color::RED);
        system("CLS");
        cout << "GAME OVER!!";
    }
//	clear_screen();
}

void ThePacmanGame::checkMeeting(char PacPos, char GPosCur1, char GposCur2,char GPosNext1,char GPosNext2)
{
    if ((g[0].getXbody(0) == p.getXbody(0) && g[0].getYbody(0) == p.getYbody(0)) || (g[1].getXbody(0) == p.getXbody(0) && g[1].getYbody(0) == p.getYbody(0)))
    {
        life--;
        gotoxy(5, 24);
        setTextColor(WHITE);
        cout << life;
        gotoxy(p.getXbody(0), p.getYbody(0));
        cout << PacPos;
        setTextColor(BLUE);
        gotoxy(g[0].getXbody(0), g[0].getYbody(0));
        cout << GPosCur1;
        gotoxy(g[1].getXbody(0), g[1].getYbody(0));
        cout << GposCur2;
        p.SetXbody(1);
        p.SetYbody(1);
        p.move();
        g[0].setLocation(0);
        g[1].setLocation(1);
        g[0].move(GPosCur1, GPosNext1);
        g[1].move(GposCur2, GPosNext2);
    }
}
