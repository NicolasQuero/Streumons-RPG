#ifndef OUEURJ_HPP_INCLUDED
#define OUEURJ_HPP_INCLUDED

#include <iostream>
#include <vector>

#include "Entity.hpp"
#include "Pos.hpp"
#include "../GameMap.hpp"
#include "../Combat.hpp"
#include "../TextOutput.hpp"

using namespace std;

class Entity;

class Oueurj : public Entity {
private:
    const static int HP_MAX, BASE_DMG, MP_MAX, POWER_MAX, HEAL_COST, POWERATK_COST;
    int mp, power, score;
    int teleportsLeft;
    bool wantsTeleport;
    bool didMonsterDie(Entity *M);
public:
    Oueurj();
    Oueurj(Pos p);
    Oueurj(int x, int y);
    int getTeleportsLeft() const { return teleportsLeft; }
    void useTeleport() { teleportsLeft -= 1; }
    bool wantsToTeleport() const { return wantsTeleport; }
    void addTeleport() { teleportsLeft += 1; }
    virtual int getMp() const override { return mp; }
    //bool quitGame() const;
    int monsterIndexAt(Pos target, vector<Entity*> &streumons);
    bool manageChoice(string choice, vector<vector<char>> &charMap, vector<Entity*> &streumons);
    void movePlayer(int deplacement, vector<vector<char>> &charMap, vector<Entity*> &streumons);
    int getScore() { return score; }
    void addScore(Entity* M);
    virtual void act(Entity *J, GameMap &gameMap, vector<vector<char>> &charMap, vector<Entity*> &streumons);
    bool playCombatTurn(Entity *E);
    bool powerAttack(Entity *E);
    bool heal();
    ~Oueurj() {};

};


#endif // OUEURJ_HPP_INCLUDED
