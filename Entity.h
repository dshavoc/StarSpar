#ifndef ENTITY_H
#define ENTITY_H

#include "LOpenGL.h"
#include <cmath>

class Entity
{
    public:
        Entity(float x, float y, float r);
        virtual ~Entity();

        float getRadius() { return radius; }
        void setRadius(float r) { radius = r; }
        float getX() { return posX; }
        float getY() { return posY; }

        bool collidesWith(Entity other);

        //virtual void draw(int timeNow) = 0;

    protected:
        float radius;
        float posX, posY;
};

#endif // ENTITY_H
