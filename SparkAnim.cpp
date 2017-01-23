#include "SparkAnim.h"
#include "MyMath.h"

SparkAnim::SparkAnim(float x, float y, float magnitude, int timeNow)
: Animation(x, y, timeNow, 0)
{
    //magnitude pertains to both speed and radius (range at which spark dies out)
    this->radius = magnitude;
    float speed = randFloatBetween(10.f, 30.f) * (1 + magnitude/3);
    float angle = randFloatBetween(0, 2*PI);
    vx = speed * cos(angle);
    vy = speed * sin(angle);
    headX = x;
    headY = y;
}

SparkAnim::~SparkAnim()
{
    //dtor
}

void SparkAnim::draw(int timeNow) {
    //Head(x,y): Move out at full speed and color. When reach radius, continue motion but fade out.
    //Tail(0.5 x,y): Move out at half speed. Set to low saturation.

    float range;    //How far spark has traveled
    float alpha = 1.f;
    float dt = (timeNow - timeLastChangeMs)/1000.f;

    headX += vx * dt;
    headY += vy * dt;
    range = hypot(headX - posX, headY - posY);

    if(range > radius) {
        alpha = 1.f - (range - radius) / radius;
    }
    if(alpha > 0) {

        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity();

        glBegin(GL_LINE_STRIP);
            //Draw head
            glColor3f(alpha * 1.f, alpha * 1.f, alpha * 1.f);
            glVertex2f(headX, headY);
            //Draw tail
            glColor3f(0.2f * alpha * 1.f, 0.2f * alpha * 1.f, 0.2f * alpha * 1.f);
            glVertex2f(posX, posY);
        glEnd();

        timeLastChangeMs = timeNow;
        //printf("Head: (%6.2f, %6.2f), range: %6.2f, alpha: %6.2f\r\n", headX, headY, range, alpha);
    }
    else {
        isFinishedFlag = true;
    }
}
