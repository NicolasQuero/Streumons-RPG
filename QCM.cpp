#include "QCM.h"


int QCMQuestion1()
{
    int reponse;
    std::cout<<std::endl<<"Comment s'appelle l'inventeur du C++ ?"<<std::endl<<std::endl;
    std::cout<<"1)Birj Tromman"<<std::endl;
    std::cout<<"2)Jean Baptiste Yunes"<<std::endl;
    std::cout<<"3)Bjarne Stroustrup"<<std::endl;
    std::cout<<"4)Barj Grossoup"<<std::endl;
    reponse=demandeInt(1,4);
    if(reponse==3)
    {
        std::cout<<"felicitation, c'est une bonne reponse"<<std::endl;
        return 1;
    }
    else
    {
        std::cout<<"et non, c'est une mauvaise reponse"<<std::endl;
        return 0;
    }
}

int QCMQuestion2()
{
    int reponse;
    std::cout<<std::endl<<"La port�e �protected� emp�che l'acc�s aux m�thodes et attributs qui suivent depuis l'ext�rieur de la classe, sauf�"<<std::endl<<std::endl;
    std::cout<<"1)... depuis les classes filles."<<std::endl;
    std::cout<<"2)... depuis la classe m�re."<<std::endl;
    std::cout<<"3)... depuis les constructeur d�autres classes."<<std::endl;
    std::cout<<"4)la reponse D"<<std::endl;
    reponse=demandeInt(1,4);
    if(reponse==1)
    {
        std::cout<<"felicitation, c'est une bonne reponse"<<std::endl;
        return 1;
    }
    else
    {
        std::cout<<"et non, c'est une mauvaise reponse"<<std::endl;
        return 0;
    }
}

int QCMQuestion3()
{
    int reponse;
    std::cout<<std::endl<<"Ce code compilera-t-il ?"<<std::endl<<std::endl;

    std::cout<<"Truc *monTruc(0);"<<std::endl;
    std::cout<<"Bidule *monBidule = new Bidule();"<<std::endl;
    std::cout<<"monTruc = monBidule;"<<std::endl<<std::endl;

    std::cout<<"1)Oui, quel que soient Bidule et Truc"<<std::endl;
    std::cout<<"2)Oui, si Bidule h�rite de Truc."<<std::endl;
    std::cout<<"3)Oui, si Truc h�rite de Bidule."<<std::endl;
    std::cout<<"4)Non, jamais."<<std::endl;
    reponse=demandeInt(1,4);
    if(reponse==2)
    {
        std::cout<<"felicitation, c'est une bonne reponse"<<std::endl;
        return 1;
    }
    else
    {
        std::cout<<"et non, c'est une mauvaise reponse"<<std::endl;
        return 0;
    }
}

int QCMQuestion4()
{
    int reponse;
    std::cout<<std::endl<<"Quelles m�thodes ne peuvent pas �tre virtuelles ?"<<std::endl<<std::endl;
    std::cout<<"1)Les m�thodes avec plus d'un argument"<<std::endl;
    std::cout<<"2)Les op�rateurs"<<std::endl;
    std::cout<<"3)Le destructeur"<<std::endl;
    std::cout<<"4)Les constructeurs"<<std::endl;
    reponse=demandeInt(1,4);
    if(reponse==4)
    {
        std::cout<<"felicitation, c'est une bonne reponse"<<std::endl;
        return 1;
    }
    else
    {
        std::cout<<"et non, c'est une mauvaise reponse"<<std::endl;
        return 0;
    }
}

int QCMQuestion5()
{
    int reponse;
    std::cout<<std::endl<<"� quels constituants d'une classe, une fonction amie a-t-elle acc�s ?"<<std::endl<<std::endl;
    std::cout<<"1)� toutes les m�thodes"<<std::endl;
    std::cout<<"2)� tous les attributs et m�thodes"<<std::endl;
    std::cout<<"3)� tous les attributs"<<std::endl;
    std::cout<<"4)� toutes les m�thodes publiques"<<std::endl;
    reponse=demandeInt(1,4);
    if(reponse==2)
    {
        std::cout<<"felicitation, c'est une bonne reponse"<<std::endl;
        return 1;
    }
    else
    {
        std::cout<<"et non, c'est une mauvaise reponse"<<std::endl;
        return 0;
    }
}


