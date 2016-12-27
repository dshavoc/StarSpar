
#ifndef LUTIL_H
#define LUTIL_H

#include "LOpenGL.h"
#include <stdio.h>
#include <cstdlib>
#include <cstring>

//Screen constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const GLdouble VIEW_NATURAL_SCALE = 105.; //How much length fits in the view
const int SCREEN_FPS = 60;

bool initGL();

void handleKeyDown( unsigned char key, int x, int y );
void handleKeyUp( unsigned char key, int x, int y );

void setProjection();

bool getKey(unsigned int code);
void resetKeys();

#endif
