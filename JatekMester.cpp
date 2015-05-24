#include "JatekMester.h"
#include <math.h>
#include <iostream>

JatekMester::JatekMester(bool _aktiv) : aktiv(_aktiv) {
ido = 0;
}

void JatekMester::Fire(Tank *tank)
{
    float pi=3.14159265;

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

        if (tank -> GetGolyoY() >= 600)
        {
            cout << "lofasz";
            loves = false;
            tank ->SetGolyoX(tank -> GetX() +(sqrt(900) * cos(tank -> GetLoveg()*pi/180)));
            tank ->SetGolyoY(tank -> GetY() +(sqrt(900) * sin(tank -> GetLoveg()*pi/180)));
            ido = 0;
            AktivFelcserel();
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
