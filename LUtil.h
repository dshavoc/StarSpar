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
#include "Projectile.h"
#include "Solar.h"

using namespace std;


//Screen constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const GLdouble VIEW_NATURAL_SCALE = 105.; //How much length fits in the view
const int SCREEN_FPS = 60;

//Color modes
const int COLOR_MODE_CYAN = 0;
const int COLOR_MODE_MULTI = 1;

bool initGL();

//Perform per-frame logic
void update(int timeNowMs);

//Perform per-frame rendering
void render();


void handleKeyDown( unsigned char key, int x, int y );
void handleKeyUp( unsigned char key, int x, int y );

void initGamespace();
void drawGrid();
void setProjection();

void addProjectile(Projectile*);        //A pointer to this function will be passed to all ships as a way for them
                                        //to add projectiles to the world without any other read/write ability.

#endif
