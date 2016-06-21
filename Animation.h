#ifndef ANIMATION_H
#define ANIMATION_H

#include "LOpenGL.h"

enum AnimState {OFF, STARTING, ON, STOPPING};

class Animation
{
    public:
        Animation();
        Animation(float posX, float posY, int timeNow, int transitionTime);
        virtual void draw(int timeNow) = 0;

        void start(int timeNow);
        void stop(int timeNow);

    protected:
        AnimState animState;
        int timeLastChangeMs;
        int transitionTime;
        float posX, posY;

        float lerp(float a, float b, float t) {return (b - a) * t + a;}
};

#endif // ANIMATION_H
