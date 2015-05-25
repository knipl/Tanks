#include "widget.hpp"
#include "slide.hpp"

#include <sstream>
#include <fstream>
#include <vector>
using namespace std;
using namespace genv;

Slide::Slide(float _x, float _y, float _mx, float _my, int _minimum, int _maximum):Widget(_x,_y,_mx,_my)
{
    minimum = _minimum;
    maximum=_maximum;
    ertek = 0;
    mouse_1 = 0;
    mouse_2 = 0;
    pctg = 0;
    pos = 0;
    div = maximum-minimum;
    klikkelve=0;
}

void Slide :: rajzol()
{
    gout << color(150,150,150) << move_to(x,y) << box(mx,my)
         << color(1,1,1) << move_to(x+pos,y) << box(my,my);
    if(mouse_1)
    {
        gout << color(150,150,150) << move_to(x-10,y) << box(10,my);
    }
    if(mouse_2)
    {
        gout << color(150,150,150) << move_to(x+mx,y) << box(10,my);
    }
    gout << color(1,1,1) << move_to(x-4,y+5) << line_to(x-9,y+my/2) << line_to(x-4,y+my-5)
         << color(1,1,1) << move_to(x+mx+3,y+5) << line_to(x+mx+8,y+my/2) << line_to(x+mx+3,y+my-5);
    if(fokuszalva)
    {
        gout << color(1,1,255) << move_to(x,y) << line(mx,0) << line(0,my) << line(-mx,0) << line(0,-my);
    }
}

void Slide :: klikk(event ev)
{
    if(ev.type==ev_mouse)
    {
        if(ev.button == 1)
        {
            if(ev.pos_x < x || ev.pos_x > x+mx || ev.pos_y < y || ev.pos_y > y+my)
            {
                klikkelve = 0;
                fokuszalva = 0;
            }
        }
        if(ev.button == 1 && ev.pos_x > x && ev.pos_x < x+mx && ev.pos_y > y && ev.pos_y < y+my)
        {
            klikkelve = 1;
            fokuszalva = 1;
        }
        if(klikkelve)
        {
            pos = int(((ev.pos_x-x)/((mx-my)/div))-(my/(500/div)))*((mx-my)/div);
            pctg = pos/((mx-my)/div);
            if(pos < 0)
            {
                pos = 0;
                pctg = 0;
            }
            if(pos > mx-my)
            {
                pos = mx-my;
                pctg = div;
            }
        }
        if(ev.button == -1)
        {
            klikkelve = 0;
        }
        if(ev.pos_x > x-10 && ev.pos_x < x && ev.pos_y > y && ev.pos_y < y+my)
        {
            mouse_1 = 1;
            if(ev.button == 1 && pctg > 0)
            {
                pos-=(mx-my)/div;
                pctg--;
            }
        }
        else mouse_1 = 0;
        if(ev.pos_x > x+mx && ev.pos_x < x+mx+10 && ev.pos_y > y && ev.pos_y < y+my)
        {
            mouse_2 = 1;
            if(ev.button == 1 && pctg < div)
            {
                pos+=(mx-my)/div;
                pctg++;
            }
        }
        else mouse_2 = 0;
    }
    if(fokuszalva)
    {
        if(ev.keycode == key_up || ev.keycode == key_right)
        {
            if(pctg < div)
            {
                pos+=(mx-my)/div;
                pctg++;
            }
        }
        if(ev.keycode == key_down || ev.keycode == key_left)
        {
            if(pctg > 0)
            {
                pos-=(mx-my)/div;
                pctg--;
            }
        }
        if(ev.keycode == key_pgup)
        {
            if(pctg < div-2)
            {
                pos+=2*((mx-my)/div);
                pctg++;
                pctg++;
            }
            else
            {
                pos = mx-my;
                pctg = div;
            }
            if(pos > mx-my)
            {
                pos = mx-my;
                pctg = div;
            }
        }
        if(ev.keycode == key_pgdn)
        {
            if(pctg > 2)
            {
                pos-=2*((mx-my)/div);
                pctg--;
                pctg--;
            }
            else
            {
                pos = 0;
                pctg = 0;
            }
            if(pos < 0)
            {
                pos = 0;
                pctg = 0;
            }
        }
    }
    ertek = minimum+(maximum-minimum)/div*pctg;

}

int Slide::GetErtek()
{
    return ertek;
}

//
//void Slide :: kiirat(event ev){
//    if(ev.keycode == key_f2){
//        ifstream bef("kimenet.txt");
//        vector<string>text;
//        if(bef.good()){
//            while(!bef.eof()){
//                string helper;
//                getline(bef,helper);
//                text.push_back(helper);
//            }
//        }
//        ofstream kif("kimenet.txt");
//        for(size_t i = 0; i < text.size(); ++i){
//            kif << text[i] << "\n";
//        }
//        kif << ertek;
//    }
//}
