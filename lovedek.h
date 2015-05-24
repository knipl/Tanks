#ifndef LOVEDEK_H_INCLUDED
#define LOVEDEK_H_INCLUDED

#include "widget.hpp"

class Lovedek:public Widget{
protected:
float x,y;
public:
    Lovedek(float _x, float _y, float _mx, float _my);
    void rajzol();

};

#endif // LOVEDEK_H_INCLUDED
