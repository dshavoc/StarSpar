#ifndef ENTITY_H
#define ENTITY_H

#include "LOpenGL.h"
#include <cmath>
#include <vector>
#include "Draw.h"

//#include "Solar.h"  //If this is included, then Entity.cpp can't cast 'this' to Solar*
class Solar;    //Forward declare so that void update(...Solar...) will be happy
                //If Solar.h is included, then the Solar class gets choked up including Entity.
                //I don't know why, since the #ifndef guard block is there.

                //Lesson learned:   When referring to child from parent, forward declare the
                //                  child class name from the parent header, then #include
                //                  the child's header in the parent's .cpp

/*
 * Entity is the parent class of all objects in the world that interact with
 * each other, such as planets, comets, ships, missiles. This class handles
 * common functions such as physics and collision detection.
 */
class Entity
{
    public:
        Entity();
        Entity(float x, float y, float r, int timeNow);
        virtual ~Entity();

        float getRadius() { return radius; }
        void setRadius(float r) { radius = r; }
        float getX() { return px; }
        float getY() { return py; }

        bool collidesWith(Entity *other);

        virtual void draw(int timeNow) = 0;
        void update(int timeNow, float accel, float accelAngle, float angularAccel, std::vector<Solar*> solars);

        bool isFinished() {return isFinishedFlag;}
        void markFinished() {isFinishedFlag = true;}

        float DEG_TO_RAD = 3.14159/180;

    protected:
        float radius;
        float px, py,   theta;      //position in relative world units, facing angle in degrees
        float vx, vy,   omega;      //velocity, angular velocity

        int timeLastUpdate;
        bool isFinishedFlag;
};

#endif // ENTITY_H
