#ifndef STREUMON_HPP_INCLUDED
#define STREUMON_HPP_INCLUDED

#include <iostream>
#include <vector>

#include "../Pos.hpp"
#include "../Entity.hpp"
#include"../../Combat.hpp"


class Streumon : public Entity {
protected:
    Streumon(char monsterLetter, int x = -1, int y = -1, int hp = 1, int dmg = 1);

public:
    virtual void act(Entity *J, GameMap &gameMap, vector<vector<char>> &charMap, vector<Entity*> &streumons) = 0;
    ~Streumon() {};

    bool moveBy(Pos movement, Entity *J, vector<vector<char>> &charMap, vector<Entity*> &streumons);
    bool moveMonsterAtRandom(Entity *J, vector<vector<char>> &charMap, vector<Entity*> &streumons);
};



#endif // STREUMON_HPP_INCLUDED
