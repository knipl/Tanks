#include "button.hpp"

using namespace genv;
using namespace std;

Gomb::Gomb(float _x, float _y, float _mx, float _my, function<void()> f, string szam):Widget(_x,_y,_mx,_my)
{
    fv=f;
    nev=szam;
}

void Gomb::klikk(event ev)
{
    bool helper = 1;
    if(ev.button == 1 && ev.pos_x > x && ev.pos_x < x+mx && ev.pos_y > y && ev.pos_y < y+my && klikkelve == 0 && helper)
    {
        klikkelve = 1;
        helper = 0;
        fv();
    }
    if(ev.button == -1 && klikkelve && helper)
    {
        klikkelve = 0;
        helper = 0;
    }
}

void Gomb::rajzol()
{
    gout <<move_to(x+0.2,y+0.2)<<color(50,50,50)<<box(mx-0.4, my-0.4);

    if(klikkelve)
    {
        gout <<move_to(x,y)<<color(200,200,200)<<box(mx,my)
             <<move_to(x+(mx/2)-(gout.twidth(nev)/2),y+(my/2)+((gout.cascent()-gout.cdescent())/2))<<color(0,0,0)<<text(nev);
    }
    else
    {
        gout<<move_to(x+(mx/2)-(gout.twidth(nev)/2),y+(my/2)+((gout.cascent()-gout.cdescent())/2))<<color(255,255,255)<<text(nev);
    }
}


