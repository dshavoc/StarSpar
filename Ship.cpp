#include "Ship.h"

Ship::Ship(float x, float y, float r, int t, void (*addProjectileHandle)(Projectile*)) : Entity(x, y, r, t) {
    timeLastUpdate = glutGet(GLUT_ELAPSED_TIME);
    thrusterAnim = new ThrusterAnim(90.f, -r, -r, 10.f);
    thrusterAnim2 = new ThrusterAnim(90.f, -r, r, 10.f);
    thrusterAnimL = new ThrusterAnim(0.f, 1.1f * r, 0.6 * r, 4.f);
    thrusterAnimR = new ThrusterAnim(180.f, 1.1f * r, -0.6 * r, 4.f);
    isThrustForward = false;
    isThrustLeft = false;
    isThrustRight = false;
    addProjectile = addProjectileHandle;
}

Ship::~Ship()
{
    delete thrusterAnim;
    delete thrusterAnim2;
    delete thrusterAnimL;
    delete thrusterAnimR;
}

void Ship::draw(int timeNow) {

    glMatrixMode( GL_MODELVIEW );
    glTranslatef(px, py, 0.f);
    glRotatef(theta, 0.f, 0.f, 1.f);

    glBegin(GL_LINE_STRIP);
        glColor3f(0.9, 0.9, 0.9);
        glVertex2f(10.f, 0.f);
        glVertex2f(-5.f, 6.f);
        glVertex2f(-5.f, -6.f);
        glVertex2f(10.f, 0.f);
    glEnd();

    thrusterAnim->draw(timeNow);
    thrusterAnim2->draw(timeNow);
    thrusterAnimL->draw(timeNow);
    thrusterAnimR->draw(timeNow);
}

void Ship::update(int timeNow) {
    float accel = isThrustForward ? getForwardAccel() : 0;
    float angularAccel = ( (isThrustLeft ? -1.f : 0) + (isThrustRight ? 1.f : 0) ) * getAngularAccel();

    Entity::update(timeNow, accel, theta, angularAccel);
}

void Ship::thrustForward(bool en) {
    if(en && !isThrustForward) {
        thrusterAnim->start();
        thrusterAnim2->start();
    }
    else if(!en && isThrustForward) {
        thrusterAnim->stop();
        thrusterAnim2->stop();
    }
    isThrustForward = en;
}

void Ship::thrustLeft(bool en) {
    if(en && !isThrustLeft) {
        thrusterAnimL->start();
    }
    else if(!en && isThrustLeft) {
        thrusterAnimL->stop();
    }
    isThrustLeft = en;
}

void Ship::thrustRight(bool en) {
    if(en && !isThrustRight) {
        thrusterAnimR->start();
    }
    else if(!en && isThrustRight) {
        thrusterAnimR->stop();
    }
    isThrustRight = en;
}

void Ship::fire() {
    float PROJECTILE_SPEED = 150;
    float projectileVx = PROJECTILE_SPEED * cos(theta * DEG_TO_RAD);
    float projectileVy = PROJECTILE_SPEED * sin(theta * DEG_TO_RAD);
    (*addProjectile)( new Projectile(
        px, py, 5.f,
        vx + projectileVx,
        vy + projectileVy,
        timeLastUpdate) );
}
