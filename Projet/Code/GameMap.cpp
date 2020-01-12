#include "GameMap.hpp"

using namespace std;

GameMap::GameMap(Jeu *miniMap) {
    std::string nomMap= miniMap->getNomMap();
    std::string MAP_PATH="Code/Map/"+nomMap+".txt";
    std::ifstream flux(MAP_PATH.c_str()); //on ouvre en lecture la liste des nom de map et on affiche le nom des map existante.
    if(flux)
    {
        int i=0;
        std::string Ligne;
        while(getline(flux,Ligne))// on parcours toutes les map existante mais on affiche pas les maps "interdite"
        {
            mapStrings.push_back(Ligne);
            i++;
        }
        m_hauteur=i;
        flux.close();
    }
    else{std::cout << "ERREUR: Impossible d'ouvrir en lecture le fichier de Map cree." << std::endl;}
    m_porteH=-1;
    m_porteB=-1;
    m_porteG=-1;
    m_porteD=-1;
    savePorte(miniMap);
}

void GameMap::savePorte(Jeu *miniMap)
{
    if(miniMap->getValeurMiniMap(miniMap->getPosYJoueur()-1,miniMap->getPosXJoueur())!=-1)
        m_porteH=miniMap->getValeurMiniMap(miniMap->getPosYJoueur()-1,miniMap->getPosXJoueur());
    if(miniMap->getValeurMiniMap(miniMap->getPosYJoueur()+1,miniMap->getPosXJoueur())!=-1)
        m_porteB=miniMap->getValeurMiniMap(miniMap->getPosYJoueur()+1,miniMap->getPosXJoueur());
    if(miniMap->getValeurMiniMap(miniMap->getPosYJoueur(),miniMap->getPosXJoueur()-1)!=-1)
        m_porteG=miniMap->getValeurMiniMap(miniMap->getPosYJoueur(),miniMap->getPosXJoueur()-1);
    if(miniMap->getValeurMiniMap(miniMap->getPosYJoueur(),miniMap->getPosXJoueur()+1)!=-1)
        m_porteD=miniMap->getValeurMiniMap(miniMap->getPosYJoueur(),miniMap->getPosXJoueur()+1);
}

vector<string> GameMap::getMapStrings() const { return mapStrings; }

int GameMap::getLongueur()
{
    m_longueur=mapStrings[0].size();
    return m_longueur;
}

int GameMap::getHauteur()
{
    return m_hauteur;
}

char GameMap::getCharGameMap(int Y,int X)
{
    return mapStrings[Y][X];
}

Pos GameMap::getPortesPos(char c) {
    switch(c) {
    case 'h':
        return Pos(0, getLongueur()/2);
        break;
    case 'd':
        return Pos(getHauteur()/2, getLongueur()-1);
        break;
    case 'b':
        return Pos(getHauteur()-1, getLongueur()/2);
        break;
    case 'g':
        return Pos(getHauteur()/2, 0);
        break;
    }
    return Pos(-1,-1);
}

//C:\Users\user\Desktop\Streumons-RPG-master\GameMap.cpp
Pos GameMap::getClePos()
{
    Pos posCle;
    for(int i=0; i<this->getHauteur(); i++)
    {
        for(int j=0; j <this->getLongueur();j++)
            if(mapStrings[i][j]=='D'){posCle=Pos(j,i);}
    }
    return posCle;
}

Pos GameMap::getChargPos()
{
    Pos posCharg;
    for(int i=0; i<this->getHauteur(); i++)
    {
        for(int j=0; j <this->getLongueur();j++)
            if(mapStrings[i][j]=='C'){posCharg=Pos(j,i);}
    }
    return posCharg;
}

void GameMap::modifierValeurGameMap(char a, int posY,int posX) // modifie le charactere en X Y par 'a'
{
    this->mapStrings[posY][posX]=a;
}

void GameMap::enleverCle(bool cle)
{
    if (cle ==true)
        modifierValeurGameMap(' ',getClePos().y,getClePos().x);
}

void GameMap::enlverCharg(bool charg)
{
    if (charg == true)
        modifierValeurGameMap(' ',getChargPos().y,getChargPos().x);
}

bool GameMap::CleObtenu()
{
    cle_obtenue=true;
    for(int i=0; i<this->getHauteur(); i++)
    {
        for(int j=0; j <this->getLongueur();j++)
            if(mapStrings[i][j]=='D'){cle_obtenue=false;}
    }
    return cle_obtenue;
}

void GameMap::creaPorte(bool cle)
{
    if(m_porteH!=-1)
    {
        creaPorteHaut(m_porteH,cle);
    }
    if(m_porteB!=-1)
    {
        creaPorteBas(m_porteB,cle);
    }
    if(m_porteG!=-1)
    {
        creaPorteGauche(m_porteG,cle);
    }
    if(m_porteD!=-1)
    {
        creaPorteDroite(m_porteD,cle);
    }
}

void GameMap::creaPorteHaut(int val,bool cle)
{
    char porte;
    if (val==0 && cle==false){porte='X';}
    else{porte=' ';}
    this->modifierValeurGameMap(porte,0,(this->getLongueur())/2);
    bool j=false;
    int i=1;
    while(j!=true)
    {
        if(mapStrings[i][((getLongueur())/2)-1]=='#'&& mapStrings[i][(getLongueur())/2]=='#'&&mapStrings[i][((getLongueur())/2)+1]=='#')
        {
            this->modifierValeurGameMap(' ',i,(this->getLongueur()/2));
            i++;
        }
        else(j=true);
    }
}

void GameMap::creaPorteBas(int val,bool cle)
{
    char porte;
    if (val==0 && cle==false){porte='X';}
    else{porte=' ';}
    this->modifierValeurGameMap(porte,this->getHauteur()-1,(this->getLongueur())/2);
    bool j=false;
    int i=1;
    while(j!=true)
    {
        if(mapStrings[this->getHauteur()-1-i][((getLongueur())/2)-1]=='#'&&mapStrings[this->getHauteur()-1-i][(getLongueur())/2]=='#'&&mapStrings[this->getHauteur()-1-i][((getLongueur())/2)+1]=='#')
        {
            this->modifierValeurGameMap(' ',this->getHauteur()-1-i,(this->getLongueur())/2);
            i++;
        }
        else(j=true);
    }
}

void GameMap::creaPorteGauche(int val,bool cle)
{
    char porte;
    if (val==0 && cle==false ){porte='X';}
    else{porte=' ';}
    this->modifierValeurGameMap(porte,(this->getHauteur())/2,0);
    bool j=false;
    int i=1;
    while(j!=true)
    {
        if(mapStrings[(getHauteur()/2)-1][i]=='#'&&mapStrings[getHauteur()/2][i]=='#'&&mapStrings[(getHauteur()/2)+1][i]=='#')
        {
            this->modifierValeurGameMap(' ',(this->getHauteur())/2,i);
            i++;
        }
        else(j=true);
    }
}

void GameMap::creaPorteDroite(int val,bool cle)
{
    bool j=false;
    char porte;
    if (val==0 && cle==false){porte='X';}
    else{porte=' ';}
    this->modifierValeurGameMap(porte,(this->getHauteur())/2,this->getLongueur()-1);
    int i=1;
    while(j!=true)
    {
        if(mapStrings[(getHauteur()/2)-1][getLongueur()-1-i]=='#'&&mapStrings[getHauteur()/2][getLongueur()-1-i]=='#'&&mapStrings[(getHauteur()/2)+1][getLongueur()-1-i]=='#')
        {
            this->modifierValeurGameMap(' ',(this->getHauteur())/2,this->getLongueur()-1-i);
            i++;
        }
        else(j=true);
    }
}

void GameMap::afficherGameMap()
{
    std::cout<<std::endl;
    for(int i=0; i<this->getHauteur(); i++)
    {
        for(int j=0; j <this->getLongueur();j++)
            std::cout<<mapStrings[i][j]<<" ";
        std::cout<<std::endl;
    }
}
