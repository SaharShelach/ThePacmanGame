//#include <Windows.h>
#include <iostream>

using namespace std;

#include "THE_PACMAN_GAME.h"

int main()
{
    ThePacmanGame game;
    int userSel;
    bool Setcolor;
    cout << "Welcome to PACMAN GAME!\nplease select:" <<endl;
    cout << "1.Start a new game\n8.Present instructions and keys\n9.EXIT" <<endl;
    cin >> userSel;
    while (userSel != 1 && userSel != 8 && userSel != 9)
    {
        cout << "Wrong key! Pless choose again:" << endl;
        cin >> userSel;
    }
    switch (userSel)
    {
        case 1:
        {
            cout << "Press 1 to play with colors or 0 to play without colors: " << endl;
            cin >> Setcolor;
            if (Setcolor == true)
            {
                system("CLS");
                game.init();
                game.run();
            }
            else
            {
                game.init();
                game.run();
            }
        }break;
        case 8:
        {
            cout << "To play the PACMAN game use the folowing keys: " << endl;
            cout << "a or A : LEFT\nd or D : RIGHT\nw or W : UP\nx or X : DOWN\ns or S : STAY" << endl;
        }break;
        case 9:
            break;
//	default:
//		break;
    }

}
