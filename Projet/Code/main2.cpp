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

	cout << endl << "Bienvenue dans le Jeu" << endl;
	cout << "a quel jeu voulez vous jouer ?" << endl<< endl;
	cout <<"1) la Demo" << endl << "2) le jeu personnalise" << endl;
	int i = demandeInt(1,2);
	Jeu j(i);
	j.startGame();

    return 0;
}
