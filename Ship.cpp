#include "Ship.h"

Ship::Ship()
{
    //ctor
}

Ship::Ship(float x, float y, float r) : Entity(x, y, r) {
    timeLastUpdate = glutGet(GLUT_ELAPSED_TIME);
}

Ship::~Ship()
{
    //dtor
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
}

void Ship::update(int timeNow) {
    float a = isThrustForward ? getForwardAccel() : 0;
    float alpha = ( (isThrustLeft ? -1.f : 0) + (isThrustRight ? 1.f : 0) ) * getAngularAccel();
    float t_s = (float)(timeNow - timeLastUpdate) / 1000.f;

    velocity += a * t_s;
    omega += alpha * t_s;

    theta += omega * t_s;
    px += velocity * cos(theta * 3.1415926/180) * t_s;
    py += velocity * sin(theta * 3.1415926/180) * t_s;

    timeLastUpdate = timeNow;
}
