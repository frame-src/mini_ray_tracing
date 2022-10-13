# ifndef IMAGE_H
#define IMAGE_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include "vector.h"

#define IMG_WIDTH 700
#define IMG_HEIGHT 300
typedef struct sVector tVector;
typedef struct sRgb tRgb;
typedef struct sPoint tPoint;

typedef struct sViewport{
    double  height;
    double  width;
    double  focalLeght;
    tPoint  *origin;
    tVector *horizontal;
    tVector *vertical;
    tVector *lowerLeftCorner;

}   tViewport;

//the ray is a "line"  𝐏(𝑡)=𝐀+𝑡𝐛;
typedef struct sRay{
const tPoint    *origin;
const tVector   *direction;

//void (*originInit)(tPoint *, tPoint *);
//void (*directionInit)(tVector *, tVector *);

}   tRay;

//void rayOriginInit(struct sRay* ray, tPoint *, tPoint *);
void rayOriginInit(tPoint *, tPoint *);
tViewport *initViewport();

tRgb *rayColor(tRay *ray);

#endif