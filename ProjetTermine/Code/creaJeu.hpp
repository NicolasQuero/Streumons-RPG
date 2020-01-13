#ifndef CREAJEU_HPP_INCLUDED
#define CREAJEU_HPP_INCLUDED


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "FonctionUtile.hpp"
#include "creaMap.hpp"

class creaJeu {
private:
    std::vector<std::vector<std::string> > m_listeMiniMap;
public:

    creaJeu();
    ~creaJeu();

    int getTailleX();
    int getTailleY();

    std::string choixMapAjoute(); //on choisit quelle map ajouter au jeu
    void choixMapAdjacente(std::string MapImposee = ""); // on selection un map a partir de la quelle on va ajouter une nouvelle map

    void creaMiniMap();//fonction principal, permet e cree la minimap qui servira a sauvegarder le chemins entre les maps

    void ajoutMap(std::string Map,int posX,int posY,char direction); //envoie la map dans un des fontion en dessous
    void ajoutADroite(std::string Map,int posX,int posY, int tailleX,int tailleY); // on ajoute la map choisie a droite sur la minimap
    void ajoutAGacuhe(std::string Map,int posX,int posY, int tailleX,int tailleY,std::vector<std::string> p1);// on ajoute la map choisie a gauche sur la minimap
    void ajoutEnHaut(std::string Map,int posX,int posY, int tailleX,int tailleY,std::vector<std::string> p1);// on ajoute la map choisie en haut sur la minimap
    void ajoutEnBas(std::string Map,int posX,int posY, int tailleX,int tailleY,std::vector<std::string> p1);// on ajoute la map choisie en bas sur la minimap
    void choixDirection(int posX,int posY,std::string MapImposee=""); //choisit l'emplacement ou on met la map selectione avec choixMapAjoute() par rapport a la map selectione avec
    void validationChoix(std::string Map,std::vector<std::vector<std::string> > copieListeMiniMap);// laisse la possibilite de changer la map si elle ne conveint pas

    void enregistrerJeu();
    std::vector<std::string> afficherListeMap();
    void afficherMiniMap();

};


#endif // CREAJEU_HPP_INCLUDED
