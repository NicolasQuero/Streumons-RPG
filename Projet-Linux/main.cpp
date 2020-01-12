#include <iostream>
#include <fstream>
#include <vector>

#include "Jeu.hpp"
#include "Entities/Oueurj.hpp"
#include "Board.hpp"
#include "GameMap.hpp"
#include "Entities/Pos.hpp"

using namespace std;



int main() {
    //SetConsoleOutputCP( 1252 ); // Pour afficher les accents dans le terminal

    Jeu j;
    j.startGame();

    return 0;
}
