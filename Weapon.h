#ifndef WEAPON_H
#define WEAPON_H

#include "Module.h"
//#include "Ship.h"

/*
Weapon is what links the ship to the instance of a payload (projectile, beam, ...) in the world.
It must contain all information and interfaces
to be mountable on a ship, and must hook into the Game to inject an instance of
its payload that contains the DamageProfile information (link or copy) of the weapon.
*/


struct DamageProfile {
    float baseDamage;
    float hullMod;
    float shieldMod;
    float shieldPierce;         //How much shield is ignored before damage is applied to shield instead of hull
};

//enum DamageType { KINETIC, LASER, ION, PLASMA};         //Just a thought
//enum WeaponType { PROJECTILE, BEAM, MISSILE };          //Just a thought. Alternative to child classes


class Weapon : public Module
{
    public:
        Weapon();
        virtual ~Weapon();

        virtual void fire(float srcX, float srcY, float srcR, float srcVx, float srcVy, float theta, int timeNow);

    protected:
        DamageProfile damageProfile = {0.f, 0.f, 0.f, 0.f};
    private:
};


#endif // WEAPON_H
