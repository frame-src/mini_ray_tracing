#include "../inc/image.h"

int main (void){
    int i, j;
    double scaled;
    double aspectRatio;
    tRgb *pixel;
    tViewport   *viewport;

    viewport = initViewport();
    scaled = IMG_WIDTH;
    aspectRatio = (1/(IMG_WIDTH/IMG_HEIGHT));
    pixel = (tRgb *)newVector( 0, 0, 0);
    printf("P3\n");
    printf("%d %d\n", IMG_WIDTH, IMG_HEIGHT);
    printf("%d\n", 255);
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