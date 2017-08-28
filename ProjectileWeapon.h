#ifndef PROJECTILEWEAPON_H
#define PROJECTILEWEAPON_H

#include "Weapon.h"
#include "Projectile.h"
#include <string>

struct FiringProfile {
    int timeToChargeMs;
    int shotsPerCharge;
};

class ProjectileWeapon: public Weapon       //The error below is resolved if the inheritance is cut...
{
    public:
        ProjectileWeapon(std::string weapName, void (*addProjectileHandle)(Projectile*) );
        virtual ~ProjectileWeapon();

        void fire(float x, float y, float shipR, float vx, float vy, float theta, int timeNow);

    protected:
        Projectile *p;	// error: 'Projectile' does not name a type
    private:
        void (*addProjectile)(Projectile*);
};

#endif // PROJECTILEWEAPON_H
