#pragma once
#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <SDL.h>
#include <SDL_image.h>

class Asteroid{

    public:
        Asteroid();
        void updateAsteroid(SDL_Renderer *renderer, SDL_Texture *txr);
        SDL_Texture* asteroidTexture(SDL_Renderer *renderer);

    private:
        SDL_Surface *img;
        SDL_Texture *asteroidTx;
        SDL_Rect asteroid;

        int speed;
        int dirX;
        int dirY;

};

#endif