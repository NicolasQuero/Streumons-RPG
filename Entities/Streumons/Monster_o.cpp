#include "Monster_o.h"

using namespace std;

const int Monster_o::HP_MAX = 40;
const int Monster_o::BASE_DMG = 10;
const double Monster_o::DETECTION_RADIUS = 12;

Monster_o::Monster_o(int x, int y) : Streumon('o', x, y, HP_MAX, BASE_DMG) {}

void Monster_o::act(Entity *J, GameMap &gameMap, vector<vector<char>> &charMap, vector<Entity*> &streumons) {
    moveMonster(J, charMap, streumons);
}

void Monster_o::moveMonster(Entity *J, vector<vector<char>> &charMap, vector<Entity*> &streumons) {
    bool moved = false;
    if ( J->pos.dist(this->pos) < DETECTION_RADIUS ) { // Si le joueur est à une distance inférieure au rayon de détection
        int rand2 = rand()%2; // On choisit un nombre rand2 au hasard entre 1 et 2
        if (rand2 == 0) { // Pour rand2 == 0 on tente de se rapprocher du joueur sur l'axe des abscisses
            moved = moveMonsterInX(J, charMap, streumons);
            if (!moved) // moved vaut false si le déplacement a échoué, on essaye alors de se rapprocher sur l'axe des ordonnées
                moveMonsterInY(J, charMap, streumons);
        }
        else if (rand2 == 1) { // Pour rand2 == 1, on fait la même chose en commençant par l'axe Y au lieu de l'axe X
            moved = moveMonsterInY(J, charMap, streumons);
            if (!moved)
                moveMonsterInX(J, charMap, streumons);
        }
        else if (rand2 == 2) {
            moveMonsterAtRandom(J, charMap, streumons);
        }
    }
}

bool Monster_o::moveMonsterInX(Entity *J, vector<vector<char>> &charMap, vector<Entity*> &streumons) {
    bool moved = false;
    if (J->pos.x < this->pos.x) {
        moved = moveBy(Pos(-1,0), J, charMap, streumons);
    }
    else if (J->pos.x > this->pos.x) {
        moved = moveBy(Pos(1,0), J, charMap, streumons);
    }
    return moved;
}

bool Monster_o::moveMonsterInY(Entity *J, vector<vector<char>> &charMap, vector<Entity*> &streumons) {
    bool moved = false;
    if (J->pos.y < this->pos.y) {
        moved = moveBy(Pos(0,-1), J, charMap, streumons);
    }
    else if (J->pos.y > this->pos.y) {
        moved = moveBy(Pos(0,1), J, charMap, streumons);
    }
    return moved;
}

bool Monster_o::playCombatTurn(Entity *E) {
    return attack(E);
}

