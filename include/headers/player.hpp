#pragma once
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL/SDL.h>
#include <vector>
#include "bullet.hpp"
#include "asteroid.hpp"

using namespace std;

class Player{

    public:
        Player(int x, int y);

        void updatePlayer(SDL_Renderer *renderer, SDL_Texture *txr);
        void updateDirectionX(int ndirX);
        void updateDirectionY(int ndirY);
        void handleKeyboard();

        SDL_Texture* playerTexture(SDL_Renderer *renderer);

        vector<Bullet> getBullets();
        vector<Asteroid> getAsteroids();
        int getPosX();
        int getPosY();

        void setAD();
        void setHP();

        int attackDelay = 30;
        int asteroidDelay = 120;

    private:
        SDL_Surface *img;
        SDL_Texture *playerTx;
        SDL_Rect player;

        int dirX = 0;
        int dirY = 0;
        float speed = 5.0;

        int AD = 1;
        int HP = 3;

        vector<Bullet> bullets;
        vector<Asteroid> asteroids;
};

#endif