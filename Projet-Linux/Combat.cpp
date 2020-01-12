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
        printCombatInterface();
        keepFighting = J->playCombatTurn(M); // playCombatTurn returns false if E died hence we stop the fight
        if ( keepFighting )
            keepFighting = M->playCombatTurn(J);
    }
    return J->isAlive();
}

void Combat::printCombatInterface() {
	std::system("clear");
	Frame combat_background = Frame();
    cout << "     ----------------- " << endl;
    cout << "     | COMBAT " << J->getType() << " vs " << M->getType() << " |" << endl;
    cout << "     ----------------- " << endl << endl;
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
        string mpinfo = string("      MP : ") + to_string(J->getMp()) + "               ";
        combat_background.addLine(mpinfo);
    }
    else if (M->getType() == 'j') {
        string mpinfo = "                MP : " + to_string(M->getMp()) + "     ";
        combat_background.addLine(mpinfo);
    }
    combat_background.addLine(inside);
    combat_background.addLine(inside);
    combat_background.addLine(edge);
    basicAttack.setBackground(combat_background);

    basicAttack.printAnimation();
}

void Combat::loadCombatAnimations() {
    string basic_attack_path = "Entities/Animations/Attacks/basic_attack";
    basicAttack = Animation(100000, basic_attack_path);
}
