#include "Projectile.h"
#include "Draw.h"

Projectile::Projectile(float x, float y, float r, float vx, float vy, int t, Style style)
: Entity(x, y, r, t)
{
    this->vx = vx;
    this->vy = vy;
    this->style = style;
    timeCreated = t;
    isFinishedFlag = false;
}

void Projectile::update(int timeNow, std::vector<Solar*> solars) {
    Entity::update(timeNow, 0.f, 0.f, 0.f, solars);

    //End of life
    if(timeNow - timeCreated > PROJECTILE_LIFESPAN_MS) {
        isFinishedFlag = true;
        printf("t1: %d, t2: %d, delta: %d, eol: %d \r\n", timeCreated, timeNow, timeNow-timeCreated, PROJECTILE_LIFESPAN_MS);
    }
}

void Projectile::draw(int timeNow) {
    unsigned int NUM_POINTS = 12;

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef(px, py, 0.f);

    glColor3f(1.f, .5f, 1.f);
    drawCircle(radius, NUM_POINTS);
}
