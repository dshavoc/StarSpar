#include "Projectile.h"

Projectile::Projectile(float x, float y, float r, float vx, float vy, int t, Style style)
: Entity(x, y, r, t)
{
    this->vx = vx;
    this->vy = vy;
    this->style = style;
}

void Projectile::update(int timeNow, std::vector<Solar*> solars) {
    Entity::update(timeNow, 0.f, 0.f, 0.f, solars);
}

void Projectile::draw(int timeNow) {
    float r = radius;
    unsigned int NUM_POINTS = 12;

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef(px, py, 0.f);

    glBegin(GL_LINE_STRIP);
    glColor3f(1.f, 1.f, 1.f);
    for(unsigned int i=0; i<=NUM_POINTS; i++) {
        glVertex2f( r * cos((float)i*6.283/NUM_POINTS),
                    r * sin((float)i*6.283/NUM_POINTS));
    }
    glEnd();
}
