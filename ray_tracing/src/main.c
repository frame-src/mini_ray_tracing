#include "../inc/image.h"


tRgb   *colorAssign(tRgb *pixelColor, int i, int j){
    pixelColor->r = (double)(i)/(IMG_WIDTH - 1);
    pixelColor->g = (double)(j)/(IMG_HEIGHT - 1);
    pixelColor->b = 0.25;
    return pixelColor;
}

int main (void){
    int i, j;
    double scaled;
    double aspectRatio;
    tRgb *pixel;
    
    scaled = IMG_WIDTH;
    aspectRatio = (1/(IMG_WIDTH/IMG_HEIGHT));
    pixel = (tRgb *)newVector( 0, 0, 0);
    printf("P3\n");
    printf("%d %d\n", IMG_WIDTH, IMG_HEIGHT);
    printf("%d\n", 256);
    i=0;
    while(i < IMG_HEIGHT){
        j = 0;
        while(j < IMG_WIDTH){
            scaled = j * aspectRatio;
            pixel = colorAssign(pixel, i, scaled);
            printPixelColor(pixel);
            j++;
        }
        i++;
    }
}