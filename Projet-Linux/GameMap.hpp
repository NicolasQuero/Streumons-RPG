#ifndef GAMEMAP_HPP_INCLUDED
#define GAMEMAP_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>

#include "Jeu.hpp"
#include "Entities/Pos.hpp"


using namespace std;

class GameMap {
protected:
    vector<string> mapStrings;
    int m_hauteur;
    int m_longueur;
    bool cle_obtenue;
    int m_porteH;
    int m_porteB;
    int m_porteG;
    int m_porteD;
public:

    GameMap(Jeu *j);
    vector<string> getMapStrings() const;

    void savePorte(Jeu *j);
    int getLongueur();
    int getHauteur();
    void afficherGameMap();
    char getCharGameMap(int Y,int X);
    void modifierValeurGameMap(char a,int posY,int posX);
    void prendreCle() { cle_obtenue = true; }
    bool CleObtenu();
    Pos getPortesPos(char c);
    void enleverCle(bool cle);
    void enlverCharg(bool charg);
    Pos getClePos();
    Pos getChargPos();
    void creaPorte(bool cle=false);
    void creaPorteHaut(int val,bool cle);// val=0 carte non visite (porte fermée) val!=0 carte visite( porte ouverte)
    void creaPorteBas(int val,bool cle);// 'X' porte fermee
    void creaPorteGauche(int val,bool cle);
    void creaPorteDroite(int val,bool cle);
};



#endif // GAMEMAP_HPP_INCLUDED
