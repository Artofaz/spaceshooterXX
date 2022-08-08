#ifndef BULLET_HPP
#define BULLET_HPP

#include <SDL.h>
#include <vector>

using namespace std;

class Bullet{

    public:
        Bullet(int px, int py);
        ~Bullet();
        void updateBullet(SDL_Renderer *renderer, vector<Bullet> bl);

    private:
        SDL_Rect bullet;
};

#endif