#ifndef DRAW_H
#define DRAW_H

#include "LOpenGL.h"

#define ROOT_3_BY_2     (0.866025404)
#define PI              (3.14159f)

void drawCircle(float radius, unsigned int numPoints);
void drawHex(float radius);
void drawHexGrid(float, float);
void drawGrid();

#endif
