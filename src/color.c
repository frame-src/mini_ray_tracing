#include "../inc/colors.h"

void    printPixelColor(tRgb *pixelColor){
    int red, green, blue;

    red = (int)(255.999 *pixelColor->r);
    green = (int)(255.999 *pixelColor->g);
    blue = (int)(255.999 *pixelColor->b);
    printf("%d %d %d\n", red, green, blue);
}

tRgb   *colorAssign(tRgb *pixelColor, int i, int j){
    pixelColor->r = (double)(i)/(IMG_WIDTH - 1);
    pixelColor->g = (double)(j)/(IMG_HEIGHT - 1);
    pixelColor->b = 0.25;
    return pixelColor;
}