#ifndef MONSTER_O_H_INCLUDED
#define MONSTER_O_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#include "Streumon.h"
#include "../Oueurj.h"
#include "../Entity.h"
#include "../Pos.h"
#include "../../Combat.h"

class Monster_o: public Streumon {
private:
    const static int HP_MAX, BASE_DMG;
    const static double DETECTION_RADIUS;
    bool moveMonsterInX(Entity *J, vector<vector<char>> &charMap, vector<Entity*> &streumons);
    bool moveMonsterInY(Entity *J, vector<vector<char>> &charMap, vector<Entity*> &streumons);

public:
    Monster_o(int x = -1, int y = -1);
    virtual void act(Entity *J, GameMap &gameMap, vector<vector<char>> &charMap, vector<Entity*> &streumons); // Il faut définir la fonction abstraite implémentée
    void moveMonster(Entity *J, vector<vector<char>> &charMap, vector<Entity*> &streumons);
    bool playCombatTurn(Entity *E);

};


#endif // MONSTER_O_H_INCLUDED
