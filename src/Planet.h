/*
 * Earth.h
 * Copyright (C) 2014 Florian Leprince <floleprince@gmail.com>
 *
 * Distributed under terms of the GNU GPL V2 license.
 */

#ifndef __PLANET_H__
#define __PLANET_H__

#include <vector>
#include <map>
#include "Point.h"
#include "Segment.h"
#include "Triangle.h"
#include "Plaque.h"

using namespace std;

namespace Gaia {

    enum DRAW_STYLE {
        DRAW_POINT      = (1 << 0),
        DRAW_LINE       = (1 << 1),
        DRAW_TRIANGLE   = (1 << 2)
    };

    class Planet {
        public:
            Planet();
            ~Planet();
            void Draw(Point* pcam, DRAW_STYLE style);
            void Divide(int n);
            void AddPoint(Point* p);
            void AddSegment(Segment* s);
            void AddTriangle(Triangle* t);
            bool Step();

        private:
            int radius; // en mètres
            Point* center;
            vector<Point*> points;
            vector<Segment*> segments;
            vector<Triangle*> triangles;
            vector<Plaque*> plaques;
//            map<int, Triangle> villes;
            void Divide();
    };
} // ns Gaia

#endif /* __PLANET_H__ */
