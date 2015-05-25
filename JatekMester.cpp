#include "JatekMester.h"
#include <math.h>
#include <iostream>

JatekMester::JatekMester(bool _aktiv) : aktiv(_aktiv)
{
    ido = 0;
}

void JatekMester::Fire(Tank *tank)
{
    if(tank -> GetEle())
    {

        float golyo_x=tank -> GetGolyoX();
        float golyo_y=tank -> GetGolyoY();
        float loveg=tank -> GetLoveg();
        float tank_x=tank -> GetX();
        float tank_y=tank -> GetY();

        float pi=3.14159265;
        tank -> SetGolyoLatszodik(1);

        if(tank -> GetPlayer())
        {
            tank -> SetGolyoX(golyo_x - tank -> GetSebesseg() * cos(loveg*pi/180));
            tank -> SetGolyoY(golyo_y - tank -> GetSebesseg() * sin(loveg*pi/180) + ido);
            ido += 1;
        }
        else
        {
            tank -> SetGolyoX(golyo_x + tank -> GetSebesseg() * cos(loveg*pi/180));
            tank -> SetGolyoY(golyo_y - tank -> GetSebesseg() * sin(loveg*pi/180) + ido);
            ido += 1;
        }

        if(tank -> GetPlayer())
        {
            if (golyo_x > 50 && golyo_x < 50+30 && golyo_y > 300 && golyo_y < 300+30)
            {
                tank -> SetEle(0);
            }
            if (tank -> GetGolyoX() <= 0 || tank -> GetGolyoY() >= 400)
            {
                tank ->SetGolyoX(tank_x -(sqrt(900) * cos(loveg*pi/180)));
                tank ->SetGolyoY(tank_y -(sqrt(900) * sin(loveg*pi/180)));
                ido = 0;
                AktivFelcserel();
                tank -> SetGolyoLatszodik(0);
                loves = false;
            }

        }
        else
        {
            if (golyo_x > 700 && golyo_x < 700+30 && golyo_y > 300 && golyo_y < 300+30)
            {
                tank -> SetEle(0);
            }
            if (tank -> GetGolyoX() >= 800 || tank -> GetGolyoY() >= 400)
            {
                tank ->SetGolyoX(1.5*tank_x +(sqrt(900) * cos(loveg*pi/180)));
                tank ->SetGolyoY(tank_y +(sqrt(900) * sin(-loveg*pi/180)));
                ido = 0;
                AktivFelcserel();
                tank -> SetGolyoLatszodik(0);
                loves = false;
            }
        }
    }
}

void JatekMester::LovesIgaz()
{
    loves = true;
}

bool JatekMester::LovesGetter()
{
    return loves;
}

bool JatekMester::AktivGetter()
{
    return aktiv;
}
void JatekMester::AktivFelcserel()
{
    aktiv = !aktiv;
}
