#ifndef TANK_H_INCLUDED
#define TANK_H_INCLUDED

#include "lovedek.h"

using namespace std;

class Tank{
public:
    bool ele;
    bool Player;
    float x,y;
    float loveg;
    Lovedek golyo;

    Tank(float _x, float _y, bool Pl, float _loveg);
    void SetEle(bool _ele);
    void SetLoveg(float _loveg);
    void SetGolyoX(float _x);
    void SetGolyoY(float _y);
    void SetGolyoLatszodik(bool _latszodik);
    void SetSebesseg(float _sebesseg);
    bool GetEle();
    float GetLoveg();
    float GetGolyoX();
    float GetGolyoY();
    float GetX();
    float GetY();
    bool GetGolyoLatszodik();
    bool GetPlayer();
    float GetSebesseg();





};


#endif // TANK_H_INCLUDED
