/*
 * main.cpp
 * Copyright (C) 2014 Florian Leprince <floleprince@gmail.com>
 *
 * Distributed under terms of the GNU GPL V2 license.
 */

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <iostream>
#include "GCam.h"
#include "Planet.h"

// debug directives

using namespace std;
using namespace Gaia;

void Dessiner(Planet* planet);
void cleanexit();

GCam * gcam;
Planet* earth;

void cleanexit() {
    delete gcam;
    delete earth;
    SDL_Quit();
}

int main(int argc, char *argv[])
{
    atexit(cleanexit);
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    atexit(SDL_Quit);
    SDL_WM_SetCaption("GAIAp viewer", NULL);
    SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);

    gcam = new GCam();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70,(double)640/480,1,1000);
    glEnable(GL_DEPTH_TEST);

    earth = new Planet();
    cout << "earth contains " << earth->GetNPoints() << " points." << endl;

    Dessiner(earth);

    for (;;)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        exit(0);
                        break;
                    default:
                        break;
                }
                break;
            case SDL_MOUSEMOTION:
                gcam->OnMouseMotion(event.motion);
                break;
            case SDL_MOUSEBUTTONUP:
            case SDL_MOUSEBUTTONDOWN:
                gcam->OnMouseButton(event.button);
                break;
            default:
                break;
        }
        Dessiner(earth);
    }
    return 0;
}

void Dessiner(Planet* planet)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gcam->Look();

    /* Dessin 3D */
    planet->Draw(DRAW_POINT);

    glFlush();
    SDL_GL_SwapBuffers();
}
