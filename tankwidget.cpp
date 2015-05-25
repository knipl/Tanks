#include "tankwidget.h"
#include "graphics.hpp"
#include <math.h>
#include <iostream>

using namespace std;
using namespace genv;


TankWidget :: TankWidget(float _x, float _y, float _mx, float _my, Tank *_tank):Widget(_x,_y,_mx,_my), tank(_tank)
{

}

void TankWidget::rajzol()
{
    if(tank -> GetEle())
    {

    float loveg = tank -> GetLoveg();
    float pi=3.14159265;
    if(tank -> GetPlayer())
    {
        if(tank -> GetGolyoLatszodik())
        {
            gout<<move_to(tank ->GetX(), tank -> GetY())<< color(200,10,10)<< box(30,30);
            gout<<move_to(tank ->GetX(), tank -> GetY()+10) << line(-(sqrt(900) * cos(loveg*pi/180)), sqrt(900)*sin(-loveg*pi/180));
            gout<<move_to(tank ->GetGolyoX(), tank ->GetGolyoY()+10)<<color(1,1,1)<<box(3,3);
        }
        else
        {
            gout<<move_to(tank ->GetX(), tank -> GetY())<< color(200,10,10)<< box(30,30);
            gout<<move_to(tank ->GetX(), tank -> GetY()+10) << line(-(sqrt(900) * cos(loveg*pi/180)), sqrt(900)*sin(-loveg*pi/180));
        }
    }
    else
    {   if(tank -> GetGolyoLatszodik())
        {
            gout<<move_to(tank ->GetX(), tank -> GetY())<< color(10,10,200)<< box(30,30);
            gout<<move_to(tank ->GetX() + 30, tank -> GetY()+10) << line((sqrt(900) * cos(loveg*pi/180)), sqrt(900)*sin(-loveg*pi/180));
            gout<<move_to(tank ->GetGolyoX(), tank ->GetGolyoY()+10)<<color(1,1,1)<<box(3,3);
        }
        else
        {
            gout<<move_to(tank ->GetX(), tank -> GetY())<< color(10,10,200)<< box(30,30);
            gout<<move_to(tank ->GetX() + 30, tank -> GetY()+10) << line((sqrt(900) * cos(loveg*pi/180)), sqrt(900)*sin(-loveg*pi/180));
        }
    }
    }
    else
    {   gout<<move_to(0,0)<<color(1,1,1)<<box(800,400);
        gout<<move_to(350,200)<<color(199,199,199) <<text("Game Over \n Nyomj Esc-et a kilépéshez!");

    }



}
