#include "asteroid.hpp"
#include <time.h>
#include <random>

Asteroid::Asteroid(){
    srand(time(0));

    dirX = ( rand() % 1000 )/100;
    dirY = ( rand() % 1000 )/100;

    if(rand()%2 == 0){
        dirX *= -1;
    }

    speed = rand() % 8;

    asteroid.x = ( rand()%500 );
    asteroid.y = 0;
    asteroid.w = 32;
    asteroid.h = 32;
}

void Asteroid::updateAsteroid(){
    asteroid.x += dirX * speed;
    asteroid.y += dirY * speed;
}