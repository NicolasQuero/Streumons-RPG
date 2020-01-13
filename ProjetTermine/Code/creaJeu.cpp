#include "creaJeu.hpp"

creaJeu::creaJeu()
{
    std::vector<std::string> p1;
    p1.push_back("       ");
    p1.push_back("       ");
    p1.push_back("       ");
    std::vector<std::string> p;
    p.push_back("       ");
    p.push_back("Depart");
    p.push_back("       ");
    m_listeMiniMap.push_back(p);
    m_listeMiniMap.insert(m_listeMiniMap.begin(),1,p1);
    m_listeMiniMap.push_back(p1);
}

creaJeu::~creaJeu()
{
}

int creaJeu::getTailleX()
{
   return m_listeMiniMap[0].size();
}

int creaJeu::getTailleY()
{
    return m_listeMiniMap.size();
}

std::vector<std::string> creaJeu::afficherListeMap()
{
    std::vector<std::string> listemap;
    std::cout<<"choisissez une map existante pour l'ajouter au Jeu"<<std::endl;
    std::string MAP_PATH="Code/ListeMap/ListeMap.txt";
    std::ifstream flux(MAP_PATH.c_str()); //on ouvre en lecture la liste des nom de map et on affiche le nom des map existante.
    if(flux)
    {
        std::string nomMap;
        std::cout<<"map disponible :"<<std::endl<<std::endl;
        while(getline(flux,nomMap))// on parcours toutes les map existante mais on affiche pas les maps "interdite"
        {
            int i=nomMap.size();
            if(nomMap.substr(0,i-1)!="fin" && nomMap.substr(0,i-1)!="Depart" && nomMap.substr(0,i-1)!="---------------")// map "interdite"   ("---------------" = separateur pour la creation du jeu
            {

                std::cout<<nomMap<<std::endl;
                listemap.push_back(nomMap.substr(0,i));
            }
        }
        flux.close();
        std::cout<<std::endl;
    }
    else{std::cout << "ERREUR: Impossible d'ouvrir en lecture le fichier de liste des nom de Map." << std::endl;}
    return listemap;
}


std::string creaJeu::choixMapAjoute()
{
    bool i=false;
    std::vector<std::string> listeMap=afficherListeMap();
    char aOUs;
    std::string nomMap;
        do
        {
            i=false;
            std::cout<<"Voulez vous afficher une Map ou selectionner definitivement la Map a ajouter ?"<<std::endl;
            std::cout<<"afficher(a) ,selectionner(s)"<<std::endl;
            aOUs = demandeAouB("a","s");
            std::cout<<"quelle map choisissez vous ?"<<std::endl;
            std::cin >> nomMap;
            int tailleListeMap = listeMap.size();
            for(int j=0;j<tailleListeMap;j++)
            {
                int k =listeMap[j].size();
                if(nomMap == listeMap[j].substr(0,k) && aOUs=='a')
                {
                        creaMap c(listeMap[j].substr(0,k)); // on recree la map demandee
                        c.afficherMap(); // on l'affiche
                        afficherListeMap();
                        i=true;
                }
                else if(nomMap == listeMap[j].substr(0,k) && aOUs=='s' )
                {
                    i=true;
                }
            }
            if(i==false)
                std::cout<<"cette map n'existe pas"<<std::endl;
        }while(i==false || aOUs=='a');
    return nomMap;
}


void creaJeu::choixMapAdjacente(std::string MapImposee)
{
    int posX,posY;
    do
    {
        afficherMiniMap();
        std::cout<<"selectionner une map existante a cote de la quelle vous voulez ajouter une nouvelle map"<<std::endl;
        std::cout<<"selectionner la position de la Map en X"<<std::endl;
        posX = demandeInt(1,getTailleX()-2);
        std::cout<<"selectionner la position de la Map en Y"<<std::endl;
        posY = demandeInt(1,getTailleY()-2);
        if (m_listeMiniMap[posY][posX]=="       ")
            std::cout<<"il n'y a pas de map ici, merci de choisir une autre position"<<std::endl;
        else if ( m_listeMiniMap[posY-1][posX]!="       " && m_listeMiniMap[posY+1][posX]!="       " && m_listeMiniMap[posY][posX-1]!="       " && m_listeMiniMap[posY][posX+1]!="       " )
        {
            std::cout<<"il n'y a plus de place disponible autour de cette map"<<std::endl;
            this->creaMiniMap();
        }
    }while(m_listeMiniMap[posY][posX]=="       " ||( m_listeMiniMap[posY-1][posX]!="       " && m_listeMiniMap[posY+1][posX]!="       " && m_listeMiniMap[posY][posX-1]!="       " && m_listeMiniMap[posY][posX+1]!="       " ));
    choixDirection( posX, posY,MapImposee);
}

void creaJeu::creaMiniMap()
{
    char oOUn;
    do
    {
        this->choixMapAdjacente();
        this->afficherMiniMap();
        std::cout<<"voulez vous ajouter une nouvelle map avant de placer la derniere map de fin ?" <<std::endl<<"(oui (o)  non(n))"<<std::endl;
        oOUn = demandeAouB("o","n");
    }while(oOUn=='o');
    std::cout<<"tres bien il ne vous reste que la map de fin a ajouter pour pouvoir terminer ce nouveau Jeu" <<std::endl;
    this->choixMapAdjacente("fin");
    this->afficherMiniMap();
    std::cout<<"votre Jeu est desormait enregistre, vous pouvez des a present jouer a votre propre Jeu" <<std::endl;
    std::cout<<"Attention si vous creez un nouveau jeu, celui qui viens d'etre cree sera supprime" <<std::endl<<std::endl;
}


void creaJeu::ajoutMap(std::string Map,int posX,int posY, char direction)
{
    int tailleX =getTailleX();
    int tailleY =getTailleY();
    std::vector<std::string> p1;
    if (direction=='b')
    {
        this->ajoutEnBas(Map, posX, posY, tailleX, tailleY, p1);
    }
    else if (direction=='h')
    {
        this->ajoutEnHaut(Map, posX, posY, tailleX, tailleY, p1);
    }
    else if (direction=='g')
    {
        this->ajoutAGacuhe(Map, posX, posY, tailleX, tailleY, p1);
    }
    else if (direction=='d')
    {
        this->ajoutADroite(Map, posX, posY, tailleX, tailleY);
    }
}

void creaJeu::ajoutADroite(std::string Map,int posX,int posY,int tailleX,int tailleY)
{
    std::vector<std::vector<std::string> > copieListeMiniMap=m_listeMiniMap;
    if(posX==tailleX-2 )
    {
        for(int y=0;y<tailleY;y++)
        {
            m_listeMiniMap[y].push_back("       ");
        }
        m_listeMiniMap[posY][posX+1]=Map;
    }
    else
    {
        m_listeMiniMap[posY][posX+1]=Map;
    }
    this->validationChoix(Map,copieListeMiniMap);
}

void creaJeu::ajoutAGacuhe(std::string Map,int posX,int posY,int tailleX,int tailleY,std::vector<std::string> p1)
{
    std::vector<std::vector<std::string> > copieListeMiniMap=m_listeMiniMap;
    if(posX==1)
    {
        for(int y=0;y<tailleY;y++)
        {
            std::vector<std::string> p1;
            p1.push_back("       ");
            for(int x=0;x<tailleX;x++)
            {
                p1.push_back(m_listeMiniMap[y][x]);
            }
            m_listeMiniMap[y]=p1;
        }
        m_listeMiniMap[posY][posX]=Map;
    }
    else
    {
        m_listeMiniMap[posY][posX-1]=Map;
    }
    this->validationChoix(Map,copieListeMiniMap);
}

void creaJeu::ajoutEnHaut(std::string Map,int posX,int posY, int tailleX,int tailleY,std::vector<std::string> p1)
{
    std::vector<std::vector<std::string> > copieListeMiniMap=m_listeMiniMap;
    if(posY==1)
    {
        for(int i=0;i<tailleX;i++)
        {
            p1.push_back("       ");
        }
        m_listeMiniMap[posY-1][posX]=Map;
        m_listeMiniMap.insert(m_listeMiniMap.begin(),1,p1);
    }
    else
    {
        m_listeMiniMap[posY-1][posX]=Map;
    }
    this->validationChoix(Map,copieListeMiniMap);
}

void creaJeu::ajoutEnBas(std::string Map,int posX,int posY, int tailleX,int tailleY,std::vector<std::string> p1)
{
    std::vector<std::vector<std::string> > copieListeMiniMap=m_listeMiniMap;
    if(posY==tailleY-2)
    {
        for(int x=0;x<tailleX;x++)
        {
            p1.push_back("       ");
        }
        m_listeMiniMap[posY+1][posX]=Map;
        m_listeMiniMap.insert(m_listeMiniMap.end(),1,p1);
    }
    else
    {
        m_listeMiniMap[posY+1][posX]=Map;
    }
    this->validationChoix(Map,copieListeMiniMap);
}


void creaJeu::choixDirection(int posX,int posY,std::string MapImposee)
{
    std::cout << "ou voulez vous placer une nouvelle map par rapport a la map selectionnee?"<<std::endl<<"vous pouver aller :";
    std::string choix[]={"d","g","b","h"};
    bool j = true;
    if(m_listeMiniMap[posY-1][posX]!="       ")
        choix[3]=""; //on regarde si la place en haut est occupee
    else(std::cout << " en haut (h) ",j=false); //si elle n'est pas occupee, on propose l'emplacement,  le bool j est present juste pour la presentation du texte(aujout de  "," ou pas)

    if(m_listeMiniMap[posY+1][posX]!="       ")
        choix[2]=""; //on regarde si la place en bas est occupee
    else if(j==true)
        std::cout << "en bas (b) ",j=false;//si elle n'est pas occupee, on propose l'emplacement
    else(std::cout << ",en bas (b) ");

    if(m_listeMiniMap[posY][posX-1]!="       ")
            choix[1]=""; //on regarde si la place a gauche est occupee
    else if(j==true)
        std::cout << "a gauche (g) ",j=false;//si elle n'est pas occupee, on propose l'emplacement
    else(std::cout << ",a gauche (g) ");

    if(m_listeMiniMap[posY][posX+1]!="       ")
        choix[0]=""; //on regarde si la place a droite est occupee
    else if(j==true)
        std::cout << "a droite(d) ",j=false;//si elle n'est pas occupee, on propose l'emplacement
    else(std::cout << ",a droite (d) ");

    std::cout<<std::endl;
    char direction=demandeAouB(choix[3],choix[2],choix[1],choix[0]);
    if (MapImposee=="")
    {
        MapImposee=choixMapAjoute();
    }
    this->ajoutMap(MapImposee, posX, posY, direction);
}

void creaJeu::validationChoix(std::string Map,std::vector<std::vector<std::string> > copieListeMiniMap)
{
    this->afficherMiniMap();
    std::cout<<"cette configuration de Jeu vous convient-elle ?"<<std::endl<<"oui (o) ou non non (n)"<<std::endl;
    char oOUn=demandeAouB("o","n");
    if (oOUn=='n' && Map=="fin")
    {
        m_listeMiniMap=copieListeMiniMap; //reprned la minimap d'avant
        this->choixMapAdjacente("fin");
    }
    else if (oOUn=='n')
    {
        m_listeMiniMap=copieListeMiniMap; //reprned la minimap d'avant
    }
}

void creaJeu::enregistrerJeu()
{
    std::string directioncreaJeu ="Code/JeuCree/Jeu.txt"; // on ouvre le repertoire ou on va enregistrer le creaJeu
    std::ofstream flux(directioncreaJeu.c_str());
    if(flux.is_open())
    {
        for (int y=1; y<getTailleY()-1; y++)
        {
            for (int x=1; x<getTailleX()-1; x++)
            {
                flux<<m_listeMiniMap[y][x]<<std::endl;
            }
            flux<<"---------------"<<std::endl; //separation entre les lignes
        }
        flux.close();
    }
    else{std::cout<<"impossible d'ouvrir le fichier texte en ecriture pour creer le Jeu"<<std::endl;}
}

void creaJeu::afficherMiniMap()
{
    std::cout<<std::endl<<"***Mini Map***"<<std::endl<<std::endl;
    for(int x=1; x<getTailleX()-1;x++)
    {
        std::cout<<"    "<<x<<"    ";
    }
    std::cout<<std::endl<<std::endl;
    for(int y=1; y<getTailleY()-1;y++)
    {
        for(int x=1;x<getTailleX()-1;x++)
        {
            std::cout<<"."<<(m_listeMiniMap[y][x]+"     ").substr(0,7)<<".";
        }
        std::cout<<"   "<<y<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
}
