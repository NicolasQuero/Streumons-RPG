#include "Monster_s.hpp"

using namespace std;

const int Monster_s::HP_MAX = 25;
const int Monster_s::BASE_DMG = 6;

Monster_s::Monster_s(int x, int y,int niveau,char s) : Streumon(s, x, y, niveau*HP_MAX, niveau*BASE_DMG) {}
void Monster_s::act(Entity *J, GameMap &gameMap, vector<vector<char>> &charMap, vector<Entity*> &streumons)
{
    if (this->isAlive())
        moveMonster(J, charMap, streumons);
}

bool Monster_s::playCombatTurn(Entity *E) {
    return attack(E);
}

void Monster_s::moveMonster(Entity *J, vector<vector<char>> &charMap, vector<Entity*> &streumons)
{
    bool moved = false;
    moved=moveMonsterAtRandom(J,charMap,streumons);
    if(!moved){moveMonster(J, charMap, streumons);}
}


