#include "Entity.hpp"

const Pos Entity::DEPLACEMENTS_POS[] = {Pos(1, -1), Pos(1, 0), Pos(1, 1), Pos(0, -1), Pos(0,0), Pos(0,1), Pos(-1, -1), Pos(-1, 0), Pos(-1, 1)};

Entity::Entity(char type, int x, int y, int hp, int dmg) : type(type), hp(hp), dmg(dmg), is_alive(true), attackInUse(' '), pos(x, y) {}

Entity::Entity(char type, Pos p, int hp, int dmg) : type(type), hp(hp), dmg(dmg), is_alive(true), attackInUse(' '), pos(p) {}

bool Entity::attack(Entity *E) {
    E->inflictDamage(dmg);
    cout << ' ' << this->type << " inflige " << this->dmg << " point(s) de dégâts à " << E->type << endl;
    cout << ' ' << E->type << " n'a plus que " << E->hp << " points de vie !" << endl;
    attackInUse = 'n';
    return E->isAlive();
}

