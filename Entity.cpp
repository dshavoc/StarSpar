#include "Entity.h"

Entity::Entity(float x, float y, float r)
{
    posX = x;
    posY = y;
    radius = r;
}

Entity::~Entity()
{
    //dtor
}

bool Entity::collidesWith(Entity other) {
    return hypot( other.getX() - getX(), other.getY() - getY() ) < (other.getRadius() + getRadius());
}
