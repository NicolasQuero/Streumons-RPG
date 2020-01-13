#ifndef CREAMAP_HPP_INCLUDED
#define CREAMAP_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "FonctionUtile.hpp"

class creaMap {

private:

    std::vector<std::string> mapStrings;
    int m_hauteur;
    int m_longueur;
    bool m_chargeur;

public:

    creaMap();
    creaMap(std::string nomMap);
    ~creaMap();

    int getLongueur()const;
    int getHauteur()const;
    std::string getMapStrings(int i)const;

    void afficherMap()const;
    void creaMur(); //creation de mur
    void creaMurVertical(int valY,int valX);
    void creaMurHorizontal(int valY,int valX);
    void choixChoses(const std::string chose);//creation de chose peut prendre les valeurs :" Diamants, Streumons, Chargeurs" et cree les objets
    void creaChoses(const std::string chose,std::string choix);
    void modifierValeurMap(char a, int posX,int posY); //modifie un caractere en X,Y
    void ajouterElement();

    void choixNomMap() const;
    void enregistrerMap(std::string nomMap)const;

};

#endif // CREAMAP_HPP_INCLUDED
