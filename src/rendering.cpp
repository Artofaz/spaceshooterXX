#include <rendering.hpp>
#include <SDL.h>
#include <SDL_image.h>

Rendering::Rendering(){

    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("SDL SPACSHOOTER V1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1,  0); //SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC

    SDL_Surface *icon = IMG_Load("./res/spaceship.png");

    SDL_SetWindowIcon(window, icon);

    SDL_FreeSurface(icon);
}

void Rendering::updateEvents(){
    while(SDL_PollEvent(&event) != 0){

            switch(event.type){

                case SDL_QUIT:
                    running = false;
                    break;
                default:
                    break;
            }
        }
}

void Rendering::clearRenderer(){
    SDL_SetRenderDrawColor(renderer, 36, 5, 73, 255);
    SDL_RenderClear(renderer);
}

void Rendering::updateRenderer(){
    SDL_RenderPresent(renderer);
}

void Rendering::destroyRendering(SDL_Texture *txr){
    SDL_DestroyTexture(txr);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Renderer* Rendering::getRenderer(){
    return renderer;
}

SDL_Window* Rendering::getWindow(){
    return window;
}