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
//#include "Plaque.h"
//#include "Triangle.h"
using namespace std;

namespace Gaia {

    class Planet {
        public:
            Planet();
            ~Planet();
            int GetNPoints();

        private:
            int radius; // en mètres
            Point* center;
            vector<Point*> points;
//            vector<Plaque> plaques;
//            map<int, Triangle> villes;
            void Divide();
    };
} // ns Gaia

#endif /* __PLANET_H__ */
