#pragma once
#include <vector>
#include "Frame.h"
#include "global.h"
#include "Object.h"

class Rectangle : public Object{
public:
    Rectangle(double h, double w, double x, double y, byte r, byte g, byte b): h(h), w(w), x(x), y(y), r(r), g(g), b(b) {}
    
    virtual void draw() const;
    virtual void update(double dt);
    
    void setSpeed(double dx, double dy);
private:
    byte r, g, b;
    double h, w, x, y, dx, dy, dp;
    
};
