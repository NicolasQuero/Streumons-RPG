#ifndef COMBAT_HPP_INCLUDED
#define COMBAT_HPP_INCLUDED

#include "Entities/Entity.hpp"
#include "Entities/Animations/Animation.hpp"
#include <string>

class Combat {
private:
    Entity *J;
    Entity *M;
    bool keepFighting;
    bool playCombatTurn(); // returns true if the player is still alive
    Animation basicAttack;//, powerAttack, heal;
    void loadCombatAnimations();

public:
    Combat(Entity *J, Entity *M);
    bool startCombat(); // returns true if the player is still alive, false otherwise
    void printCombatInterface();



};



#endif // COMBAT_HPP_INCLUDED
