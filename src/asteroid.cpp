#include "asteroid.hpp"
#include <time.h>
#include <random>

Asteroid::Asteroid(){
    srand(time(0));

    dirX = ( (rand() % 500) + 1 )/100;
    dirY = ( (rand() % 1000) + 1)/100;

    if(rand()%2 == 0){
        dirX *= -1;
    }

    speed = (rand() % 2 ) + 1;

    asteroid.x = ( rand()%500 );
    asteroid.y = 0;
    asteroid.w = 32;
    asteroid.h = 32;
}

void Asteroid::updateAsteroid(SDL_Renderer *renderer, SDL_Texture *txr){
    asteroid.x += dirX * speed;
    asteroid.y += dirY * speed;

    SDL_RenderCopy(renderer, txr, NULL, &asteroid);
}

SDL_Texture* Asteroid::asteroidTexture(SDL_Renderer *renderer){
    img = IMG_Load("./res/asteroid.png");
    asteroidTx = SDL_CreateTextureFromSurface(renderer, img);
    SDL_FreeSurface(img);

    return asteroidTx;
}