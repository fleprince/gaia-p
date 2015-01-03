/*
 * Point.h
 * Copyright (C) 2014 Florian Leprince <floleprince@gmail.com>
 *
 * Distributed under terms of the GNU GPL V2 license.
 */

#ifndef __POINT_H__
#define __POINT_H__

#include <vector>
using namespace std;

namespace Gaia {
    class Segment;

    class Point{
        public:
            Point();
            Point(Point* A, Point* B);
            ~Point();
            void setCartesian(double _x, double _y, double _z);
            void setSpherical(double _p, double _a, double _r);
            void Draw();
            void AddSegment(Segment* s);
            Segment* FindLink(Point* p);

        private:
            double x, y, z;
            double p, a, r;

            vector<Segment*> segments;
    };
}

#endif /* __POINT_H__ */
