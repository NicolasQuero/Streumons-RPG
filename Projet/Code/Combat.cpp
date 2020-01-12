#include "Combat.hpp"

using namespace std;

Combat::Combat(Entity *J, Entity *M) : J(J), M(M), keepFighting(true) {
    loadCombatAnimations();
}

bool Combat::playCombatTurn() {
    return true;
    //J->playCombatTurn()
}

bool Combat::startCombat() {
    cout << "Le combat entre " << J->getType() << " et " << M->getType() << " commence !" << endl << endl;
    cout << J->getType() << " a " << J->getHp() << " HP." << endl;
    cout << M->getType() << " a " << M->getHp() << " HP." << endl;
    //usleep(300000);
    while (keepFighting) {
        keepFighting = J->playCombatTurn(M); // playCombatTurn returns false if E died hence we stop the fight
        printCombatInterface(0);
        J->setAttackInUse(' '); // Resets the attack because we just printed it in printCombatInterface
        if ( keepFighting ) {
            keepFighting = M->playCombatTurn(J);
            printCombatInterface(1);
            M->setAttackInUse(' '); // Resets the attack because we just printed it in printCombatInterface
        }
    }
    return J->isAlive();
}

void Combat::printCombatInterface(int attackerLocation) {
    loadCombatBackground();
    basicAttack.setBackground(combat_background);
    powerAttack.setBackground(combat_background);
    if (attackerLocation == 0) {
        if (J->getAttackInUse() == 'b')
            basicAttack.printAnimation(0);
        else if (J->getAttackInUse() == 'p')
            powerAttack.printAnimation(0);
    }
    else if (attackerLocation == 1) {
        if (J->getAttackInUse() == 'b')
            basicAttack.printAnimation(1);
        else if (J->getAttackInUse() == 'p')
            powerAttack.printAnimation(1);
    }
}

void Combat::loadCombatAnimations() {
    string basic_attack_path = "Code/Entities/Animations/Attacks/basic_attack";
    string power_attack_path = "Code/Entities/Animations/Attacks/power_attack";
    basicAttack = Animation(100000, basic_attack_path);
    powerAttack = Animation(100000, power_attack_path);
	Frame header = Frame();
    header.addLine("     ----------------- ");
    header.addLine(string("     | COMBAT ") + J->getType() + " vs " + M->getType() + " |");
    header.addLine("     ----------------- \n");

    loadCombatBackground();

    basicAttack.setBackground(combat_background);
    powerAttack.setBackground(combat_background);
    basicAttack.addHeader(header);
    powerAttack.addHeader(header);
}

void Combat::loadCombatBackground() {
    combat_background = Frame();
    string edge = "  -------------------------";
    string inside = "  -                       -";
    string types = string("  -      ") + J->getType() + "         " + M->getType() + "      -";
    string hpinfo = string("      HP : ") + to_string(J->getHp()) + "   HP : " + to_string(M->getHp()) + "    ";
    combat_background.addLine(edge);
    combat_background.addLine(inside);
    combat_background.addLine(inside);
    combat_background.addLine(types);
    combat_background.addLine(inside);
    combat_background.addLine(hpinfo);
    if (J->getType() == 'j') {
        string mpinfo = "      MP : " + to_string(J->getMp()) + "               ";
        combat_background.addLine(mpinfo);
    }
    else if (M->getType() == 'j') {
        string mpinfo = "                MP : " + to_string(M->getMp()) + "     ";
        combat_background.addLine(mpinfo);
    }
    combat_background.addLine(inside);
    combat_background.addLine(inside);
    combat_background.addLine(edge);
    combat_background.addLine("                           ");
}

Combat::~Combat() {

}
