#ifndef SHOCKWAVEANIM_H
#define SHOCKWAVEANIM_H

#include "Animation.h"


class ShockwaveAnim : public Animation
{
    public:
        ShockwaveAnim(float x, float y, float magnitude, int timeNow);
        virtual ~ShockwaveAnim();

        void draw(int timeNow);

    protected:
        float magnitude;
};

#endif // SHOCKWAVEANIM_H
