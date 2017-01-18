
#include "LUtil.h"


//The projection scale
GLfloat gProjectionScale = 1.f;

bool keys[128];     //Stores the present state of the keyboard


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

void resetKeys() {
    memset(keys, 0, sizeof(keys));
}

bool getKey(unsigned int code) {
    return keys[code];
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


