/*
 * Point.h
 * Copyright (C) 2014 Florian Leprince <floleprince@gmail.com>
 *
 * Distributed under terms of the GNU GPL V2 license.
 */

#ifndef __POINT_H__
#define __POINT_H__

namespace Gaia {
    class Point{
        public:
            Point();
            ~Point();
            void setCartesian(double _x, double _y, double _z);
            void setSpherical(double _p, double _a, double _r);

        private:
            double x, y, z;
            double p, a, r;
    };
}

#endif /* __POINT_H__ */
