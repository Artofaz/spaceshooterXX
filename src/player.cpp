#include <player.hpp>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "bullet.hpp"


using namespace std;

const Uint8* keystates = SDL_GetKeyboardState(NULL);

SDL_Scancode ku = SDL_SCANCODE_UP;
SDL_Scancode kd = SDL_SCANCODE_DOWN;
SDL_Scancode kr = SDL_SCANCODE_RIGHT;
SDL_Scancode kl = SDL_SCANCODE_LEFT;

Player::Player(int x, int y){
    player.x = x;
    player.y = y;
    player.h = 25;
    player.w = 25;
}

void Player::updatePlayer(SDL_Renderer *renderer, SDL_Texture *txr){
    player.x += dirX * speed;
    player.y += dirY * speed;

    if(player.x <= 0){
        player.x = 0;
    }
    else if(player.x >= 475){
        player.x = 475;
    }

    if(player.y <= 0){
        player.y = 0;
    }
    else if(player.y >= 475){
        player.y = 475;
    }

    SDL_RenderCopy(renderer, txr, NULL, &player);
}

void Player::handleKeyboard(){

    if(keystates[kr]){
        updateDirectionX(1);
        speed = 5.0;
    }
    else if(keystates[kl]){
        updateDirectionX(-1);
        speed = 5.0;
    }
    else {
        updateDirectionX(0);
        speed = 5.0;
    }

    if(keystates[ku]){
        updateDirectionY(-1);
        speed = 5.0;
    }
    else if(keystates[kd]){
        updateDirectionY(1);
    }
    else {
        updateDirectionY(0);
    }

    if(keystates[ku] && keystates[kr]){
        speed = 2.5;
    }
    else if(keystates[ku] && keystates[kl]){
        speed = 2.5;
    }
    else if(keystates[kd] && keystates[kr]){
        speed = 2.5;
    }
    else if(keystates[kd] && keystates[kl]){
        speed = 2.5;
    }
};

void Player::updateDirectionX(int ndirX){
    dirX = ndirX;
}

void Player::updateDirectionY(int ndirY){
    dirY = ndirY;
}

SDL_Texture* Player::playerTexture(SDL_Renderer *renderer){
    img = IMG_Load("./res/spaceship.png");
    playerTx = SDL_CreateTextureFromSurface(renderer, img);
    SDL_FreeSurface(img);

    return playerTx;
}

vector<Bullet> Player::getBullets(){
    return bullets;
}

vector<Asteroid> Player::getAsteroids(){
    return asteroids;
}

int Player::getPosX(){
    return player.x;
}

int Player::getPosY(){
    return player.y;
}