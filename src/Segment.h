/*
 * Segment.h
 * Copyright (C) 2014 Florian Leprince <floleprince@gmail.com>
 *
 * Distributed under terms of the GNU GPL V2 license.
 */

#ifndef __SEGMENT_H__
#define __SEGMENT_H__

#include "Point.h"

namespace Gaia {
    class Triangle;

    class Segment{
        public:
            Segment(Point* _A, Point* _B);
            ~Segment();
            void Draw();
            void AddTriangle(Triangle* t);
            void RemoveTriangle(Triangle* t);
            Point* Middle();
            Point* Other(Point* p);
            Triangle* Other(Triangle* t);
            bool isNewMiddle();

        private:
            Point *A,*B;
            Point *M;
            Triangle *t1, *t2;
            bool newMiddle;
    };
}

#endif /* __SEGMENT_H__ */
