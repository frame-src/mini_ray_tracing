#include "../inc/image.h"

// void systemLeaks(){
//     system("leaks image");
// }
// atexit(systemLeaks);

int main (void){
    int         i, j;
    double      u, v;
    tRgb        *pixel;
    tViewport   *viewport;
    tRay        *ray;
    tVector *direction;

    viewport = initViewport();    
    pixel = (tRgb *)newVector( 0, 0, 0);
    printf("P3\n");
    printf("%d %d\n", IMG_WIDTH, IMG_HEIGHT);
    printf("%d\n", 255);
    i = IMG_HEIGHT;
    while(i > 0){
        j = 0;
        while(j < IMG_WIDTH){
            u = (double)(j) / (IMG_WIDTH - 1);
            v = (double)(i) / (IMG_HEIGHT - 1);
            direction = directionCoordinatesCalculation( viewport, u, v);
            ray = rayInit(viewport, direction); 
            pixel = rayColor(ray);
            printPixelColor(pixel);
            j++;
        }
        i--;
    }
}

