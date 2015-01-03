/*
 * GCam.h
 * Copyright (C) 2014 Florian Leprince <floleprince@gmail.com>
 *
 * Distributed under terms of the GNU GPL V2 license.
 */

#ifndef __GCAM_H__
#define __GCAM_H__

#include <SDL/SDL.h>

namespace Gaia {
    class GCam {
        public:
            GCam();
            ~GCam();

            void Look();
            void OnMouseMotion(const SDL_MouseMotionEvent & event);
            void OnMouseButton(const SDL_MouseButtonEvent & event);
            //void OnKeyboard(const SDL_MouseMotionEvent & event);

            //void SetMotionSens(double sensitivity);
            //void SetScrollSens(double sensitivity);

        private:
            double motionSens;
            double scrollSens;
            bool moving;
            double distance;
            double phi, psi;
    };
}

#endif /* __GCAM_H__ */
