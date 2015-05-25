#include "Application.h"
#include <iostream>

using namespace genv;

Application::Application(const int sz, const int m): szeles(sz), magas(m)
{

    gout.open(szeles,magas);

}

void Application::torol()
{
    gout << move_to(0,0) << color(100,200,255) << box(szeles, magas);
}
