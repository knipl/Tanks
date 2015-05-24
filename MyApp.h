#ifndef MYAPP_H_INCLUDED
#define MYAPP_H_INCLUDED

#include "Application.h"
#include "widget.hpp"
#include "button.hpp"
#include "tank.h"
#include "tankwidget.h"
#include "JatekMester.h"
#include "slide.hpp"

class MyApp: public Application{
protected:
    JatekMester * JM;
Tank * tank0;
Tank * tank1;
Slide * lovegallito;
Slide * power;
Gomb * fire;
public:
    MyApp(const int sz, const int m);
    void ki();
};

#endif // MYAPP_H_INCLUDED
