#include "Solar.h"

Solar::Solar(float x, float y, float r, float gravity) : Entity(x, y, r, 0)
{
    this->gravity = gravity;
}

Solar::~Solar()
{
    //dtor
}

void Solar::update(int timeNow, std::vector<Solar*> solars) {
    Entity::update(timeNow, 0.f, 0.f, 0.f, solars);
}

void Solar::draw(int timeNow) {
    unsigned int NUM_POINTS = 36;

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef(px, py, 0.f);

    glBegin(GL_LINE_STRIP);
    glColor3f(1.f, 1.f, 0.2f);      //Light yellow
    for(unsigned int i=0; i<=NUM_POINTS; i++) {
        glVertex2f( radius * cos((float)i*6.283/NUM_POINTS),
                    radius * sin((float)i*6.283/NUM_POINTS));
    }
    glEnd();

    //Animate corona
}
