#ifndef COMBAT_HPP_INCLUDED
#define COMBAT_HPP_INCLUDED

#include "Entities/Entity.hpp"
#include "Entities/Animations/Animation.hpp"
#include "Entities/Animations/Frame.hpp"
#include <string>

class Combat {
private:
    Entity *J;
    Entity *M;
    bool keepFighting;
    bool playCombatTurn(); // returns true if the player is still alive
    Animation basicAttack, powerAttack;// heal;
    Frame combat_background;
    void loadCombatAnimations();
    void loadCombatBackground();

public:
    Combat(Entity *J, Entity *M);
    bool startCombat(); // returns true if the player is still alive, false otherwise
    void printCombatInterface(int attackerLocation);
    ~Combat();



};



#endif // COMBAT_HPP_INCLUDED
