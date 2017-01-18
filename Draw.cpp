
#include "Draw.h"
#include "MyMath.h"


void drawCircle(float radius, unsigned int numPoints) {

    glBegin(GL_LINE_STRIP);
    for(unsigned int i=0; i<=numPoints; i++) {
        glVertex2f( radius * cos((float)i*2*PI/numPoints),
                    radius * sin((float)i*2*PI/numPoints) );
    }
    glEnd();
}

void drawHex(float radius) {

    glBegin(GL_LINE_STRIP);

    glVertex2f( 0.5 * radius,   ROOT_3_BY_2 * radius );
    glVertex2f( radius,         0 );
    glVertex2f( 0.5 * radius,   -ROOT_3_BY_2 * radius );
    glVertex2f( -0.5 * radius,  -ROOT_3_BY_2 * radius );
    glVertex2f( -radius,        0 );
    glVertex2f( -0.5 * radius,  ROOT_3_BY_2 * radius);
    glVertex2f( 0.5 * radius,   ROOT_3_BY_2 * radius );

    glEnd();
}

void drawHexGrid(float radiusOut, float radiusHex) {
    float x, y;
    int numHex = (int)(radiusOut / radiusHex);

    for(int i = -numHex; i <= numHex; i++) {
        for(int j = -numHex; j <= numHex; j++) {
            x = i * radiusHex * 3/2;
            y = radiusHex * ROOT_3_BY_2 * (2*j - (i%2==0 ? 0.f : 1.f));
            if(hypot(x, y) <= radiusOut) {
                glPushMatrix();
                glTranslatef(x, y, 0.f);
                drawHex(radiusHex);
                glPopMatrix();
            }
        }
    }

}

void drawGrid() {
    const int GRID_MIN = -5;
    const int GRID_MAX = 5;
    const float GRID_SCALE = 20;

    glBegin( GL_LINES );
    glColor3f(0.2f, 0.2f, 0.2f);

    for(int x = GRID_MIN; x <= GRID_MAX; x++) {
        //Horizontal
        glVertex2f(GRID_MIN * GRID_SCALE, x * GRID_SCALE);
        glVertex2f(GRID_MAX * GRID_SCALE, x * GRID_SCALE);

        //Vertical
        glVertex2f(x * GRID_SCALE, GRID_MIN * GRID_SCALE);
        glVertex2f(x * GRID_SCALE, GRID_MAX * GRID_SCALE);
    }

    //Major axes
    glColor3f(0.35f, 0.35f, 0.35f);
    glVertex2f(GRID_MIN * GRID_SCALE, 0);
    glVertex2f(GRID_MAX * GRID_SCALE, 0);
    glVertex2f(0, GRID_MIN * GRID_SCALE);
    glVertex2f(0, GRID_MAX * GRID_SCALE);

    glEnd();
}
