#include "JatekMester.h"
#include <math.h>
#include <iostream>

JatekMester::JatekMester(bool _aktiv) : aktiv(_aktiv) {
    ido = 0;
}

void JatekMester::Fire(Tank *tank)
{
    if(tank -> GetEle())
    {

        float golyo_x=tank -> GetGolyoX();
        float golyo_y=tank -> GetGolyoY();

        float pi=3.14159265;
        tank -> SetGolyoLatszodik(1);

        if(tank -> GetPlayer())
        {
            tank -> SetGolyoX(tank -> GetGolyoX() - tank -> GetSebesseg() * cos(tank -> GetLoveg()*pi/180));
            tank -> SetGolyoY(tank -> GetGolyoY() - tank -> GetSebesseg() * sin(tank -> GetLoveg()*pi/180) + ido);
            ido += 1;
        }
        else
        {
            tank -> SetGolyoX(tank -> GetGolyoX() + tank -> GetSebesseg() * cos(tank -> GetLoveg()*pi/180));
            tank -> SetGolyoY(tank -> GetGolyoY() - tank -> GetSebesseg() * sin(tank -> GetLoveg()*pi/180) + ido);
            ido += 1;
        }

        if(tank -> GetPlayer())
        {
            if (golyo_x > 50 && golyo_x < 50+30 && golyo_y > 300 && golyo_y < 300+30)
            {
                tank -> SetEle(0);
            }
            if (tank -> GetGolyoY() >= 600)
            {
                tank ->SetGolyoX(tank -> GetX() -(sqrt(900) * cos(tank -> GetLoveg()*pi/180)));
                tank ->SetGolyoY(tank -> GetY() +(sqrt(900) * sin(-tank -> GetLoveg()*pi/180)));
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
            if (tank -> GetGolyoY() >= 600)
            {
                tank ->SetGolyoX(1.5*tank -> GetX() +(sqrt(900) * cos(tank -> GetLoveg()*pi/180)));
                tank ->SetGolyoY(tank -> GetY() +(sqrt(900) * sin(-tank -> GetLoveg()*pi/180)));
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
void JatekMester::AktivFelcserel(){
    aktiv = !aktiv;
}
