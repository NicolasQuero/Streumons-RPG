#include"FonctionUtile.hpp"



char demandeAouB(std::string a,std::string b,std::string c,std::string d) // verifie si l'utilisateur a bien choisie oui ou non
{
    std::string AouB;
    std::cin.clear();
    std::cin >> AouB;
    std::string valeurs[]={a,b,c,d};
    while(AouB!=valeurs[0] && AouB!=valeurs[1] && AouB!=valeurs[2] && AouB!=valeurs[3])
    {
        std::cout <<"la valeur est incorrect, merci de choisir  entre";
        bool j=true;// le premier choix n'a pas avoir de "et" devant
        for(int i=0;i<4;i++)
        {
            if(valeurs[i]!=""&&j==true)
            {
                std::cout<<" ("<<valeurs[i]<<")";
                j=false; //une fois le premier choix passer on va pouvoir mettre des "et"
            }
            else if(valeurs[i]!="")
            {
                std::cout<<" et ("<<valeurs[i]<<")";
            }
        }
        std::cout <<std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin>> AouB;
    }
    return (AouB[0]);
}

int demandeInt(int b, int c) //verifie la selection entre deux valeur b et c
{
    int val;
    std::cin.clear();
    std::cin >> val;
    while (val < b  || val > c || std::cin.fail() )
    {
        std::cout <<"la valeur est incorrect, merci de choisir une valeur entre " <<b<<" et "<<c<< std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin>> val;
    }
    return val;
}
