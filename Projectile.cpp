#include "Projectile.h"
#include "Draw.h"

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
    unsigned int NUM_POINTS = 12;

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef(px, py, 0.f);

    glColor3f(1.f, .5f, 1.f);
    drawCircle(radius, NUM_POINTS);
}
