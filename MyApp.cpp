#include "MyApp.h"
#include <iostream>
using namespace genv;
using namespace std;

MyApp::MyApp(const int sz, const int  m) :  Application(sz,m)
{
    JM = new JatekMester(true);
    tank0 = new Tank(50,300,0,0);
    tank1 = new Tank(700,300,1,0);
    TankWidget * PL1 = new TankWidget(0,0,0,0, tank0);
    widgets.push_back(PL1);
    TankWidget * PL0 = new TankWidget(0,0,0,0, tank1);
    widgets.push_back(PL0);
    lovegallito = new Slide(50,50,150,20,0,90,"Direction");
    widgets.push_back(lovegallito);
    power = new Slide(600,50,100,20,0,50,"Power");
    widgets.push_back(power);

    fire = new Gomb(375,50,50,20,[&]()
    {

        JM -> LovesIgaz();


    },"FIRE");
    widgets.push_back(fire);

}

void MyApp::ki()
{

    gin.timer(60);
    while(gin >> ev && ev.keycode!=key_escape)
    {
        torol();
        for(size_t i = 0; i<widgets.size(); i++)
        {
            widgets[i]->rajzol();
        }

        lovegallito -> klikk(ev);
        fire -> klikk(ev);
        power -> klikk(ev);
        if(!JM -> AktivGetter())
        {
            tank0 -> SetLoveg(lovegallito-> GetErtek());
            tank0 -> SetSebesseg(power -> GetErtek());
        }
        else
        {
            tank1 -> SetLoveg(lovegallito -> GetErtek());
            tank1 -> SetSebesseg(power -> GetErtek());
        }

        if(ev.time)
        {
            if(JM -> LovesGetter())
            {
                if(JM ->AktivGetter())
                    JM -> Fire(tank1);
                else JM -> Fire(tank0);
            }
        }

        gout<<refresh;
    }

}

