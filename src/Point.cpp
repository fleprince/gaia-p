/*
 * Point.cpp
 * Copyright (C) 2014 Florian Leprince <floleprince@gmail.com>
 *
 * Distributed under terms of the GNU GPL V2 license.
 */

#include "Point.h"

namespace Gaia {
    Point::Point() {
        x = 0;
        y = 0;
        z = 0;
        p = 0;
        a = 0;
        r = 0;
    }

    Point::~Point() {
    }

    void Point::setCartesian(float _x, float _y, float _z) {
        x = _x;
        y = _y;
        z = _z;
        // TODO : others coordinates
    }

    void Point::setSpherical(float _p, float _a, float _r) {
        p = _p;
        a = _a;
        r = _r;
        // TODO : others coordinates
    }
}

