#include "../inc/colors.h"

void    printPixelColor(tRgb *pixelColor){
    int red, green, blue;

    red = (int)(255.999 *pixelColor->r);
    green = (int)(255.999 *pixelColor->g);
    blue = (int)(255.999 *pixelColor->b);
    printf("%d %d %d\n", red, green, blue);
}
