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
#include <iostream>
#include "Planet.h"
#include "Plaque.h"

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

        plaque = nullptr;
    }

    Triangle::~Triangle() {
    }

    void Triangle::Draw(Point* pcam) {
        if (p[0]->isViewableFrom(pcam)
         || p[1]->isViewableFrom(pcam)
         || p[2]->isViewableFrom(pcam))
        {
            if (plaque == nullptr)
                glColor3ub(255, 255, 255);
            else
                plaque->UseGLColor();

            p[0]->Draw();
            p[1]->Draw();
            p[2]->Draw();
        }
    }

    void Triangle::Divide(Planet* planet) {
        bool ans;

        ans = s[0]->isNewMiddle();
        Point* mab = s[0]->Middle();
        if (ans) {
            planet->AddPoint(mab);
            planet->AddSegment(new Segment(p[0], mab));
            planet->AddSegment(new Segment(p[1], mab));
        }

        ans = s[1]->isNewMiddle();
        Point* mbc = s[1]->Middle();
        if (ans) {
            planet->AddPoint(mbc);
            planet->AddSegment(new Segment(p[1], mbc));
            planet->AddSegment(new Segment(p[2], mbc));
        }

        ans = s[2]->isNewMiddle();
        Point* mca = s[2]->Middle();
        if (ans) {
            planet->AddPoint(mca);
            planet->AddSegment(new Segment(p[0], mca));
            planet->AddSegment(new Segment(p[2], mca));
        }

        planet->AddSegment(new Segment(mca, mab));
        planet->AddSegment(new Segment(mbc, mab));
        planet->AddSegment(new Segment(mbc, mca));

        planet->AddTriangle(new Triangle(p[0], mab, mca));
        planet->AddTriangle(new Triangle(p[1], mbc, mab));
        planet->AddTriangle(new Triangle(p[2], mca, mbc));
        planet->AddTriangle(new Triangle(mab, mbc, mca));

        Triangle* tmpt;
        tmpt = s[0]->Other(this);
        s[0]->RemoveTriangle(this);
        if (tmpt == nullptr) delete s[0];

        tmpt = s[1]->Other(this);
        s[1]->RemoveTriangle(this);
        if (tmpt == nullptr) delete s[1];

        tmpt = s[2]->Other(this);
        s[2]->RemoveTriangle(this);
        if (tmpt == nullptr) delete s[2];

        delete this;
    }

    Triangle* Triangle::GetNeighbor(unsigned int num) {
        if (num < 3) {
            return s[num]->Other(this);
        } else {
            return nullptr;
        }
    }
}

