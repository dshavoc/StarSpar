#include "ProjectileWeapon.h"
#include "MyMath.h"


ProjectileWeapon::ProjectileWeapon(std::string weaponName, void (*addProjectileHandle)(Projectile*) )
{
    addProjectile = addProjectileHandle;
    name = weaponName;
}

ProjectileWeapon::~ProjectileWeapon()
{
    //dtor
}


void ProjectileWeapon::fire(float x, float y, float shipR, float vx, float vy, float theta, int timeNow) {

    float PROJECTILE_SPEED = 100;
    float PROJECTILE_RADIUS = 1.0f;
    float projectileVx = PROJECTILE_SPEED * cos(theta * DEG_TO_RAD);
    float projectileVy = PROJECTILE_SPEED * sin(theta * DEG_TO_RAD);

    (*addProjectile)( new Projectile(
        x + (shipR + PROJECTILE_RADIUS + 1) * (float)cos(theta * DEG_TO_RAD),
        y + (shipR + PROJECTILE_RADIUS + 1) * (float)sin(theta * DEG_TO_RAD),
        PROJECTILE_RADIUS,
        vx + projectileVx,
        vy + projectileVy,
        timeNow));
}
