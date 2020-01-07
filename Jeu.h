#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

#include "Entities/Pos.h"
#include "FonctionUtile.h"

class Jeu
{
private:
    std::vector<std::vector<std::string> > m_emplacementMap; //permet de stocker le nom des map
    std::vector<std::vector<int> > m_miniMap;  //permet de connaitre si les map on deja ete visite (-1=vide, 0=map non visite, 1=visite, 2=le joueur est sur cette map)
    int m_posXj;  //position du joueur en X sur la miniMap
    int m_posYj;  //position du joueur en Y sur la miniMap

public:
    Jeu();
    void startGame();
    void miniMap();
    int getTailleY();
    int getTailleX();
    std::string getNomMap(); //permet de savoir sur quelle map est le joueur
    int getValeurMiniMap(int posY,int posX); //permet de connaitre ou est le joueur sur la minimap
    int getPosXJoueur();
    int getPosYJoueur();

    void deplacementMiniMapGauche();
    void deplacementMiniMapDroite();
    void deplacementMiniMapHaut();
    void deplacementMiniMapBas();

    void deplacerJoueur(int NewValY,int NewValX);
    std::vector<int> MapVisite();
    void teleportation();

    void afficherMiniMap2(); //permet de voir les "dessous de la map" (inutile dans le jeu)
    void afficherMiniMap(); // permet d'afficher la miniMap pour le joueur
    void afficherSchemaJeu(); //permet d'afficher le miniMap entiere
};

#endif // JEU_H_INCLUDED
