#ifndef COMBAT_HPP_INCLUDED
#define COMBAT_HPP_INCLUDED

#include "Entities/Entity.hpp"

class Combat {
private:
    Entity *J;
    Entity *M;
    bool keepFighting;
    bool playCombatTurn(); // returns true if the player is still alive

public:
    Combat(Entity *J, Entity *M);
    bool startCombat(); // returns true if the player is still alive, false otherwise
    void printCombatInterface() const;



};



#endif // COMBAT_HPP_INCLUDED
