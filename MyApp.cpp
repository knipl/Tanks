#include "MyApp.h"



using namespace genv;
using namespace std;


Tank * PL1 = new Tank(50, 300,0,0,1); widgets.push_back(PL1);
Tank * PL0 = new Tank(650,300,0,0,0); widgets.push_back(PL0);

Gomb * fire = new Gomb(375,50,50,20,[&](){},"FIRE"); widgets.push_back(fire);

MyApp::ki(){

    gin.timer(60);
    while(gin >> ev && ev.keycode!=key_escape) {
            torol();
            for(size_t i = 0; i<widgets.size();i++){
                widgets[i]->rajzol();
            }
            gout<<refresh;
    }
}

