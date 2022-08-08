#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "player.hpp"
#include "rendering.hpp"
#include "bullet.hpp"
#include "asteroid.hpp"

using namespace std;

int main(int argv, char** args){

    // Asteroid asteroids[20];

    SDL_Init(SDL_INIT_EVERYTHING);

    //Some frames stuff (https://www.youtube.com/watch?v=jzasDqPmtPI)
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    const Uint8* keystates = SDL_GetKeyboardState(NULL);

    //Init player
    Rendering rendering;
    Player player(225, 425);

    vector<Bullet> bl = player.getBullets();
    vector<Asteroid> as = player.getAsteroids();

    SDL_Renderer *renderer = rendering.getRenderer();
    SDL_Window *window = rendering.getWindow();
    SDL_Texture *playerTxr = player.playerTexture(renderer);

    //Generic asteroid object
    Asteroid ast;
    SDL_Texture *asteroidTxr = ast.asteroidTexture(renderer);

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

        if(player.asteroidDelay <= 0){
            Asteroid a;
            as.push_back(a);
            player.asteroidDelay = 120;
        }

        player.updatePlayer(renderer, playerTxr);

        for(int i = 0; i< bl.size(); i++){
            bl.at(i).updateBullet(renderer, bl);
        };

        for(int i = 0; i< as.size(); i++){
            as.at(i).updateAsteroid(renderer, asteroidTxr, as);
        };

        rendering.updateRenderer();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }

        player.attackDelay--;
        player.asteroidDelay--;
    }

    SDL_DestroyTexture(asteroidTxr);    
    rendering.destroyRendering(playerTxr);

    return 0;
}