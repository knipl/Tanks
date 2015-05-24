#ifndef JATEKMESTER_H_INCLUDED
#define JATEKMESTER_H_INCLUDED

#include "tank.h"

class JatekMester{
protected:
    bool aktiv;
    bool loves;
    float ido;
public:
    JatekMester(bool _aktiv);
    void Fire(Tank *tank);
    void LovesIgaz();
    bool LovesGetter();
    bool AktivGetter();
    void AktivFelcserel();
};


#endif // JATEKMESTER_H_INCLUDED
