#include "asteroid.hpp"
#include <time.h>
#include <random>
#include <vector>
#include <iostream>

using namespace std;

Asteroid::Asteroid(){
    srand(time(0));

    dirX = ( (rand() % 500) + 1 )/100;
    dirY = ( (rand() % 1000) + 1)/100;

    if(rand()%2 == 0){
        dirX *= -1;
    }

    speed = (rand() % 2 ) + 1;

    int randNum = rand()%(64-32 + 1) + 32; //generate random number btw 16 and 42
    asteroid.x = ( rand()%500 );
    asteroid.y = -25;
    asteroid.w = randNum;
    asteroid.h = randNum;
}

Asteroid::~Asteroid(){ };

void Asteroid::updateAsteroid(SDL_Renderer *renderer, SDL_Texture *txr, vector<Asteroid> ast){
    angle+=5;
    asteroid.x += dirX * speed;
    asteroid.y += dirY * speed;

    //CHANGER AST.ERASE PSK CA FONCTIONNE PAS TJRS

    if(asteroid.x <= 0-asteroid.w){
        ast.erase(ast.begin());
        this->~Asteroid();
    }
    else if(asteroid.x >= 475 + asteroid.w){
        ast.erase(ast.begin());
        this->~Asteroid();
    }

    if(asteroid.y >= 475 + asteroid.h){
        ast.erase(ast.begin());
        this->~Asteroid();
    }

    if(angle >= 360){
        angle = 0;
    }

    SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
    // SDL_RenderCopy(renderer, txr, NULL, &asteroid);
    SDL_RenderCopyEx(renderer, txr, NULL, &asteroid, angle, NULL, flip);
}

SDL_Texture* Asteroid::asteroidTexture(SDL_Renderer *renderer){
    img = IMG_Load("./res/asteroid.png");
    asteroidTx = SDL_CreateTextureFromSurface(renderer, img);
    SDL_FreeSurface(img);

    return asteroidTx;
}