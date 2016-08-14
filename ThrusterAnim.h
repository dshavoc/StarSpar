#ifndef THRUSTERANIM_H
#define THRUSTERANIM_H

#include "Animation.h"


class ThrusterAnim : public Animation
{
    public:
        ThrusterAnim(float angle, float xOffset, float yOffset, float flameLength);
        ~ThrusterAnim();
        void draw(int timeNow);
    private:
        float flameLength;
        float angle;
};

#endif // THRUSTERANIM_H
