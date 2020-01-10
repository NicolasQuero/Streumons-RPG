#include "Streumon.h"


using namespace std;


Streumon::Streumon(char monsterLetter, int x, int y, int hp, int dmg) : Entity(monsterLetter, x, y, hp, dmg) {}

bool Streumon::moveBy(Pos movement, Entity *J, vector<vector<char>> &charMap, vector<Entity*> &streumons) {
    Pos targetPos = this->pos + movement;
    if ( charMap[targetPos.x][targetPos.y] == '#' || charMap[targetPos.x][targetPos.y] == 'X') { // WALL DETECTED
        return false;
    }
    else {
        for (Entity* streumon : streumons) {
            if (streumon->pos.y == targetPos.y && streumon->pos.x == targetPos.x) // OTHER MONSTER AT TARGET LOCATION
                return false;
        }
        if (J->pos.y == targetPos.y && J->pos.x == targetPos.x) { // START COMBAT WITH PLAYER
            Combat newCombat = Combat(this, J);
            cout << "COMBAT" << endl;
            newCombat.startCombat();
            return true;
        }
    }
    this->pos += movement; // NO COLLISION, MOVEMENT IS DONE
    return true;
}

bool Streumon::moveMonsterAtRandom(Entity *J, vector<vector<char>> &charMap, vector<Entity*> &streumons) {
    int rand9 = rand()%9;
    moveBy(DEPLACEMENTS_POS[rand9], J, charMap, streumons);
    return true;
}
