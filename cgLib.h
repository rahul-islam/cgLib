#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#ifndef CGLIB_H_INCLUDED
#define CGLIB_H_INCLUDED

void drawLine(float x1, float y1, float x2, float y2);

void drawCircle ( float xc, float yc, float r);

void eclips(float xc,float yc, float rx, float ry);

void parallel(float x1,float y1, float x2, float y2);

void Bresenham(float x ,float y, float z, float l);

void wu(float x ,float y, float z, float l);

void Cartesian(float xc ,float yc, float r);

void Parametric(float xc ,float yc, float r);

void dda(float x ,float y, float z, float l);

void Bresenham_circle(float xc, float yc, float r);

void mid_point(float xc ,float yc, float r);

void cartisian_eci(float Xc,float Yc,float radius_x,float radius_y);

void mid_eci(float xc,float yc, float rx, float ry);

void mid_line(float x1, float y1,float x2, float y2);

#endif
