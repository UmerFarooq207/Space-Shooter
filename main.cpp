#include <SFML/Graphics.hpp>
#include <time.h>
#include <fstream>
#include <iostream>
#include "game.h"

using namespace std;

int main()
{
    bool check = false;

    do {

        Game* g = new Game;

        string pname; 	// player name input
        cout << "\nEnter name: ";
        getline(cin, pname);

        g->start_game();

        check = g->playagain;

        //saving score in file-->File Handling

        fstream file;//obj to open file
        file.open("score.txt", ios::in | ios::out | ios::app);//file opened for both reading and writting
        file << g->score << "," << pname << endl;
        file.close();


        delete g;


    } while (check);



    return 0;
}


