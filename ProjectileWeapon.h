#ifndef PROJECTILEWEAPON_H
#define PROJECTILEWEAPON_H

#include "Weapon.h"
#include "Projectile.h"
#include <string>

struct FiringProfile {
    int timeToChargeMs;
    int shotsPerCharge;
    int timeBetweenShots;
};

class ProjectileWeapon: public Weapon       //The error below is resolved if the inheritance is cut...
{
    public:
        ProjectileWeapon(std::string weapName, void (*addProjectileHandle)(Projectile*) );
        virtual ~ProjectileWeapon();

        void fire(int timeNow);
        void update(float x, float y, float shipR, float vx, float vy, float theta, int timeNow);

    protected:
        Projectile *p;	// error: 'Projectile' does not name a type
    private:
        void (*addProjectile)(Projectile*);

        int timeLastFired = 0;      //Charge
        int timeLastShot = 0;       //Shot
        int numShotsFired = 0;      //In this charge

        bool isFiring = false;
        FiringProfile firingProfile = {
            .timeToChargeMs = 800,
            .shotsPerCharge = 3,
            .timeBetweenShots = 100
        };

        const float PROJECTILE_SPEED = 100;
        const float PROJECTILE_RADIUS = .80f;
};

#endif // PROJECTILEWEAPON_H
