#include "Entity.h"
#include "Solar.h"      //Including this here to avoid circular reference issues (can't detect getX(), ... )

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

bool Entity::collidesWith(Entity *other) {
    float dist = hypot( other->getX() - getX(), other->getY() - getY() );
    bool cw = dist < (other->getRadius() + getRadius());
    if(cw) {
        printf("Collided at distance %f < %f + %f\r\n", dist, other->getRadius(), getRadius());
    }
    return  cw;
}

void Entity::printDistanceTo(Entity *other) {
    printf("  here to there: %f\r\n", hypot(other->getX() - getX(), other->getY() - getY()));
}

void Entity::update(int timeNow, float accel, float accelAngle, float angularAccel, std::vector<Solar*> solars) {
    float t_s = (float)(timeNow - timeLastUpdate) / 1000.f;
    float cosTheta = cos(accelAngle * DEG_TO_RAD);
    float sinTheta = sin(accelAngle * DEG_TO_RAD);
    float dx, dy, r;
    float a, ax = 0, ay = 0;

    //Add acceleration due to solar gravity sources
    if(!solars.empty()) {
        for(unsigned int i=0; i<solars.size(); i++) {
            if(this != solars[i]) {
                dx  = solars[i]->getX() - getX();
                dy  = solars[i]->getY() - getY();
                r   = hypot(dx, dy);
                a   = 1000.f * solars[i]->getGravity() / powf(r, 2);
                ax += a * dx / r;
                ay += a * dy / r;
            }
        }
    }

    //Add acceleration due to ship thrust
    ax += accel * cosTheta;
    ay += accel * sinTheta;

    //Update first derivatives
    vx += ax * t_s;
    vy += ay * t_s;
    omega += angularAccel * t_s;

    //Update position and angle
    px += vx * t_s;
    py += vy * t_s;
    theta += omega * t_s;

    timeLastUpdate = timeNow;

    //printf("Entity::Update velocity %f\r\n", hypot(vx, vy));
}
