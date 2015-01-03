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
//#include "Plaque.h"

using namespace std;

namespace Gaia {

    enum DRAW_STYLE {
        DRAW_POINT,
        DRAW_LINE,
        DRAW_TRIANGLE
    };

    class Planet {
        public:
            Planet();
            ~Planet();
            int GetNPoints();
            void Draw(DRAW_STYLE style);
            void Divide();

        private:
            int radius; // en mètres
            Point* center;
            vector<Point*> points;
            vector<Segment*> segments;
            vector<Triangle*> triangles;
//            vector<Plaque> plaques;
//            map<int, Triangle> villes;
    };
} // ns Gaia

#endif /* __PLANET_H__ */
