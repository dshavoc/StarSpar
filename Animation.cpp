#include "Animation.h"

Animation::Animation()
{
    animState = OFF;
    timeLastChangeMs = 0;
    transitionTime = 0;
    posX = 0.;
    posY = 0.;
}

Animation::Animation(float posX, float posY, int timeNow, int transitionTime) {
    animState = OFF;
    this->posX = posX;
    this->posY = posY;
    timeLastChangeMs = timeNow;
    this->transitionTime = transitionTime;
}

void Animation::start() {
    if(transitionTime <= 0) {
        animState = ON;
    }
    else {
        animState = STARTING;
    }
    timeLastChangeMs = glutGet(GLUT_ELAPSED_TIME);
}

void Animation::stop() {
    if(transitionTime <= 0) {
        animState = OFF;
    }
    else {
        animState = STOPPING;
    }
    timeLastChangeMs = glutGet(GLUT_ELAPSED_TIME);
}

void Animation::updateAnimState(int timeNow) {
    switch(animState) {
    case STARTING:
        if(timeNow - timeLastChangeMs >= transitionTime) {
            animState = ON;
            printf("STARTING -> ON\r\n");
        }
        break;
    case STOPPING:
        if(timeNow - timeLastChangeMs >= transitionTime) {
            animState = OFF;
            printf("STOPPING -> OFF\r\n");
        }
    }
}
