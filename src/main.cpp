#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "player.hpp"
#include "rendering.hpp"
#include "bullet.hpp"
#include "asteroid.hpp"

using namespace std;

int main(int argv, char** args){

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

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
    TTF_Font * font = TTF_OpenFont("./res/pcsenior.ttf", 10);

    //Generic asteroid object
    Asteroid ast;
    SDL_Texture *asteroidTxr = ast.asteroidTexture(renderer);

    SDL_Color color = { 255, 255, 255 };
    SDL_Surface * surface = TTF_RenderText_Solid(font,
    "Score:", color);
    SDL_Rect ds;ds.w=100;ds.h=20;ds.x=5;ds.y=5;

    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);

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

        SDL_RenderCopy(renderer, texture, NULL, &ds);
        rendering.updateRenderer();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }

        player.attackDelay--;
        player.asteroidDelay--;
    }

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyTexture(asteroidTxr);  
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);  
    rendering.destroyRendering(playerTxr);

    return 0;
}