#ifndef ENTITY_H
#define ENTITY_H

#include "LOpenGL.h"
#include <cmath>
#include "LOpenGL.h"

/*
 * Entity is the parent class of all objects in the world that interact with
 * each other, such as planets, comets, ships, missiles.
 */
class Entity
{
    public:
        Entity();
        Entity(float x, float y, float r);
        virtual ~Entity();

        float getRadius() { return radius; }
        void setRadius(float r) { radius = r; }
        float getX() { return px; }
        float getY() { return py; }

        bool collidesWith(Entity &other);

        virtual void draw(int timeNow) = 0;
        void update(int timeNow);

    protected:
        float radius;
        float px, py,     theta;      //position in relative world units, angle in degrees
        float velocity,   omega;

        int timeLastUpdate;
};

#endif // ENTITY_H
