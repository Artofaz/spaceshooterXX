#pragma once
#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SDL.h>
#include <SDL_image.h>

class Enemy{

    public:
        Enemy();

        void setAD();
        void setHP();
        void setDir();

        void attack();
        void updateEnemy(SDL_Renderer *renderer, SDL_Texture *txr);
        SDL_Texture* enemyTexture(SDL_Renderer *renderer, const char *file);

    private:

        SDL_Surface *img;
        SDL_Texture *enemyTx;
        SDL_Rect enemy;

        int speed;

        int dirX;
        int dirY;

        int HP; // health points
        int AD; //attack damage
};

#endif