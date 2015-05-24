#include "Application.h"
#include <iostream>

using namespace genv;

Application::Application(const int sz, const int m): szeles(sz), magas(m){

    gout.open(szeles,magas);

}

void Application::torol()
{
    gout << move_to(0,0) << color(200,200,200) << box(szeles, magas);
}
