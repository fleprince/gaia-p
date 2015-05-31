/*
 * Plaque.h
 * Copyright (C) 2015 Florian Leprince <floleprince@gmail.com>
 *
 * Distributed under terms of the GNU GPL V2 license.
 */

#ifndef __PLAQUE_H__
#define __PLAQUE_H__

#include <vector>
#include "Triangle.h"

namespace Gaia {
    class Plaque {
        public:
            Plaque(Triangle *root);
            ~Plaque();
            void UseGLColor();
            bool Step();
            int GetId();
            float GetRatio();

        private:
            int id;
            vector<Triangle*> in;
            vector<Triangle*> onedge;
            int color[3];
            bool canGrow;
            int edgelength;
            int ntriangles;
    };
}

#endif /* __PLAQUE_H__ */
