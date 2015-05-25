#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"

class Widget
{
protected:
    float x, y, mx, my;
    bool fokuszalva;
public:
    Widget(float _x, float _y, float _mx, float _my);
    virtual void rajzol();
    virtual void klikk(genv::event ev);
};


#endif
