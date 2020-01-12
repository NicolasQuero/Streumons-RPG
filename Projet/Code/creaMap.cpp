#include "creaMap.hpp"

creaMap::creaMap()//cree la base de la map
{
    m_chargeur = false;
    std::cout << "De quelle longueur voulez vous votre Map? (Axe des X)"<< std::endl << "(valeur de 5 a 50)"<<std::endl;
    int longMap;
    longMap=demandeInt(5,50);
    std::cout << "De quelle hauteur voulez vous votre Map? (Axe des Y)" << std::endl << "(valeur de 5 a 50)"<<std::endl; // on cree les deux valeurs qui seront la taille de la map
    int hautMap;
    hautMap=demandeInt(5,50);
    m_longueur=longMap; // on enregistre la longueur de la map
    m_hauteur=hautMap;// on enregistre la hauteur de la map
    std::string creationLigne[hautMap];
    for (int i(0);i<hautMap;i++)
    {
        for (int j(0);j<longMap;j++)
        {
            if(j==0 || i==0 || i==hautMap-1 || j==longMap-1)
                creationLigne[i]+="#";
            else
                creationLigne[i]+=" ";
        }
        mapStrings.push_back(creationLigne[i]);
    }
    afficherMap();
}

creaMap::creaMap(std::string nomMap)// cree une map a partir d'un fichier txt
{
    std::string MAP_PATH="Map/"+nomMap+".txt";
    std::ifstream flux(MAP_PATH.c_str());
    if(flux)
    {
        int i=0;
        while(getline(flux,MAP_PATH))
        {
            mapStrings.push_back(MAP_PATH);
            i++;
        }
        m_longueur=mapStrings[0].size();
        m_hauteur=i;
        flux.close();
    }
    else{std::cout << "ERREUR: Impossible d'ouvrir en lecture le fichier de la Map." << std::endl;}
}


creaMap::~creaMap()
{
}

int creaMap::getLongueur()const
{
    return m_longueur;
}

int creaMap::getHauteur()const
{
    return m_hauteur;
}

std::string creaMap::getMapStrings(int i)const
{
    return mapStrings[i];
}

void creaMap::afficherMap()const
{
    std::cout<< std::endl;
    for(int j(0);j< this->getLongueur();j++)
    {
        if (j<9)
            std::cout<<j+1<<"  ";
        else
            std::cout<<j+1<<" ";
    }
    std::cout<<std::endl<<std::endl;
    for(int i(0);i< this->getHauteur();i++)
    {
        for(int j(0);j<this->getLongueur();j++)
            std::cout<<this->getMapStrings(i)[j]<<"  ";
        std::cout<<i+1<<std::endl;
    }
    std::cout<< std::endl;
}


void creaMap::creaMur()//on demande si le joueur veut cree des murs sur la map, puis on les construits.
{
    std::vector<std::string> copieMapStrings=mapStrings;
    std::cout << "voulez vous creer des murs supplementaires dans la salle ? (attention de ne pas vous enfermer)" << std::endl << "(oui (o) ou non (n))"<<std::endl;
    std::string oOUn;
    oOUn=demandeAouB("o","n");
    if (oOUn=="n")
        std::cout << "tres bien, passons a l'etape suivante" << std::endl;
    else
    {
        std::cout << "voulez vous creer des murs horizontaux ou verticaux ?" << std::endl << "(horizontaux (h) ou verticaux(v))"<<std::endl;
        std::string hOUv;
        hOUv=demandeAouB("h","v");
        std::cout << "a quelle position en X voulez vous creer le debut de votre mur ?" << std::endl <<"valeur de 2 a "<< getLongueur()-1 << std::endl;
        int valX = demandeInt(2,getLongueur()-1);
        std::cout << "a quelle position en Y voulez vous creer le debut de votre mur ?" << std::endl <<"valeur de 2 a "<< getHauteur()-1 << std::endl;
        int valY = demandeInt(2,getHauteur()-1);
        std::cout << "de quelle taille voulez vous votre mur ?" << std::endl;
        if (hOUv=="h")
            this->creaMurHorizontal(valY,valX);
        else
            this->creaMurVertical(valY,valX);
        std::cout << "ce mur vous convient-il ?" << std::endl << "(oui (o) ou non (n))"<<std::endl;
        oOUn=demandeAouB("o","n");
        if (oOUn=="n")
        {
            mapStrings=copieMapStrings;
            this->afficherMap();
        }
        this->creaMur(); // on recree d'autre mur si le joueur demande
    }
}

void creaMap::creaMurVertical(int valY,int valX)
{
    std::cout <<"valeur de "<<1<<" a "<<getHauteur()-valY<< std::endl;
    int valDist = demandeInt(1,getHauteur()-valY);
    for (int i=0;i<valDist;i++)
        this->modifierValeurMap('#',valX-1,valY-1+i);
    this->afficherMap();
}

void creaMap::creaMurHorizontal(int valY,int valX)
{
    std::cout <<"valeur de "<<1<<" a "<<getLongueur()-valX<< std::endl;
    int valDist = demandeInt(1,getLongueur()-valX);
    for (int i=0;i<valDist;i++)
        this->modifierValeurMap('#',valX-1+i,valY-1);
    this->afficherMap();
}


void creaMap::choixChoses(const std::string chose)
{
    this->afficherMap();
    std::cout << "voulez vous ajouter des "<<chose<<" dans la salle ? (attention vous ne pouvez pas cree de "<<chose<<" sur les murs)" << std::endl << "(oui (o) ou non (n))"<<std::endl;
    std::string oOUn;
    oOUn=demandeAouB("o","n");
    if (oOUn=="n" && chose!="Chargeurs")
        std::cout << "tres bien, passons a l'etape suivante" << std::endl;
    else if(oOUn=="n");
    else
    {
        std::string  choix;
        if (chose=="Streumons")
        {
            std::cout << "voulez vous creer de simple Streumons ou des Streumons plus puissant ?" << std::endl << "(Streumons (s) ,Streumons puissant (S), Streumons puissant et Intelligent (o)"<<std::endl;
             choix=demandeAouB("s","S","o");
        }
        else if (chose=="Diamants")
        {
            std::cout << "Si vous creez un Diamant sur un Streumon, le Streumon sera instantanement detruit ecrase par le Diamants" << std::endl;
             choix="D";
        }
        else if (chose=="Chargeurs")
        {
            std::cout << "les Chargeurs ne peuvent pas etre cree sur les Diamants ou sur les Streumons, vous ne pouvez avoir qu'un Chargeur par map" << std::endl;
            choix="C";
        }
        else
            std::cout << "cette chose n existe pas encore dans l univers du jeu" << std::endl;
        this->creaChoses(chose,choix);
    }
}

void creaMap::creaChoses(const std::string chose,std::string choix)
{
    std::vector<std::string> copieMapStrings=mapStrings;
    std::string oOUn;
    std::cout << "a quelle position en X voulez vous creer le "<<chose<<" ?" << std::endl <<"valeur de 2 a "<< getLongueur()-1 << std::endl;
    int valX = demandeInt(2,getLongueur()-1);
    std::cout << "a quelle position en Y voulez vous creer le "<<chose<<" ?" << std::endl <<"valeur de 2 a "<< getHauteur()-1 << std::endl;
    int valY = demandeInt(2,getHauteur()-1);
    if (getMapStrings(valY-1)[valX-1]=='#')
    {
        std::cout << "ne soyez pas tetu, je vous ai dit que l'on ne pouvais pas creer de "<<chose<<" sur les murs"<< std::endl;
        this->choixChoses(chose);
    }
    else if((getMapStrings(valY-1)[valX-1]=='s'||getMapStrings(valY-1)[valX-1]=='S'||getMapStrings(valY-1)[valX-1]=='o'||getMapStrings(valY-1)[valX-1]=='D' )&& choix!="D")
    {
        std::cout << "vous ne pouvez pas creer de "<<chose<<" sur les murs, sur les Streumons ou sur les Diamants"<< std::endl;
        this->choixChoses(chose);
    }
    else
    {
        this->modifierValeurMap(choix[0],valX-1,valY-1);
        this->afficherMap();
        std::cout << "cet emplacement pour le "<<chose<<" vous convient-il ?" << std::endl << "(oui (o) ou non (n))"<<std::endl;
        oOUn=demandeAouB("o","n");
        if (oOUn=="n")
            mapStrings=copieMapStrings;
        else if (oOUn=="o"&&choix=="C")
            m_chargeur = true;
        if(m_chargeur!= true)
            this->choixChoses(chose);
    }
}



void creaMap::modifierValeurMap(char a, int posX,int posY) // modifie le charactere en X Y par 'a'
{
    this->mapStrings[posY][posX]=a;
}

void creaMap::ajouterElement()
{
    this->creaMur();
    this->choixChoses("Streumons"); //on cree les monstres
    this->choixChoses("Diamants"); //on cree les Diamants
    this->choixChoses("Chargeurs"); //on cree les Chargeurs
    bool i = false ;
    do
    {
        std::cout<<"cette map vous convient-elle ?" <<std::endl<<"il est encore temps de la modifier(ajouter des murs, des Streumons ..."<< std::endl<<"(oui (o) ou non (n))"<<std::endl;
        char oOUn=demandeAouB("o","n");
        if (oOUn=='o')
        {
            i=true;
        }
        else
        {
            char aOUb;
            if (m_chargeur==false)
            {
                std::cout << "voulez vous ajouter des murs ?(m), des Streumons ? (s), des Diamants ?(d), ou des Chargeurs ?(c)";
                aOUb=demandeAouB("m","s","d","c");
            }
            else
            {
                std::cout << "voulez vous ajouter des murs ?(m), des Streumons ? (s), des Diamants ?(d)";
                aOUb=demandeAouB("m","s","d");
            }

            if(aOUb=='m')
                this->creaMur(); //permet de cree les mur supplementaire de la salle
            else if (aOUb=='s')
                this->choixChoses("Streumons"); //on cree les monstres
            else if (aOUb=='d')
                this->choixChoses("Diamants"); //on cree les Diamants
            else
                this->choixChoses("Chargeurs"); //on cree les Chargeurs
        }
    }while (i==false);
}

void creaMap::choixNomMap() const
{
    std::cout<<"felicitation votre map est terminee"<<std::endl;
    bool i=false;
    std::string liste="ListeMap/ListeMap.txt";
    std::string nomMap;
        do
        {
            i=false;
            std::cout<<"sous quel nom voulez vous enregistrer votre map ?"<<std::endl;
            std::cin >> nomMap;
            std::string ligne;
            std::ifstream fluxII(liste.c_str()); //on ouvre en lecture la liste des nom de map ||et on regarde si se nom existe deja
            if(fluxII)
            {
                while(getline(fluxII, ligne))
                {
                    if (nomMap==ligne) //si le nom est deja pris, on en redemande un autre
                    {
                        std::cout<< "se nom est deja utilise, vous ne pouvez pas ecraser une map deja existante, merci de choisir un autre nom."<< std::endl;
                        i=true;
                    }
                }
                fluxII.close();
            }
            else{std::cout << "ERREUR: Impossible d'ouvrir en lecture le fichier de liste des nom de Map." << std::endl;}
        }while(i!=false);
    this->enregistrerMap(nomMap);
}


void creaMap::enregistrerMap(std::string nomMap) const
{
    std::string liste="ListeMap/ListeMap.txt";
    std::ofstream fluxIII(liste.c_str(), std::ios::app); //on ouvre le fichier en mode ecriture pour ajouter le nom de la nouvelle map a la liste de map
    if(fluxIII.is_open())
    {
        fluxIII<<std::endl<<nomMap;
        fluxIII.close();
    }
    else {std::cout << "ERREUR: Impossible d'ouvrir en ecriture le fichier de liste des nom de Map." << std::endl;}

    std::ofstream flux(("Map/"+nomMap+".txt").c_str()); //on cree un nouveau txt pour enregistrer la map a l'interieur
    if(flux.is_open())
    {
        for(int i(0);i< this->getHauteur();i++)
        {
            flux<<this->getMapStrings(i)<<std::endl;
        }
        flux.close();
    }
    else{std::cout<<"erreur ouverture fichier";}

    std::cout<< "la map "<<nomMap<<" a bien ete cree."<<std::endl<<std::endl;
}
