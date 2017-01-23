#ifndef GAME_H
#define GAME_H

#include "LOpenGL.h"
#include "LUtil.h"
#include "animations.h"
#include "Ship.h"
#include "Projectile.h"
#include "Solar.h"
#include "Draw.h"

using namespace std;

/*class Game
{
    public:
        Game();
        virtual ~Game();
    protected:
    private:
};*/

//Perform per-frame logic
void update(int timeNowMs);

//Perform per-frame rendering
void render();

void initGamespace();

void addProjectile(Projectile*);        //A pointer to this function will be passed to all ships as a way for them
                                        //to add projectiles to the world without any other read/write ability.

void createExplosion(float x, float y, float magnitude, int timeNow);

#endif // GAME_H
