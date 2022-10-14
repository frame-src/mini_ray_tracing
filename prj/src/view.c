#include "../inc/image.h"

/*origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);*/
static tVector *lowerLeftCornerCalculation(tViewport *viewport){
    tVector *lowerLeftCorner;
    tVector *tmp;
    tmp = vectorScalar(viewport->horizontal, 0.5);
    lowerLeftCorner = vectorDiff((tVector *)viewport->origin, tmp);
    free(tmp);
    tmp = vectorScalar(viewport->vertical, 0.5);
    lowerLeftCorner = vectorDiff(lowerLeftCorner, tmp);
    free(tmp);
    tmp = newVector(0, 0, viewport->focalLeght);
    lowerLeftCorner = vectorDiff(lowerLeftCorner, tmp);
    free(tmp);
    return lowerLeftCorner;
}

tViewport *initViewport(){
    tViewport *viewport;

    viewport = malloc(sizeof(tViewport));
    if(!viewport)
        return (NULL);
    viewport->height = 4.0;
    viewport->width = viewport->height * (double)(16.0/9.0);
    viewport->focalLeght = 1.0;
    viewport->origin = (tPoint *)newVector(0,0,0);
    viewport->horizontal = newVector(viewport->width, 0, 0);
    viewport->vertical = newVector(0, viewport->height, 0);
    viewport->lowerLeftCorner = lowerLeftCornerCalculation(viewport);
    return(viewport);
}
