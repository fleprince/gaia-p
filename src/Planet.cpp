/*
 * Earth.cpp
 * Copyright (C) 2014 Florian Leprince <floleprince@gmail.com>
 *
 * Distributed under terms of the GNU GPL V2 license.
 */

#include <iostream>
#include <math.h>
#include "Planet.h"

using namespace std;
namespace Gaia {
    Planet::Planet() {
        float originlat = atan(1/2) * 180 / M_PI;
        radius = 6371000;
        center = new Point();
        cout << "Creating planet with " << radius/1000 << " km as radius." << endl;

        Point* top = new Point();
        Point* bottom = new Point();
        Point* t[5];
        Point* b[5];
        top->setSpherical(90.0, 0.0, radius);
        bottom->setSpherical(-90.0, 0.0, radius);
        points.push_back(top);
        points.push_back(bottom);

        for (int i=0 ; i<5 ; i++) {
            t[i] = new Point();
            b[i] = new Point();
            t[i]->setSpherical(originlat, i * 360.0/5, radius);
            b[i]->setSpherical(-originlat, i * 360.0/5 + 36.0, radius);
            points.push_back(t[i]);
            points.push_back(b[i]);
        }
    }

    Planet::~Planet() {
        delete center;
        // TODO : delete all triangles, plaques, points
    }

    int Planet::GetNPoints() {
        return points.size();
    }

    void Planet::Divide() {
    }
}
