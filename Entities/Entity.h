#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>

#include "Pos.h"
#include "../GameMap.h"

using namespace std;

class Entity
{

protected:
    const static Pos DEPLACEMENTS_POS[];
    int hp, dmg;
    char type;
    bool is_alive;

public:
    Pos pos;
    Entity(char type, int x, int y, int hp, int dmg);
    Entity(char type, Pos p, int hp, int dmg);
    int getHp() const { return hp; };
    void inflictDamage(int amount) {
        hp -= amount;
        if (hp <= 0)
            is_alive = false;
    };
    bool attack(Entity& E);
    bool isAlive() const { return is_alive; };
    char getType() const { return type; };
    virtual void act(Entity &J, GameMap &gameMap, vector<vector<char>> &charMap, vector<Entity*> &streumons) = 0;
    virtual bool playCombatTurn(Entity &E) = 0;

    virtual ~Entity() {};

};


#endif // PERSONNAGE_H_INCLUDED

