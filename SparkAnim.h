#ifndef SPARKANIM_H
#define SPARKANIM_H

#include "Animation.h"

class SparkAnim : public Animation
{
    public:
        SparkAnim(float x, float y, float magnitude, int timeNow);
        virtual ~SparkAnim();

        void draw(int timeNow);
    protected:
        float vx, vy, radius;
        float headX, headY;
};

#endif // SPARKANIM_H
