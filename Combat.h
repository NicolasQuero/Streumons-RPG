#ifndef COMBAT_H_INCLUDED
#define COMBAT_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <unistd.h>

#include "Entities/Entity.h"


class Combat {
private:
    Entity *J;
    Entity *M;
    bool keepFighting;

public:
    Combat(Entity *J, Entity *M);
    bool startCombat(); // returns true if the player is still alive, false otherwise
    void printCombatInterface() const;



};


#endif // COMBAT_H_INCLUDED
