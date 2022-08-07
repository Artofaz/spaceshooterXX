#include <iostream>
#include <SDL/SDL.h>
#include "player.hpp"
#include "rendering.hpp"
#include "bullet.hpp"
#include "asteroid.hpp"

using namespace std;

int main(int argv, char** args){


    SDL_Init(SDL_INIT_EVERYTHING);

    //Some frames stuff (https://www.youtube.com/watch?v=jzasDqPmtPI)
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    Uint32 framePrevious;
    int frameTime;

    const Uint8* keystates = SDL_GetKeyboardState(NULL);

    //Init player
    Rendering rendering;
    Player player(225, 425);
    Asteroid asteroid;

    vector<Bullet> bl = player.getBullets();

    SDL_Renderer *renderer = rendering.getRenderer();
    SDL_Window *window = rendering.getWindow();
    SDL_Texture *playerTxr = player.playerTexture(renderer);
    SDL_Texture *asteroidTxr = asteroid.asteroidTexture(renderer);

    while(rendering.running){

        rendering.clearRenderer();

        frameStart = SDL_GetTicks();

        rendering.updateEvents();

        player.handleKeyboard();

        if(keystates[SDL_SCANCODE_SPACE] && player.attackDelay <= 0){
            Bullet b(player.getPosX(), player.getPosY());
            bl.push_back(b);
            player.attackDelay = 25;
        }

        // asteroid.updateAsteroid(renderer, asteroidTxr);
        player.updatePlayer(renderer, playerTxr);

        for(int i = 0; i< bl.size(); i++){
            bl.at(i).updateBullet(renderer, bl);
        };


        rendering.updateRenderer();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }

        player.attackDelay--;

    }

    rendering.destroyRendering(playerTxr, asteroidTxr);

    return 0;
}