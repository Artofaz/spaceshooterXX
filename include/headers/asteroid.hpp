#pragma once
#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

using namespace std;

class Asteroid{

    public:
        Asteroid();
        ~Asteroid();
        void updateAsteroid(SDL_Renderer *renderer, SDL_Texture *txr, vector<Asteroid> ast);
        SDL_Texture* asteroidTexture(SDL_Renderer *renderer);
        int spawnDelay;

    private:
        SDL_Surface *img;
        SDL_Texture *asteroidTx;
        SDL_Rect asteroid;

        int speed;
        int dirX;
        int dirY;

        int angle = 0;
};

#endif