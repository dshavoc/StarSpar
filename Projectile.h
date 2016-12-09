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
    private:
};

#endif // PROJECTILE_H
