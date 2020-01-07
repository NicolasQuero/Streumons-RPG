#ifndef STREUMON_H_INCLUDED
#define STREUMON_H_INCLUDED

#include <iostream>
#include <vector>

#include "../Pos.h"
#include "../Entity.h"
#include"../../Combat.h"

class Streumon : public Entity {
protected:
    Streumon(char monsterLetter, int x = -1, int y = -1, int hp = 1, int dmg = 1);

public:
    virtual void act(Entity *J, GameMap &gameMap, vector<vector<char>> &charMap, vector<Entity*> &streumons) = 0;
    ~Streumon() {};

    bool moveBy(Pos movement, Entity *J, vector<vector<char>> &charMap, vector<Entity*> &streumons);
    bool moveMonsterAtRandom(Entity *J, vector<vector<char>> &charMap, vector<Entity*> &streumons);
};



#endif // STREUMON_H_INCLUDED
