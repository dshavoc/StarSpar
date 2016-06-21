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
    this->posX = posX;
    this->posY = posY;
    timeLastChangeMs = timeNow;
    this->transitionTime = transitionTime;
}

void Animation::start(int timeNow) {
    if(transitionTime <= 0) {
        animState = ON;
    }
    else {
        animState = STARTING;
    }
    timeLastChangeMs = timeNow;
}

void Animation::stop(int timeNow) {
    if(transitionTime <= 0) {
        animState = OFF;
    }
    else {
        animState = STOPPING;
    }
    timeLastChangeMs = timeNow;
}
