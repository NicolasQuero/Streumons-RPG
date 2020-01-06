#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
#include <vector>
#include <algorithm>

#include "GameMap.h"
#include "Entities/Entity.h"
#include "Entities/Oueurj.h"
#include "Entities/Streumons/Streumon.h"
#include "Entities/Streumons/Monster_s.h"
#include "Entities/Streumons/Monster_o.h"

using namespace std;

class Board {
private:
    GameMap *gamemap;
    int score;
    vector<vector<char>> charMap;
    const vector<char> monsterPossibleLetters = {'s', 'S', 'e', 'E', 'o', 'O'}; // vector of the possible letters associated to a monster
    vector<Entity*> monstersOnMap; // Un vector d'objets abstraits doit être un vector de pointeurs
    bool monstreCree;
    Oueurj J;

public:
    static bool gameOn;
    static void setGameOn(bool a) {gameOn = a;};
    Board(GameMap *gamemap,Oueurj &j);
    void actualiseMap(GameMap *gamemap);
    void addMonster(char c, int i, int j);
    void setCharMaps(GameMap &gameMap);
    char getCharAt(int &x, int &y) const;
    void printMap() const ;
    void printCoordinatesAroundTheMap(vector<vector<char>> charMap, int row, int col) const;
    void printInformation(int &row) const;
    int playTurn();
    ~Board();

};


#endif // BOARD_H_INCLUDED
