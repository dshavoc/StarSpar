#ifndef SHIP_H
#define SHIP_H

#include "Entity.h"
#include <vector>
#include "ThrusterAnim.h"
#include "Projectile.h"

class Ship : public Entity
{
    public:
        Ship(float x, float y, float r, int timeNow, void (*addProjectileHandle)(Projectile*));
        virtual ~Ship();

        //Administrative
        void draw(int);
        void update(int);

        //Public Actions
        void thrustForward(bool en);
        void thrustLeft(bool en);
        void thrustRight(bool en);
        void fire();


    protected:
        bool isThrustForward, isThrustLeft, isThrustRight;     //combinations of these may produce unique results

        int hitPoints;
        //hard points
        //maneuvering thrusters (angular acceleration)
        //main engine (forward acceleration)

        float getForwardAccel() {return 50.f;}  //Placeholder that will eventually call engine.accel()
        float getAngularAccel() {return 400.f;}   //Placeholder that will eventually call thrusters.accelDegrees()

        ThrusterAnim *thrusterAnim;
        ThrusterAnim *thrusterAnim2;
        ThrusterAnim *thrusterAnimL;
        ThrusterAnim *thrusterAnimR;

        void (*addProjectile)(Projectile*);
};

#endif // SHIP_H
