/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/
//Version: 002

#include "LUtil.h"

vector<Animation*> destructionAnims;
vector<Ship*> ships;
Projectile *projectile;

//The current color rendering mode
int gColorMode = COLOR_MODE_MULTI;

//The projection scale
GLfloat gProjectionScale = 1.f;

bool keys[256];     //Stores the present state of the keyboard


bool initGL()
{
    //Initialize Projection Matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    GLdouble ar = (double)SCREEN_WIDTH / (double)SCREEN_HEIGHT;
    glOrtho(-VIEW_NATURAL_SCALE*ar, VIEW_NATURAL_SCALE*ar, VIEW_NATURAL_SCALE, -VIEW_NATURAL_SCALE, 1.0, -1.0 );

    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //Initialize clear color
    glClearColor( 0.f, 0.f, 0.f, 1.f );

    //Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        return false;
    }

    return true;
}

void update(int timeNowMs)
{
    ships[0]->thrustLeft(keys['a']);
    ships[0]->thrustRight(keys['d']);
    ships[0]->thrustForward(keys['w']);
    ships[0]->update(timeNowMs);
    projectile->update(timeNowMs);
}

void render()
{
    //Clear color buffer
    glClear( GL_COLOR_BUFFER_BIT );

    //Reset modelview matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    int timeNowMs = glutGet(GLUT_ELAPSED_TIME);

    //1. Draw grid
    drawGrid();

    //2. Draw solars (sun, commets, asteroids, etc...)

    //3. Draw destruction animations and debris
    for(unsigned int i = 0; i < destructionAnims.size(); i++) {
        destructionAnims[i]->draw(timeNowMs);
    }


    //4. Draw ships
    for(unsigned int i = 0; i < ships.size(); i++) {
        ships[i]->draw(timeNowMs);
    }

    //5. Draw projectiles, beam weapon discharge, explosions, and other effects
    projectile->draw(timeNowMs);


    setProjection();

    //Update screen
    glutSwapBuffers();
}

void handleKeyDown( unsigned char key, int x, int y )
{
    keys[key] = true;
    //printf("Key down: %s\r\n", &key);
}

void handleKeyUp( unsigned char key, int x, int y )
{
    keys[key] = false;
    //printf("Key up: %s\r\n", &key);   it works
}

void initGamespace() {
    memset(keys, 0, sizeof(keys));

    LightningAnim *l;

    l = new LightningAnim(-50, -50, 50, 50, glutGet(GLUT_ELAPSED_TIME), 0);
    //l->start(glutGet(GLUT_ELAPSED_TIME));
    destructionAnims.push_back(l);

    l = new LightningAnim(50, -50, -50, 50, glutGet(GLUT_ELAPSED_TIME), 0);
    //l->start(glutGet(GLUT_ELAPSED_TIME));
    destructionAnims.push_back(l);

    //ThrusterAnim *t = new ThrusterAnim(0.f, 0.f, 0.f, 25.f);
    //destructionAnims.push_back(t);
    //t->start();

    Ship *s = new Ship(0.f, 0.f, 5.f);
    ships.push_back(s);

    projectile = new Projectile(0.f, 0.f, 5.f, 20.f, 50.f);

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

void setProjection() {
    //Initialize Projection Matrix, preserve aspect ratio for resizing screen
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    int winWidth = glutGet(GLUT_WINDOW_WIDTH);
    int winHeight = glutGet(GLUT_WINDOW_HEIGHT);
    GLdouble ar = (double)winWidth / (double)winHeight;
    glOrtho(-VIEW_NATURAL_SCALE*ar, VIEW_NATURAL_SCALE*ar, VIEW_NATURAL_SCALE, -VIEW_NATURAL_SCALE, 1.0, -1.0 );
}
