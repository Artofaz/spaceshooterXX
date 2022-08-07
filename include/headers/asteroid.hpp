#pragma once
#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <SDL.h>
#include <SDL_image.h>

class Asteroid{

    public:
        Asteroid();
        void updateAsteroid();

    private:
        SDL_Surface *img;
        SDL_Texture *asteroidTx;
        SDL_Rect asteroid;

        int speed;
        int dirX;
        int dirY;

};

#endif