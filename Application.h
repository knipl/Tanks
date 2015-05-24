#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include "widget.hpp"
#include "graphics.hpp"
#include <vector>

class Application{
protected:
    genv::event ev;
    const int szeles,magas;
    std::vector<Widget *> widgets;
public:
    Application(const int sz, const int m);
    void torol();
};

#endif // APPLICATION_H_INCLUDED
