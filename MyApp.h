#ifndef MYAPP_H_INCLUDED
#define MYAPP_H_INCLUDED

#include "Application.h"
#include "widget.hpp"
#include "button.hpp"
#include "tank.h"

class MyApp: public Application{
protected:

public:
    MyApp(const int sz, const int m);
    void ki();
};

#endif // MYAPP_H_INCLUDED
