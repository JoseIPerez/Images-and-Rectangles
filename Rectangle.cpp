#include <iostream>
#include "Rectangle.h"
#include "Frame.h"
#include "global.h"

extern Frame frame;
void Rectangle::setSpeed(double dx, double dy) {
    this->dx = dx;
    this->dy = dy;
}

void Rectangle::update(double dt) {
    x += dx*dt;
    y += dy*dt;
}
void Rectangle::draw() const {
    double x0 = x;
    double x1 = x + w;
    double y0 = y;
    double y1 = y + h;
    for (double y = y0; y < y1; ++y) {
        for (double x = x0; x < x1; ++x) {
            frame.setPixel(x, y, r, g, b);
        }
    }
}
