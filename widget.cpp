#include "widget.hpp"

Widget::Widget(float _x, float _y, float _mx, float _my)
{
    x=_x;
    y=_y;
    mx=_mx;
    my=_my;
    fokuszalva = 0;
}

void Widget::rajzol() {}
void Widget::klikk(genv::event ev) {}

