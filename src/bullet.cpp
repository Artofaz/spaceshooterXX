#include "bullet.hpp"
#include <SDL.h>
#include <vector>

using namespace std;

Bullet::Bullet(int px, int py){
    bullet.x = px + 12;
    bullet.y = py;
    bullet.w = 3;
    bullet.h = 5;
}

// Bullet::~Bullet(){
    // delete &bullet;
// };

void Bullet::updateBullet(SDL_Renderer *renderer, vector<Bullet> bl){
    bullet.y -= 2;

    if(bullet.y <= 0){
        bl.erase(bl.begin());
    }

    SDL_SetRenderDrawColor(renderer, 255, 0, 155, 255);
    SDL_RenderFillRect(renderer, &bullet);
};