#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INCLUDED

#include <iostream>
#include <vector>
#include <algorithm>

#include "GameMap.hpp"
#include "Entities/Entity.hpp"
#include "Entities/Oueurj.hpp"
#include "Entities/Streumons/Streumon.hpp"
#include "Entities/Streumons/Monster_s.hpp"
#include "Entities/Streumons/Monster_o.hpp"

using namespace std;

class Board {
private:
    GameMap *gamemap;
    int score;
    vector<vector<char>> charMap;
    const vector<char> monsterPossibleLetters = {'s', 'S', 'o'}; // vector of the possible letters associated to a monster
    vector<Entity*> monstersOnMap; // Un vector d'objets abstraits doit être un vector de pointeurs
    bool monstreCree;
    Oueurj *J;

public:
    static bool gameOn;
    static void setGameOn(bool a) {gameOn = a;};
    Board(GameMap *gamemap,Oueurj *j);
    void actualiseMap(GameMap *gamemap);
    void addMonster(char c, int i, int j);
    void setCharMaps(GameMap &gameMap);
    char getCharAt(int &x, int &y) const;
    void printMap() const ;
    void printInformation(int &row) const;
    int playTurn();
    ~Board();

};

#endif // BOARD_HPP_INCLUDED
