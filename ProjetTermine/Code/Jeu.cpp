#include "Jeu.hpp"
#include "Entities/Oueurj.hpp"
#include "Board.hpp"
#include "GameMap.hpp"


Jeu::Jeu(int i)
{
    std::string MAP_PATH;
    if (i==1)
    	MAP_PATH="Code/JeuCree/Demo.txt";
    else
	MAP_PATH="Code/JeuCree/Jeu.txt";
    std::ifstream flux(MAP_PATH.c_str()); //on ouvre en lecture la liste des nom de map et on affiche le nom des map existante.
    if(flux.is_open())
    {
        std::string Map;
        std::vector<std::string> vectString;
        while(getline(flux,Map))// on parcours toutes les map existante mais on affiche pas les maps "interdite"
        {
            if( Map == "---------------")
            {
                m_emplacementMap.push_back(vectString);
                vectString.clear();
            }
            else
            {
                vectString.push_back(Map);
            }
        }
        flux.close();
    }
    else{std::cout << "ERREUR: Impossible d'ouvrir en lecture le fichier de jeu cree." << std::endl;}
    this->miniMap();
}

void Jeu::startGame() {

    int k=-1;//definit d'ou on viens
    int turn = 0;
    cout << endl << "Vous vous reveillez en plein milieu d'une salle, votre but retrouver la sortie vivant !" << endl;
    cout << "comment voulez vous appeler votre personnage ?" << endl ;
    string nom;
    cin >> nom;
    Oueurj *O = new Oueurj(nom);
    cout << endl << "***************** La partie débute *****************" << endl << endl;
    do{
        int posX, posY;
        int nbDeChargeur= O->getTeleportsLeft();

        GameMap Map(this);
        Map.enleverCle(this->presenceDeCle()); //on regarde si il y a besoin des cle de la map
        Map.enlverCharg(this->chargeurRamasse());
        Map.creaPorte(Map.CleObtenu()); //on cree les portes (ouverte ou fermee)

        if(k==1){posY=1,posX=(Map.getLongueur())/2;}//... d'en bas,... en haut
        else if(k==2){posY=Map.getHauteur()-2,posX=(Map.getLongueur())/2;} // on vient d'en haut, on cree le joueur en bas
        else if(k==3){posY=(Map.getHauteur())/2,posX=1;}//... de droite,... a droite
        else if(k==4){posY=(Map.getHauteur())/2,posX=(Map.getLongueur())-2;}//... de gauche,... a gauche
        else if(k==-1){posY=(Map.getHauteur())/2,posX=(Map.getLongueur())/2;}

        O->pos = Pos(posY, posX);
        Board board = Board(&Map, O);
        do {
            std::system("clear");
	    this->afficherMiniMap();
            cout << endl << "********************** tour " << turn << " **********************" << endl << endl;
            board.printMap();
            manageStoryText();
            k = board.playTurn();
            turn ++;
        }while (k == 0);

        if (nbDeChargeur < O->getTeleportsLeft() && k!=-1)
            this->addChargRamasse();
        else if (nbDeChargeur == O->getTeleportsLeft() && k==-1)
            this->addChargRamasse();

        switch (k) {
        case 1:
            this->deplacementMiniMapBas();
            break;
        case 2:
            this->deplacementMiniMapHaut();
            break;
        case 3:
            this->deplacementMiniMapDroite();
            break;
        case 4:
            this->deplacementMiniMapGauche();
            break;
        case -1:
            this->teleportation();
            break;
        }

    }while(this->getNomMap()!="fin" && O->isAlive());
    if(O->isAlive())
    {
        cout<<"Bravo ! Vous avez gagné !" << endl;
        O->enregistrerScore();
        O->afficherScore();
    }
    else
        cout << "Vous avez perdu..." << endl;
    delete O;
}

void Jeu::miniMap() // cree un tableau identique que m_emplacementMap avec valeur -1 si il y a rien,0 si il y a une map
//1 si elle a ete deja visite,2 si le joueur est dessus
{
    std::vector<int> vectInt;
    for(int x=0 ; x < getTailleX()+2 ; x++)
    {
        vectInt.push_back(-1);
    }
    m_miniMap.push_back(vectInt);
    for(int y=0; y<getTailleY();y++)
    {
        std::vector<int> vectInt;
        vectInt.push_back(-1);
        for(int x=0;x<getTailleX();x++)
        {
            if(m_emplacementMap[y][x].substr(0,6)=="Depart")
            {
                vectInt.push_back(2);
                m_posXj=x+1;
                m_posYj=y+1;
            }
            else if(m_emplacementMap[y][x].substr(0,7)!="       "){vectInt.push_back(0);}
            else (vectInt.push_back(-1));
        }
        vectInt.push_back(-1);
        m_miniMap.push_back(vectInt);
    }
    m_miniMap.push_back(vectInt);
}

int Jeu::getTailleX()
{
    return m_emplacementMap[0].size();
}

int Jeu::getTailleY()
{
    return m_emplacementMap.size();
}

int Jeu::getPosXJoueur()
{
    return m_posXj;
}

int Jeu::getPosYJoueur()
{
    return m_posYj;
}

bool Jeu::presenceDeCle()
{
    bool cle = false;
    if(getValeurMiniMap(getPosYJoueur()+1,getPosXJoueur())!=0 && getValeurMiniMap(getPosYJoueur()-1,getPosXJoueur())!=0 &&
       getValeurMiniMap(getPosYJoueur(),getPosXJoueur()+1)!=0 && getValeurMiniMap(getPosYJoueur(),getPosXJoueur()-1)!=0) //si les map au alentour on deja ete visite, la cle est inutile
    {
        cle = true;
    }
    return cle;
}

bool Jeu::chargeurRamasse()
{
    bool chargeur = false;
    int LongM_Chargeur=m_chargeur.size();
    for (int i=0;i<LongM_Chargeur;i++)
    {
        if(m_chargeur[i].y == getPosXJoueur() && m_chargeur[i].x == getPosYJoueur())
            chargeur = true;
    }
    return chargeur;
}

void Jeu::addChargRamasse()
{
    m_chargeur.push_back(Pos(getPosYJoueur(),getPosXJoueur()));
}

std::string Jeu::getNomMap() //permet de savoir sur quelle map est le joueur
{
    return m_emplacementMap[m_posYj-1][m_posXj-1];
}

int Jeu::getValeurMiniMap(int posY,int posX) //permet de connaitre ou est le joueur sur la minimap
{
    return m_miniMap[posY][posX];
}


void Jeu::deplacementMiniMapGauche()
{
    m_miniMap[m_posYj][m_posXj]=1; // le joueur n'est plus sur la map,mais elle a ete visite
    m_miniMap[m_posYj][m_posXj-1]=2; //nouvelle map ou est le joueur
    m_posXj=m_posXj-1; //changement des coordonnees du joueur
}

void Jeu::deplacementMiniMapDroite()
{
    m_miniMap[m_posYj][m_posXj]=1;
    m_miniMap[m_posYj][m_posXj+1]=2;
    m_posXj=m_posXj+1;
}

void Jeu::deplacementMiniMapHaut()
{
    m_miniMap[m_posYj][m_posXj]=1;
    m_miniMap[m_posYj-1][m_posXj]=2;
    m_posYj=m_posYj-1;
}

void Jeu::deplacementMiniMapBas()
{
    m_miniMap[m_posYj][m_posXj]=1;
    m_miniMap[m_posYj+1][m_posXj]=2;
    m_posYj=m_posYj+1;
}

std::vector<int> Jeu::MapVisite()
{
    std::vector<int> ListeMapVisite;
    for(int y=0; y<getTailleY()+2;y++)
    {
        for(int x=0;x<getTailleX()+2;x++)
        {
            if(m_miniMap[y][x]>0)
                {
                    ListeMapVisite.push_back(y);
                    ListeMapVisite.push_back(x);
                }
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
    return ListeMapVisite;
}

void Jeu::deplacerJoueur(int NewValY,int NewValX)
{
    m_miniMap[m_posYj][m_posXj]=1;
    m_posXj=NewValX;
    m_posYj=NewValY;
    m_miniMap[m_posYj][m_posXj]=2;
}

void Jeu::teleportation()
{
    int NbMapVisite=MapVisite().size()/2;
    srand(time(NULL));
    int alea = rand()%NbMapVisite;
    deplacerJoueur(MapVisite()[alea*2],MapVisite()[alea*2+1]);
}

void Jeu::afficherMiniMap()
{
    std::cout<<std::endl<<"***Mini Map***"<<std::endl<<std::endl;
    for(int x=0; x<getTailleX();x++){std::cout<<"    "<<x+1<<"    ";}
    std::cout<<std::endl<<std::endl;
    for(int y=1; y<getTailleY()+1;y++)
    {
        for(int x=1;x<getTailleX()+1;x++)
        {
            if (m_miniMap[y][x]==2){std::cout<<".***J***.";}//presence du joueur
            else if((m_miniMap[y-1][x]>0||m_miniMap[y][x-1]>0||m_miniMap[y+1][x]>0||m_miniMap[y][x+1]>0||m_miniMap[y][x]>0) && m_miniMap[y][x]!=-1)
            {
                std::cout<<".*******.";
            }
            else(std::cout<<".       .");
        }
        std::cout<<"   "<<y<<std::endl;
    }
}

void Jeu::afficherMiniMap2()
{
    for(int y=0; y<getTailleY()+2;y++)
    {
        for(int x=0;x<getTailleX()+2;x++)
        {
            std::cout<<m_miniMap[y][x];
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
}


void Jeu::afficherSchemaJeu()
{
    for(int x=0; x<getTailleX();x++)
    {
        std::cout<<"    "<<x<<"    ";
    }
    std::cout<<std::endl<<std::endl;
    for(int y=0; y<getTailleY();y++)
    {
        for(int x=0;x<getTailleX();x++)
        {
            std::cout<<"."<<(m_emplacementMap[y][x]+"       ").substr(0,7)<<".";
        }
        std::cout<<"   "<<y<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
}

void Jeu::manageStoryText() {
    if (!TextOutput::isEmpty()) {
        cout << endl << TextOutput::getText();
        TextOutput::clearText();
    }
}

Jeu::~Jeu() {}

