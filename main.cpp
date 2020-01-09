#include <iostream>
#include <fstream>
#include <vector>

#include "Jeu.h"
#include "Entities/Oueurj.h"
#include "Board.h"
#include "GameMap.h"
#include "Entities/Pos.h"
#include <windows.h>
#pragma execution_character_set( "utf-8" )

using namespace std;



int main() {
    //SetConsoleOutputCP( 1252 ); // Pour afficher les accents dans le terminal

    Jeu j;
    j.startGame();
    return 0;
}

