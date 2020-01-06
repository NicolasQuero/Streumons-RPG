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
    SetConsoleOutputCP( 1252 ); // Pour afficher les accents dans le terminal

    Jeu j;
    j.afficherMiniMap();
    int k=-1;//definit s'ou on viens
    int turn = 0;
    Oueurj O = Oueurj();
    cout << endl << "***************** La partie débute *****************" << endl << endl;
    do{
        cout << endl << "********************** tour " << turn << " **********************" << endl << endl;
        int posX, posY;

        GameMap Map(&j);
        Map.creaPorte(Map.CleObtenu());

        if(k==2){posY=Map.getHauteur()-2,posX=(Map.getLongueur())/2;} // on vient d'en haut, on cree le joueur en bas

        else if(k==1){posY=1,posX=(Map.getLongueur())/2;}//... d'en bas,... en haut

        else if(k==4){posY=(Map.getHauteur())/2,posX=(Map.getLongueur())-2;}//... de gauche,... a gauche

        else if(k==3){posY=(Map.getHauteur())/2,posX=1;}//... de droite,... a droite

        else if(k==-1){posY=(Map.getHauteur())/2,posX=(Map.getLongueur())/2;}
        O.pos = Pos(posY, posX);
        Board board = Board(&Map,O);
        board.printMap();
        k = 0;
        while (k == 0) {
            k = board.playTurn();
            turn ++;
            cout << endl << "********************  tour " << turn << " ********************" << endl << endl;
            board.printMap();
        }
        switch (k) {
        case 1:
            j.deplacementMiniMapBas();
            break;
        case 2:
            j.deplacementMiniMapHaut();
            break;
        case 3:
            j.deplacementMiniMapDroite();
            break;
        case 4:
            j.deplacementMiniMapGauche();
            break;
        }

    }while(j.getNomMap()!="fin");
    cout<<"vous avez gagner";
    return 0;
}

