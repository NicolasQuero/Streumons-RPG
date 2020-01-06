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
    std::cout<<std::endl<<"La portée “protected” empêche l'accès aux méthodes et attributs qui suivent depuis l'extérieur de la classe, sauf…"<<std::endl<<std::endl;
    std::cout<<"1)... depuis les classes filles."<<std::endl;
    std::cout<<"2)... depuis la classe mère."<<std::endl;
    std::cout<<"3)... depuis les constructeur d’autres classes."<<std::endl;
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
    std::cout<<"2)Oui, si Bidule hérite de Truc."<<std::endl;
    std::cout<<"3)Oui, si Truc hérite de Bidule."<<std::endl;
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
    std::cout<<std::endl<<"Quelles méthodes ne peuvent pas être virtuelles ?"<<std::endl<<std::endl;
    std::cout<<"1)Les méthodes avec plus d'un argument"<<std::endl;
    std::cout<<"2)Les opérateurs"<<std::endl;
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
    std::cout<<std::endl<<"À quels constituants d'une classe, une fonction amie a-t-elle accès ?"<<std::endl<<std::endl;
    std::cout<<"1)À toutes les méthodes"<<std::endl;
    std::cout<<"2)À tous les attributs et méthodes"<<std::endl;
    std::cout<<"3)À tous les attributs"<<std::endl;
    std::cout<<"4)À toutes les méthodes publiques"<<std::endl;
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


