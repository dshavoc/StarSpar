#include "ShockwaveAnim.h"
#include "Draw.h"
#include "MyMath.h"

ShockwaveAnim::ShockwaveAnim(float x, float y, float magnitude, int timeNow)
: Animation(x, y, timeNow, 0)
{
    this->magnitude = randFloatBetween(magnitude * 0.8, magnitude );
}

ShockwaveAnim::~ShockwaveAnim()
{
    //dtor
}

void ShockwaveAnim::draw(int timeNow) {

    float dt = (timeNow - timeLastChangeMs)/1000.f;
    float T_90_PCT = 1.f;       //time at which radius is at 90%. (100% is an asymptote)
    float k = 9 / T_90_PCT;  // 0.9 = 1 - 1/(kt+1)
    float p = (1 - 1/(dt * k + 1) );
    float radius = magnitude * p;

    float red, green, blue;
    if(p < 0.8f) {

        if(p < 0.4f) {
            red = 0.8f;
            green = 0.6f;
            blue = 1.0f;
        }
        else {
            red = lerp(0.6, 0.2, (p-0.4)/0.4f);
            green = lerp(0.6, 0.f, (p-0.4)/0.4f);
            blue = lerp(1.0, 0, (p-0.4)/0.4f);
        }

        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity();
        glTranslatef(posX, posY, 0.f);
        glColor3f(red, green, blue);
        drawCircle(radius, 48);

    } else {
        isFinishedFlag = true;
    }
}
