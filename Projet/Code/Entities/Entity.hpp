#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

#include <vector>
#include <string>
#include <iostream>

#include "Pos.hpp"
#include "../GameMap.hpp"


using namespace std;

class Entity
{

protected:

    char type;
    const static Pos DEPLACEMENTS_POS[];
    int hp, dmg;
    bool is_alive;

public:
    Pos pos;
    Entity(char type, int x, int y, int hp, int dmg);
    Entity(char type, Pos p, int hp, int dmg);
    int getHp() const { return hp; };
    virtual int getMp() const { return -1; }
    void inflictDamage(int amount) {
        hp -= amount;
        if (hp <= 0)
            is_alive = false;
    };
    bool attack(Entity *E);
    bool isAlive() const { return is_alive; };
    char getType() const { return type; };
    virtual void addScore(Entity* M){};
    virtual void act(Entity *J, GameMap &gameMap, vector<vector<char>> &charMap, vector<Entity*> &streumons) = 0;
    virtual bool playCombatTurn(Entity *E) = 0;

    virtual ~Entity() {};

};


#endif // ENTITY_HPP_INCLUDED
