#pragma once
#include "global.h"
#include "Object.h"

class Image : public Object {
public:
    Image() : w(0), h(0), x0(0), y0(0), dx(0), dy(0),  pixels(nullptr){ }
    ~Image() { delete [] pixels; }
    void load(const char * filename, int w, int h);
    
    virtual void draw() const;
    virtual void update(double dt);
    
    void setSpeed(double dx, double dy);
    void getX(double x) { x0 = x; }
    void getY(double y) { y0 = y; }
    
private:
    byte * pixels;
    int w;  // width of image in pixels
    int h;  // height of image in pixels
    double x0, y0;  // Location of image inside of the frame.
    double dx, dy;
};
