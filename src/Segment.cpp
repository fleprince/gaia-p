/*
 * Segment.cpp
 * Copyright (C) 2014 Florian Leprince <floleprince@gmail.com>
 *
 * Distributed under terms of the GNU GPL V2 license.
 */

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include "Segment.h"
#include "Triangle.h"

namespace Gaia {
    Segment::Segment(Point* _A, Point* _B) : A(_A), B(_B) {
        A->AddSegment(this);
        B->AddSegment(this);
        t1 = nullptr;
        t2 = nullptr;
        M = nullptr;
        newMiddle = true;
    }

    Segment::~Segment() {
        A->RemoveSegment(this);
        B->RemoveSegment(this);
    }

    void Segment::Draw() {
        A->Draw();
        B->Draw();
    }

    void Segment::AddTriangle(Triangle* t) {
        if (t != nullptr) {
            if (t1 == nullptr) {
                t1 = t;
            } else if (t2 == nullptr) {
                t2 = t;
            }
        }
    }

    void Segment::RemoveTriangle(Triangle* t) {
        if (t != nullptr) {
            if (t1 == t) {
                t1 = nullptr;
            } else if (t2 == t) {
                t2 = nullptr;
            }
        }
    }

    Point* Segment::Middle() {
        if (M == nullptr) {
           M = new Point(A, B);
           newMiddle = false;
        }
        return M;
    }

    Point* Segment::Other(Point* p) {
        if (p == nullptr) return nullptr;
        else if (p == A) return B;
        else if (p == B) return A;
        else return nullptr;
    }

    Triangle* Segment::Other(Triangle* t) {
        if (t == nullptr) return nullptr;
        else if (t == t1) return t2;
        else if (t == t2) return t1;
        else return nullptr;
    }

    bool Segment::isNewMiddle() {
        return newMiddle;
    }
}

