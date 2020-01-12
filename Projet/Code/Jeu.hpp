#ifndef JEU_HPP_INCLUDED
#define JEU_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>

#include "Entities/Pos.hpp"
#include "FonctionUtile.hpp"
#include "TextOutput.hpp"


class Jeu
{
private:
    std::vector<std::vector<std::string> > m_emplacementMap; //permet de stocker le nom des map
    std::vector<std::vector<int> > m_miniMap;  //permet de connaitre si les map on deja ete visite (-1=vide, 0=map non visite, 1=visite, 2=le joueur est sur cette map)
    int m_posXj;  //position du joueur en X sur la miniMap
    int m_posYj;  //position du joueur en Y sur la miniMap
    std::vector<Pos> m_chargeur;  // liste les maps ou les chargeur ont ete pris

public:
    Jeu(int i);
    void startGame();
    void miniMap();
    int getTailleY();
    int getTailleX();
    std::string getNomMap(); //permet de savoir sur quelle map est le joueur
    int getValeurMiniMap(int posY,int posX); //permet de connaitre ou est le joueur sur la minimap
    int getPosXJoueur();
    int getPosYJoueur();
    bool presenceDeCle(); // permet de savoir si toute les salles adjacente on ete visite, si c'est le cas on pourra enlever les cle de cette salle
    bool chargeurRamasse(); //verifie si le chargeur a deja ete ramassé
    void addChargRamasse(); //ajoute les chargeur ramassé a la liste

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

    void manageStoryText();
};


#endif // JEU_HPP_INCLUDED
