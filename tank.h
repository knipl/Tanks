#ifndef TANK_H_INCLUDED
#define TANK_H_INCLUDED

#include "widget.hpp"

using namespace genv;
using namespace std;

class Tank: public Widget{
protected:
    bool ele;
    bool Player;
public:
    Tank(float _x, float _y, float _mx, float _my, bool Pl);
    void rajzol();
    //Lovedek golyo;
};


#endif // TANK_H_INCLUDED
