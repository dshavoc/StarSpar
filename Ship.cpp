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
    float cosTheta = cos(theta * 3.1415926/180);
    float sinTheta = sin(theta * 3.1415926/180);

    //Update first derivatives
    vx += a * cosTheta * t_s;
    vy += a * sinTheta * t_s;
    omega += alpha * t_s;

    //Update position and angle
    px += vx * t_s;
    py += vy * t_s;
    theta += omega * t_s;

    timeLastUpdate = timeNow;
}
