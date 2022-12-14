# ifndef IMAGE_H
#define IMAGE_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "colors.h"
#include "vector.h"

#define IMG_WIDTH 533
#define IMG_HEIGHT 300
typedef struct sVector tVector;
typedef struct sRgb tRgb;
typedef struct sPoint tPoint;
typedef struct sSphere tSphere;

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
const tPoint    *rect;
}   tRay;

typedef struct sSphere{
    tPoint *center;
    double radius;
}   tSphere;

//void rayOriginInit(struct sRay* ray, tPoint *, tPoint *);
tPoint  *rayOriginInit(tPoint *coordinates);
void    rayDirectionInit(tVector *direction, tVector *coordinates);
tVector *directionCoordinatesCalculation(tViewport *viewport, double u, double v);
tRay    *rayInit( tViewport *viewport, tVector *direction);
double    hitSphere(tSphere *sphere, tRay *ray);
tViewport *initViewport();
tRgb    *rayColor(tRay *ray);

tSphere *sphereInit(tPoint* center, double radius);

#endif