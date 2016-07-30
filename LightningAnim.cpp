#include "LightningAnim.h"

const unsigned int NUM_SEGMENTS = 12;

LightningAnim::LightningAnim(float startX, float startY, float endX, float endY, int startTime, int timeDuration)
: Animation(startX, startY, startTime, timeDuration)
{
    targetX = endX;
    targetY = endY;

}

void LightningAnim::draw(int timeNow) {
    if(animState != ON)
        return;

    float t;    //temporal progress
    float a;    //spatial status

    t = ((timeNow - timeLastChangeMs) % 2000) / 2000.f;

    glBegin( GL_LINE_STRIP );
        glColor3f(.5f + 0.5*t, .2f, 1.f - 0.5*t);
        glVertex2f(posX, posY);         //First lightning point

        //Add lightning points in the middle
        for(unsigned int i = 1; i < NUM_SEGMENTS - 1; i++) {
            a = (float)(i) / (float)(NUM_SEGMENTS - 1);
            glVertex2f(
                lerp(posX, targetX, a) + (float)(rand() % 16 - 8),
                lerp(posY, targetY, a) + (float)(rand() % 16 - 8)
            );
        }

        glVertex2f(targetX, targetY);   //Last lightning point

    glEnd();
}
