#include <iostream>
#include <fstream>
#include <vector>

#include "Jeu.hpp"
#include "Entities/Oueurj.hpp"
#include "Board.hpp"
#include "GameMap.hpp"
#include "Entities/Pos.hpp"
//#include <windows.h>
//#pragma execution_character_set( "utf-8" )

using namespace std;



int main() {
    //SetConsoleOutputCP( 1252 ); // Pour afficher les accents dans le terminal

    Jeu j;
    j.startGame();

    return 0;
}
