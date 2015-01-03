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
#include <iostream>
#include <math.h>
#include "Planet.h"

using namespace std;
namespace Gaia {
    Planet::Planet() {
        double originlat = atan(0.5) * 180 / M_PI;
        radius = 2; //6371000;
        center = new Point();
        cout << "Creating planet with " << radius/1000 << " km as radius." << endl;

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

    int Planet::GetNPoints() {
        return points.size();
    }

    void Planet::Draw(DRAW_STYLE style) {

        // Draw points
        glBegin(GL_POINTS);
        glColor3ub(255,0,0);
        for (vector<Point*>::iterator it=points.begin(); it!=points.end(); ++it) {
            (*it)->Draw();
        }
        glEnd();

        // Draw lines
        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        for (vector<Segment*>::iterator it=segments.begin(); it!=segments.end(); ++it) {
            (*it)->Draw();
        }
        glEnd();

        // Draw triangles
        glBegin(GL_TRIANGLES);
        for (vector<Triangle*>::iterator it=triangles.begin(); it!=triangles.end(); ++it) {
            (*it)->Draw();
        }
        glEnd();
    }

    void Planet::Divide() {
        for (vector<Triangle*>::iterator it=triangles.begin(); it!=triangles.end(); ++it) {
            Triangle* t = *it;

        }
    }
}
