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
            void setCartesian(float _x, float _y, float _z);
            void setSpherical(float _p, float _a, float _r);

        private:
            float x, y, z;
            float p, a, r;
    };
}

#endif /* __POINT_H__ */
