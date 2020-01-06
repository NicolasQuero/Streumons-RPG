#include "Combat.h"

Combat::Combat(Entity &J, Entity &M) : J(J), M(M), keepFighting(true) {

}

bool Combat::playCombatTurn() {
    return true;
    //J->playCombatTurn()
}

bool Combat::startCombat() {
    cout << "Le combat entre " << J.getType() << " et " << M.getType() << " commence !" << endl;
    cout << J.getType() << " a " << J.getHp() << " HP." << endl;
    cout << M.getType() << " a " << M.getHp() << " HP." << endl;
    while (keepFighting) {
        keepFighting = J.playCombatTurn(M); // playCombatTurn returns false if E died hence we stop the fight
        if ( keepFighting )
            keepFighting = M.playCombatTurn(J);
    }
    return J.isAlive();
}
