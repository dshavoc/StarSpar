#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Entity.h"

class Projectile : public Entity
{
    public:

        enum Style {SOLID, PLASMA} style;

        Projectile(float x, float y, float r, float vx, float vy, int timeNow, Style style = SOLID);
        void draw(int);
        void update(int, std::vector<Solar*> solars);
    protected:
        int timeCreated;

        const int PROJECTILE_LIFESPAN_MS = 10000;
    private:
};

#endif // PROJECTILE_H
