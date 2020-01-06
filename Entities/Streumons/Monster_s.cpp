#include "Monster_s.h"

using namespace std;

const int Monster_s::HP_MAX = 1;
const int Monster_s::BASE_DMG = 1;

Monster_s::Monster_s(int x, int y,int niveau,char s) : Streumon(s, x, y, niveau*HP_MAX, niveau*BASE_DMG) {}
void Monster_s::act(Entity &J, GameMap &gameMap, vector<vector<char>> &charMap, vector<Entity*> &streumons)
{
    moveMonster(J, charMap, streumons);
}

bool Monster_s::playCombatTurn(Entity &E) {
    return attack(E);
}

void Monster_s::moveMonster(Entity &J, vector<vector<char>> &charMap, vector<Entity*> &streumons)
{
    int val=0;
    int rand2 = rand()%9;
    bool moved = false;
    for(int i=-1;i<2;i++)
    {
        for(int j=-1;j<2;j++)
        {
            val++;
            if(rand2==val)
                moved=moveBy(Pos(i,j),J,charMap, streumons);
        }
    }
    if(!moved){moveMonster(J, charMap, streumons);}
}

