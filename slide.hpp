#ifndef SLIDE_H_INCLUDED
#define SLIDE_H_INCLUDED


class Slide:public Widget{
private:
    int ertek, maximum, minimum;
    float pctg, div;
    double pos;
    bool mouse_1, mouse_2, klikkelve;
public:
    Slide(float _x, float _y, float _mx, float _my, int _minimum, int _maximum);
    void rajzol();
    void klikk(genv::event ev);
    int GetErtek();
   // void kiirat(genv::event ev);
};

#endif // SLIDE_H_INCLUDED
