#include "tank.h"

using namespace genv;
using namespace std;

Tank::Tank(float _x, float _y, float _mx, float _my, bool Pl):Widget(_x,_y, _mx, _my){
    Player=Pl;
}

void Tank::rajzol(){
    if(Player){
    gout<<move_to(x,y)<< color(200,10,10)<< box(30,30);

    }
    else{
    gout<<move_to(x,y)<< color(10,10,200)<< box(30,30);

    }
}



