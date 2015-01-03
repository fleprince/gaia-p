/*
 * Triangle.cpp
 * Copyright (C) 2014 Florian Leprince <floleprince@gmail.com>
 *
 * Distributed under terms of the GNU GPL V2 license.
 */

#include "Triangle.h"
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <stdlib.h>

namespace Gaia {
    Triangle::Triangle(Point* A, Point* B, Point* C) {
        p[0] = A;
        p[1] = B;
        p[2] = C;

        s[0] = A->FindLink(B); // AB
        s[1] = B->FindLink(C); // BC
        s[2] = C->FindLink(A); // CA

        s[0]->AddTriangle(this);
        s[1]->AddTriangle(this);
        s[2]->AddTriangle(this);

        color[0] = rand() % 256;
        color[1] = rand() % 256;
        color[2] = rand() % 256;
    }

    Triangle::~Triangle() {
    }

    void Triangle::Draw() {
        glColor3ub(color[0], color[1], color[2]);
        p[0]->Draw();
        p[1]->Draw();
        p[2]->Draw();
    }
}

