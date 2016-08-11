#include "ThrusterAnim.h"

#define FLAME_BASE_COLOR    0.f, 0.f, 0.8f
#define FLAME_BOWL_COLOR    1.f, 0.9f, 0.3f
#define FLAME_TIP_COLOR     0.6f, 0.3, 0.3f


ThrusterAnim::ThrusterAnim(float angle, float xOffset, float yOffset, float flameLength)
: Animation(xOffset, yOffset, 0.f, 200)
{
    this->angle = angle;
    this->flameLength = flameLength;
}

/*  The jet will have a source at point 1, bowl out at points 2 and 4, then hit a random point 3,
    all scaled by flameLength:
        1
    4       2


       333
       333
       333
*/
void ThrusterAnim::draw(int timeNow) {

    float t = (float)(timeNow - timeLastChangeMs)/(float)transitionTime;
    float scale = flameLength;
    //printf("ThrusterAnim::draw, t=%f\r\n", t);

    updateAnimState(timeNow);
    switch(animState) {
        case STARTING:
            scale = lerp(0.f, flameLength, t);
            printf("starting, t=%f\r\n", t);
            break;
        case STOPPING:
            scale = lerp(flameLength, 0.f, t);
            printf("stopping, t=%f\r\n", t);
            break;
        case ON:
            scale = flameLength;
        default:
            scale = flameLength;
    }

    if(animState != OFF) {

        glMatrixMode( GL_MODELVIEW );
        glPushMatrix();
        glTranslatef(posX, posY, 0.f);
        glRotatef(angle, 0.f, 0.f, 1.f);


        float flameTipX = (float)(rand() % 200 - 100)/100.f * 0.1f * scale;
        float flameTipY = (float)(rand() % 200 - 100)/100.f * 0.2f * scale + scale;

        glBegin(GL_LINE_STRIP);
            glColor3f(FLAME_BASE_COLOR);        //Root point 1
            glVertex2f(0.f, 0.f);

            glColor3f(FLAME_BOWL_COLOR);        //Bowl point 2
            glVertex2f(0.2f * scale, 0.2f * scale);

            glColor3f(FLAME_TIP_COLOR);
            glVertex2f(flameTipX, flameTipY);

            glColor3f(FLAME_BOWL_COLOR);        //Bowl point 4
            glVertex2f(-0.2f * scale, 0.2f * scale);

            glColor3f(FLAME_BASE_COLOR);        //Root point 1
            glVertex2f(0.f, 0.f);

        glEnd();
    }
    glPopMatrix();
}
