#include <iostream>
#include "FonctionUtile.hpp"
#include "creaMap.hpp"
#include "creaJeu.hpp"

using namespace std;

void creeUneMap();
void creeUnJeu();

int main()
{
    cout<<endl<<"Bienvenue dans l'outil de creation du jeu" <<endl;
    bool i=false;
    do
    {
        cout<<"voulez vous cree une map ou cree un jeu a partir de map deja existante ?" <<endl;
        cout<<"cree un map :(m), cree un jeu:(j) ou quitter le l'outil de creation:(q)" <<endl;
        char jOUm=demandeAouB("j","m","q");
        if(jOUm=='m')
        {
            creeUneMap();
        }
        else if(jOUm=='j')
        {
            creeUnJeu();
        }
        else
        {
            cout<<"Merci d'avoir utiliser l'outil de creation de jeu" <<endl;
            i=true;
        }
    }while(i==false);
    return 0;
}


void creeUnJeu()
{
    cout<< endl << "Bienvenue dans la creation de Jeu" << endl <<endl;
    creaJeu j;
    j.creaMiniMap();
    j.enregistrerJeu();
}

void creeUneMap()
{
    std::cout<< std::endl << "Bienvenue dans la creation de Map" << std::endl <<std::endl;
    creaMap a;  // cree un objet creaMap (cardre de la map de taille Lxl)
    a.ajouterElement(); //ajoute les element (mur, monstre ....)
    a.afficherMap();
    a.choixNomMap(); // on choisit le nom de la map puis, la map sera enregistree sous se nom
}
