# ifndef IMAGE_H
#define IMAGE_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include "vector.h"

#define IMG_WIDTH 700
#define IMG_HEIGHT 300

//the ray is a "line"  𝐏(𝑡)=𝐀+𝑡𝐛;
typedef struct sRay{
const tVector   origin;
const tVector   direction;
void (*originInit)(tVector *origin, tVector *coordinates);
void (*directionInit)(tVector *direction, tVector *coordinates);
}   tRay;

tRgb *rayColor(tRay *ray);

#endif