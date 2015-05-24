#include "tank.h"
#include <math.h>
using namespace std;

Tank::Tank(float _x, float _y, bool Pl, float _loveg)
    : x(_x), y(_y), Player(Pl), loveg(_loveg)
{    float pi=3.14159265;

    loveg = 0;
    ele = true;
    golyo.x=x+(sqrt(900) * cos(loveg*pi/180));
    golyo.y=y+(sqrt(900)*sin(-loveg*pi/180));
}

void Tank::SetEle(bool _ele){
    ele=_ele;
}
void Tank::SetLoveg(float _loveg){
    loveg=_loveg;
}
void Tank::SetGolyoX(float _x){
    golyo.x=_x;
}
void Tank::SetGolyoY(float _y){
    golyo.y=_y;
}
void Tank::SetGolyoLatszodik(bool _latszodik){
    golyo.latszodik=_latszodik;
}
void Tank::SetSebesseg(float _sebesseg){
    golyo.sebesseg=_sebesseg;
}
bool Tank::GetEle(){
    return ele;
}
float Tank::GetLoveg(){
    return loveg;
}
float Tank::GetGolyoX(){
    return golyo.x;
}
float Tank::GetGolyoY(){
    return golyo.y;
}

float Tank::GetX(){
    return x;
}
float Tank::GetY(){
    return y;
}

bool Tank::GetGolyoLatszodik(){
    return golyo.latszodik;
}

bool Tank::GetPlayer(){
    return Player;
}
float Tank::GetSebesseg(){
    return golyo.sebesseg;
}



