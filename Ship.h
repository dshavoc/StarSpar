#ifndef SHIP_H
#define SHIP_H

#include "Entity.h"
#include "ThrusterAnim.h"
#include "Projectile.h"

struct ControlKeys {
    char thrustLeft;
    char thrustRight;
    char thrustForward;
    char fire;
};

class Ship : public Entity
{
    public:
        Ship(float x, float y, float r, int timeNow, void (*addProjectileHandle)(Projectile*));
        virtual ~Ship();

        //Administrative
        void draw(int);
        void update(bool keys[], int timeNow, std::vector<Solar*> solars);

        //Public Actions
        void thrustForward(bool en);
        void thrustLeft(bool en);
        void thrustRight(bool en);
        void fire(int);


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

        //Weapon variables that may be encapsulated in a Weapon class later
        int weapFirePeriod = 300;       //ms
        int weapTimeLastFired = 0;

        ControlKeys controlKeys = {'a', 'd', 'w', 'e'};
};


#endif // SHIP_H
