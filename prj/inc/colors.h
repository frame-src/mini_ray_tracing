# ifndef COLORS_H
#define COLORS_H

#include "image.h"

typedef struct sRgb{
    double r;
    double g;
    double b;
}   tRgb;

void    printPixelColor(tRgb *pixelColor);
tRgb   *colorAssign(tRgb *pixelColor, int i, int j);

#endif