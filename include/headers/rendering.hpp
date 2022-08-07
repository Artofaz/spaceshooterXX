#pragma once
#ifndef RENDERING_HPP
#define RENDERING_HPP

#include <SDL.h>

class Rendering{

    public:
        Rendering();
        void clearRenderer();
        void updateEvents();
        void updateRenderer();
        void destroyRendering(SDL_Texture *txr, SDL_Surface *srf);
        SDL_Renderer* getRenderer();
        SDL_Window* getWindow();

        bool running = true;

    private:
        SDL_Renderer *renderer;
        SDL_Window *window;
        SDL_Event event;
};

#endif