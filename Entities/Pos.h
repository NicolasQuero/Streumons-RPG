#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Pos {
public:
    int x, y;
    Pos(int x = -1, int y = -1);
    int getX() const;
    int getY() const;
    void setX(int &x);
    void setY(int &y);
    void setPos(int &x, int &y);
    double dist(Pos &P) const;
    friend ostream &operator<<(ostream &out, const Pos &pos) {
        out << "(" << pos.x << ", " << pos.y << ")";
        return out;
    }
    void operator=(Pos const& pos2) {
        x = pos2.x;
        y = pos2.y;
    }
    void operator+=(Pos const& pos2) {
        x += pos2.x;
        y += pos2.y;
    }


};

inline Pos operator+(const Pos& pos1, const Pos& pos2) {
    Pos result = Pos(pos1.x + pos2.x, pos1.y + pos2.y);
    return result;
}
inline bool operator==(const Pos& pos1, const Pos& pos2) {
    if (pos1.x == pos2.x && pos1.y == pos2.y)
        return true;
    return false;
}




#endif // POSITION_H_INCLUDED
