/*
 * Earth.cpp
 * Copyright (C) 2014 Florian Leprince <floleprince@gmail.com>
 *
 * Distributed under terms of the GNU GPL V2 license.
 */

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <math.h>
#include "Planet.h"

using namespace std;
namespace Gaia {
    Planet::Planet() {
        double originlat = atan(0.5) * 180 / M_PI;
        radius = 2; //6371000;
        center = new Point();

        Point* top = new Point();
        Point* bottom = new Point();
        Point* t[5];
        Point* b[5];
        top->setSpherical(90.0, 0.0, radius);
        bottom->setSpherical(-90.0, 0.0, radius);
        points.push_back(top);
        points.push_back(bottom);

        for (int i=0 ; i<5 ; i++) {
            t[i] = new Point();
            b[i] = new Point();
            t[i]->setSpherical(originlat, i * 360.0/5, radius);
            b[i]->setSpherical(-originlat, i * 360.0/5 + 36.0, radius);
            points.push_back(t[i]);
            points.push_back(b[i]);

            segments.push_back(new Segment(top, t[i]));
            segments.push_back(new Segment(bottom, b[i]));
            segments.push_back(new Segment(t[i], b[i]));

            if (i > 0) {
                segments.push_back(new Segment(t[i], t[i-1]));
                segments.push_back(new Segment(b[i], b[i-1]));
                segments.push_back(new Segment(t[i], b[i-1]));
                triangles.push_back(new Triangle(top, t[i], t[i-1]));
                triangles.push_back(new Triangle(bottom, b[i], b[i-1]));
                triangles.push_back(new Triangle(b[i-1], t[i], t[i-1]));
                triangles.push_back(new Triangle(b[i-1], t[i], b[i]));
            }
        }

        segments.push_back(new Segment(t[0], t[4]));
        segments.push_back(new Segment(t[0], b[4]));
        segments.push_back(new Segment(b[0], b[4]));
        triangles.push_back(new Triangle(top, t[0], t[4]));
        triangles.push_back(new Triangle(bottom, b[0], b[4]));
        triangles.push_back(new Triangle(b[4], t[0], t[4]));
        triangles.push_back(new Triangle(b[4], t[0], b[0]));

        this->Divide(3);
    }

    Planet::~Planet() {
        delete center;
        while (! triangles.empty()) {
            delete triangles.back();
            triangles.pop_back();
        }
        while (! segments.empty()) {
            delete segments.back();
            segments.pop_back();
        }
        while (! points.empty()) {
            delete points.back();
            points.pop_back();
        }
    }

    void Planet::Draw(DRAW_STYLE style) {
        // Draw points
        /*
        glBegin(GL_POINTS);
        glColor3ub(255,0,0);
        for (vector<Point*>::iterator it=points.begin(); it!=points.end(); ++it) {
            (*it)->Draw();
        }
        glEnd();
        */

        // Draw lines
        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        for (vector<Segment*>::iterator it=segments.begin(); it!=segments.end(); ++it) {
            (*it)->Draw();
        }
        glEnd();

        // Draw triangles
        /*
        glBegin(GL_TRIANGLES);
        for (vector<Triangle*>::iterator it=triangles.begin(); it!=triangles.end(); ++it) {
            (*it)->Draw();
        }
        glEnd();
        */
    }

    void Planet::Divide() {
        vector<Triangle*>::size_type ntriangles = triangles.size();
        vector<Segment*>::size_type nsegments = segments.size();
        for (vector<Triangle*>::size_type i=0 ; i<ntriangles ; i++) {
            triangles[i]->Divide(this);
        }

        segments.erase(segments.begin(), segments.begin() + nsegments);
        triangles.erase(triangles.begin(), triangles.begin() + ntriangles);
    }

    void Planet::Divide(int n) {
        for (int i=0 ; i<n ; i++) {
            this->Divide();
        }
    }

    void Planet::AddPoint(Point* p) {
        points.push_back(p);
    }

    void Planet::AddSegment(Segment* s) {
        segments.push_back(s);
    }

    void Planet::AddTriangle(Triangle* t) {
        triangles.push_back(t);
    }
}
