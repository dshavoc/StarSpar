#include "Entity.h"

Entity::Entity() : Entity(0, 0, 0) {}

Entity::Entity(float x, float y, float r)
{
    px = x;
    py = y;
    radius = r;
    vx = vy = theta = omega = 0.f;
    timeLastUpdate = 0;
}

Entity::~Entity()
{
    //dtor
}

bool Entity::collidesWith(Entity &other) {
    return hypot( other.getX() - getX(), other.getY() - getY() ) < (other.getRadius() + getRadius());
}

