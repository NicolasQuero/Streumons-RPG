#ifndef COMBAT_H_INCLUDED
#define COMBAT_H_INCLUDED

#include <iostream>

#include "Entities/Entity.h"


class Combat {
private:
    Entity &J;
    Entity &M;
    bool keepFighting;
    bool playCombatTurn(); // returns true if the player is still alive

public:
    Combat(Entity &J, Entity &M);
    bool startCombat(); // returns true if the player is still alive, false otherwise



};


#endif // COMBAT_H_INCLUDED
