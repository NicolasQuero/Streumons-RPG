#include "Pos.h"

using namespace std;

Pos::Pos(int x, int y) : x(x), y(y) {}

int Pos::getX() const { return x; }
int Pos::getY() const { return y; }
void Pos::setX(int &newX) { x = newX; }
void Pos::setY(int &newY) { y = newY; }
void Pos::setPos(int &newX, int &newY) { x = newX; y = newY;}

double Pos::dist(Pos &P) const { // distance a un point P
    return sqrt( pow((P.getX() - x), 2) +  pow(P.getY() - y, 2) );
}
