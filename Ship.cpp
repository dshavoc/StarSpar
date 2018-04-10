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

    hitPoints = 5;
    shields = 5;
    maxShields = 5;

    setControlsForPlayer(1);

    //Temporary
    weapon = new ProjectileWeapon(std::string("Cannon"), addProjectile);
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
    glLoadIdentity();
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

    //Draw weapons and shields
    float shieldP = shields/maxShields;
    glColor3f(shieldP*.8f, shieldP*.8f, shieldP);
    //drawHexGrid(20, 5);
    //drawCircle(12.f);
    drawOval(12.f, 10.f);
}

void Ship::update(bool keys[], int timeNow, std::vector<Solar*> solars) {

    //Update shields
    shields += shieldChargeRate * (timeNow - timeLastUpdate) / 1000.f;
    if(shields > maxShields) shields = maxShields;
    printf("shields: %f\r\n", shields);

    // Update ship position
    thrustLeft(keys[(int)controlKeys->thrustLeft]);
    thrustRight(keys[(int)controlKeys->thrustRight]);
    thrustForward(keys[(int)controlKeys->thrustForward]);

    float accel = isThrustForward ? getForwardAccel() : 0;
    float angularAccel = ( (isThrustLeft ? -1.f : 0) + (isThrustRight ? 1.f : 0) ) * getAngularAccel();

    Entity::update(timeNow, accel, theta, angularAccel, solars);

    //Spawn any new Entities after updating ship position

    weapon->update(px, py, getRadius(), vx, vy, theta, timeNow);

    if(keys[(int)controlKeys->fire]) fire(timeNow);

}

float Ship::getRadius() {
    return radius + (shields >= 1.f ? 5.f : 0.f);
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

void Ship::fire(int timeNow) {
    weapon->fire(timeNow);
}

//Take damage and return whether it was lethal
bool Ship::takeDamage() {
    bool isDead = false;

    if(shields >= 1) {
        shields -= 1;
    }
    else {
        hitPoints -= 1;
    }

    if(hitPoints <= 0) {
        isDead = true;
    }

    return isDead;
}

void Ship::setControlsForPlayer(int index) {
    if(index == 2)
        controlKeys = &player2controls;
    else
        controlKeys = &player1controls;
}
