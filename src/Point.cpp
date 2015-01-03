/*
 * Point.cpp
 * Copyright (C) 2014 Florian Leprince <floleprince@gmail.com>
 *
 * Distributed under terms of the GNU GPL V2 license.
 */

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include "Point.h"
#include "Segment.h"

namespace Gaia {
    Point::Point() {
        x = 0;
        y = 0;
        z = 0;
        p = 0;
        a = 0;
        r = 0;
    }

    Point::Point(Point* A, Point* B) {
        this->setCartesian(A->x+B->x, A->y+B->y, A->z+B->z);
        this->setSpherical(this->p, this->a, A->r);
    }

    Point::~Point() {
    }

    void Point::setCartesian(double _x, double _y, double _z) {
        x = _x;
        y = _y;
        z = _z;

        // others coordinates
        r = sqrt(x*x + y*y + z*z);
        if (r == 0.0) {
            p = 0.0;
            a = 0.0;
        } else {
            p = asin(z/r) * 180 / M_PI;
            if (x == 0.0) {
                if (y > 0.0) {
                    a = 90.0;
                } else if (y == 0.0) {
                    a = 0.0;
                } else {
                    a = -90.0;
                }
            } else {
                a = atan(y/x);
            }
        }
    }

    void Point::setSpherical(double _p, double _a, double _r) {
        p = fmod(_p, 360.0);
        if (p >= 270) {
            p -= 360;
        } else if (p > 90) {
            p = 180 - p;
            a += 180;
        }
        a = fmod(a+_a, 360.0);
        if (a >= 180) {
            a -= 360;
        }
        if (_r < 0) {
            r = -_r;
            a = -a;
            p = -p;
        } else {
            r = _r;
        }

        // others coordinates
        x = r * cos(p * M_PI / 180) * cos(a * M_PI / 180);
        y = r * cos(p * M_PI / 180) * sin(a * M_PI / 180);
        z = r * sin(p * M_PI / 180);
    }

    void Point::Draw() {
        glVertex3d(x, y, z);
    }

    void Point::AddSegment(Segment* s) {
        segments.push_back(s);
    }

    Segment* Point::FindLink(Point* p) {
        Segment* res = nullptr;
        if (p == nullptr) return res;
        for (vector<Segment*>::iterator it=segments.begin(); it!=segments.end(); ++it) {
            if ((*it)->Other(this) == p) {
                res = *it;
                break;
            }
        }
        return res;
    }
}

