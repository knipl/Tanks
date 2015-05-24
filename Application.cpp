#include "Application.h"
#include <iostream>

using namespace genv;

Application::Application(const int sz, const int m): szeles(sz), magas(m){

    gout.open(szeles,magas);

}

void torol()
{
    gout << move_to(0,0) << color(10,10,100) << box(800, 800);
}
