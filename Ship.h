#ifndef SHIP_H
#define SHIP_H

#include "Entity.h"
#include "ThrusterAnim.h"
#include "ProjectileWeapon.h"

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
        bool takeDamage();

        //Public Actions
        void thrustForward(bool en);
        void thrustLeft(bool en);
        void thrustRight(bool en);
        void fire(int);
        float getRadius();                          //Overloaded from Entity to account for shield radius

        void setControlsForPlayer(int index);


    protected:

        //ENGINES
        bool isThrustForward, isThrustLeft, isThrustRight;
        ThrusterAnim *thrusterAnim;
        ThrusterAnim *thrusterAnim2;
        ThrusterAnim *thrusterAnimL;
        ThrusterAnim *thrusterAnimR;

        float getForwardAccel() {return 50.f;}      //Placeholder that will eventually call engine.accel()
        float getAngularAccel() {return 400.f;}     //Placeholder that will eventually call thrusters.accel()


        //DEFENSE
        int hitPoints, maxHitPoints;
        float shields, maxShields, shieldChargeRate = 0.2f;


        //WEAPONS
        ProjectileWeapon * weapon;
        void (*addProjectile)(Projectile*);


        //CONTROL INPUT
        ControlKeys *controlKeys;
        ControlKeys player1controls = {'a', 'd', 'w', 'e'};
        ControlKeys player2controls = {'k', ';', 'o', 'p'};
};


#endif // SHIP_H
