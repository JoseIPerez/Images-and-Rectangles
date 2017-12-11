#pragma once
#include "global.h"

class Object {
public:
    virtual void draw() const = 0;
    virtual void update(double dt) = 0;
};
