#include "Entity.h"

Entity::Entity() : Entity(0, 0, 0) {}

Entity::Entity(float x, float y, float r)
{
    px = x;
    py = y;
    velocity = 0.f;
    theta = 0.f;
    omega = 0.f;

    radius = r;
    timeLastUpdate = 0;
}

Entity::~Entity()
{
    //dtor
}

bool Entity::collidesWith(Entity &other) {
    return hypot( other.getX() - getX(), other.getY() - getY() ) < (other.getRadius() + getRadius());
}

