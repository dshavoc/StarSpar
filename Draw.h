#ifndef DRAW_H
#define DRAW_H

#include "LOpenGL.h"

void drawCircle(float radius, unsigned int numPoints = 36);
void drawOval(float radiusX, float radiusY, unsigned int numPoints = 36);
void drawHex(float radius);
void drawHexGrid(float, float);
void drawGrid();

#endif
