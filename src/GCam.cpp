/*
 * GCam.cpp
 * Copyright (C) 2014 Florian Leprince <floleprince@gmail.com>
 *
 * Distributed under terms of the GNU GPL V2 license.
 */

#include "GCam.h"
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>

namespace Gaia {
    GCam::GCam() {
        moving = false;
        distance = 5;
        phi = 0;
        psi = 0;
        motionSens = 0.3;
        scrollSens = 0.2;
    }

    GCam::~GCam() {
    }

    void GCam::OnMouseMotion(const SDL_MouseMotionEvent & event) {
        if (moving) {
            phi += event.xrel * motionSens;
            psi += event.yrel * motionSens;
            if (psi > 90)
                psi = 90;
            else if (psi < -90)
                psi = -90;
            phi = fmod(phi, 360.0);
        }
    }

    void GCam::OnMouseButton(const SDL_MouseButtonEvent & event) {
        if (event.button == SDL_BUTTON_LEFT) {
            if (moving && (event.type == SDL_MOUSEBUTTONUP)) {
                moving = false;
            } else if (!moving && (event.type == SDL_MOUSEBUTTONDOWN)) {
                moving = true;
            }
        } else if ((event.button == SDL_BUTTON_WHEELUP)
                && (event.type == SDL_MOUSEBUTTONDOWN)) {
            distance -= scrollSens;
            if (distance < 2)
                distance = 2;
        } else if ((event.button == SDL_BUTTON_WHEELDOWN)
                && (event.type == SDL_MOUSEBUTTONDOWN)) {
            distance += scrollSens;
        }
    }

    void GCam::Look() {
        gluLookAt(distance,0,0,
              0,0,0,
              0,0,1);
        glRotated(psi,0,1,0);
        glRotated(phi,0,0,1);
    }
}
