/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/
//Version: 002

#ifndef LUTIL_H
#define LUTIL_H

#include "LOpenGL.h"
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "animations.h"
#include "Ship.h"

using namespace std;

extern vector<Animation*> destructionAnims;     //extern so it isn't multiply declared by every file that includes this

//Screen constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const GLdouble VIEW_NATURAL_SCALE = 105.; //How much length fits in the view
const int SCREEN_FPS = 60;

//Color modes
const int COLOR_MODE_CYAN = 0;
const int COLOR_MODE_MULTI = 1;

bool initGL();
/*
Pre Condition:
 -A valid OpenGL context
Post Condition:
 -Initializes matrices and clear color
 -Reports to console if there was an OpenGL error
 -Returns false if there was an error in initialization
Side Effects:
 -Projection matrix is set to an orthographic matrix
 -Modelview matrix is set to identity matrix
 -Matrix mode is set to modelview
 -Clear color is set to black
*/

//Perform per-frame logic
void update(int timeNowMs);

//Perform per-frame rendering
void render();


void handleKeyDown( unsigned char key, int x, int y );
void handleKeyUp( unsigned char key, int x, int y );

void initGamespace();
void drawGrid();
void setProjection();

#endif
