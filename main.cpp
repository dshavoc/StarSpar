/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/
//Version: 002

/* NOTE: When compiling on windows, ensure that the linker search paths
         include both freeglut\bin and freeglut\lib
         */


#include "Game.h"
#include <time.h>

void runMainLoop( int val );
/*
Pre Condition:
 -Initialized freeGLUT
Post Condition:
 -Calls the main loop functions and sets itself to be called back in 1000 / SCREEN_FPS milliseconds
Side Effects:
 -Sets glutTimerFunc
*/

int main( int argc, char* args[] )
{
    //Initialize randon number generator
    srand (time(NULL));

    //Initialize FreeGLUT
    glutInit( &argc, args );

    //Create OpenGL 2.1 context
    glutInitContextVersion( 2, 1 );

    //Create Double Buffered Window
    glutInitDisplayMode( GLUT_DOUBLE );
    glutInitWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );

    glutCreateWindow( "OpenGL" );
    //glutFullScreen(); //Alt+F4 to exit
    //Do post window/context creation initialization
    if( !initGL() )
    {
        printf( "Unable to initialize graphics library!\n" );
        return 1;
    }
    //Set keyboard handler
    glutKeyboardFunc( handleKeyDown );
    glutKeyboardUpFunc( handleKeyUp );

    //Set rendering function (This is required, else crash with error "No display callback registered for window 1"
    glutDisplayFunc( render );

    //Set main loop
    glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, 0 );

    initGamespace();

    //Start GLUT main loop
    glutMainLoop();

    return 0;
}

void runMainLoop( int val )
{

    int timeNowMs = glutGet(GLUT_ELAPSED_TIME);

    //Frame logic
    update(timeNowMs);
    render();

    //Run frame one more time
    glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, val );
}
