#include "Entity.h"

Entity::Entity() : Entity(0, 0, 0, 0) {}

Entity::Entity(float x, float y, float r, int timeNow)
{
    px = x;
    py = y;
    radius = r;
    vx = vy = theta = omega = 0.f;
    timeLastUpdate = timeNow;
}

Entity::~Entity()
{
    //dtor
}

bool Entity::collidesWith(Entity &other) {
    return hypot( other.getX() - getX(), other.getY() - getY() ) < (other.getRadius() + getRadius());
}

void Entity::update(int timeNow, float accel, float accelAngle, float angularAccel) {
    float t_s = (float)(timeNow - timeLastUpdate) / 1000.f;
    float cosTheta = cos(accelAngle * DEG_TO_RAD);
    float sinTheta = sin(accelAngle * DEG_TO_RAD);

    //Update first derivatives
    vx += accel * cosTheta * t_s;
    vy += accel * sinTheta * t_s;
    omega += angularAccel * t_s;

    //Update position and angle
    px += vx * t_s;
    py += vy * t_s;
    theta += omega * t_s;

    timeLastUpdate = timeNow;
}
