#ifndef LIGHTNINGANIM_H
#define LIGHTNINGANIM_H

#include <cstdlib>
#include "Animation.h"


class LightningAnim : public Animation {
public:
    LightningAnim(float startX, float startY, float endX, float endY, int startTime, int timeDuration);
    void setStart(float x, float y) {posX=x; posY=y;}
    void setEnd(float x, float y) {targetX=x; targetY=y;}
    void draw(int timeNow);

private:
    float targetX, targetY;
};


#endif
