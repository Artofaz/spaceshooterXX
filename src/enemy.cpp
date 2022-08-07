#include "enemy.hpp"
#include <random>
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

Enemy::Enemy(){
    srand(time(0));

    enemy.x = rand() % 475;
    enemy.y = -25;
}

void Enemy::updateEnemy(SDL_Renderer *renderer, SDL_Texture *txr){
    SDL_RenderCopy(renderer, txr, NULL, &enemy);
}

SDL_Texture* Enemy::enemyTexture(SDL_Renderer *renderer, const char *file){
    img = IMG_Load(file);
    enemyTx = SDL_CreateTextureFromSurface(renderer, img);

    return enemyTx;
}
