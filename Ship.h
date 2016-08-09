#ifndef SHIP_H
#define SHIP_H

#include "Entity.h"
#include "ThrusterAnim.h"

class Ship : public Entity
{
    public:
        Ship();
        Ship(float x, float y, float r);
        virtual ~Ship();
        void draw(int);
        void update(int);

        void thrustForward(bool en);
        void thrustLeft(bool en) {isThrustLeft = en;}
        void thrustRight(bool en) {isThrustRight = en;}
    protected:
        bool isThrustForward, isThrustLeft, isThrustRight;     //combinations of these may produce unique results

        int hitPoints;
        //hard points
        //maneuvering thrusters (angular acceleration)
        //main engine (forward acceleration)

        float getForwardAccel() {return 50.f;}  //Placeholder that will eventually call engine.accel()
        float getAngularAccel() {return 400.f;}   //Placeholder that will eventually call thrusters.accelDegrees()

        ThrusterAnim *thrusterAnim;
};

#endif // SHIP_H
