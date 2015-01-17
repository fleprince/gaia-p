/*
 * Triangle.h
 * Copyright (C) 2014 Florian Leprince <floleprince@gmail.com>
 *
 * Distributed under terms of the GNU GPL V2 license.
 */

#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include <string>
#include "Point.h"
#include "Segment.h"

using namespace std;

namespace Gaia {
    class Planet;
    class Plaque;

    class Triangle {
        public:
            Triangle(Point* A, Point* B, Point* C);
            ~Triangle();
            void Draw(Point* pcam);
            void Divide(Planet* planet);
            Triangle* GetNeighbor(unsigned int num);
            Plaque* plaque;

        private:
            int pid;
            string nom;
            Point* p[3];
            Segment* s[3];
    };
}

#endif /* __TRIANGLE_H__ */
