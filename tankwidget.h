#ifndef TANKWIDGET_H_INCLUDED
#define TANKWIDGET_H_INCLUDED

#include "widget.hpp"
#include "tank.h"

class TankWidget : public Widget
{
protected:
    Tank *tank;
public:
    TankWidget(float _x, float _y, float _mx, float _my, Tank *_tank);
    virtual void rajzol();
};

#endif // TANKWIDGET_H_INCLUDED
