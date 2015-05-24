#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED
#include <functional>

#include "widget.hpp"



class Gomb : public Widget{
private:
    std::function <void ()> fv;
    std::string nev;
    bool klikkelve;
public:
    Gomb(float _x, float _y, float _mx, float _my, std::function <void ()> f, std::string szam);
    void rajzol();
    void klikk(genv::event ev);
};



#endif // BUTTON_HPP_INCLUDED
