#include "../inc/image.h"

tViewport *initViewport(){
    tViewport *viewport;

    viewport = malloc(sizeof(tViewport));
    if(!viewport)
        return (NULL);
    viewport->height = IMG_HEIGHT;
    viewport->width = IMG_WIDTH;
    viewport->focalLeght = 1.0;
    viewport->origin = (tPoint *)newVector(0,0,0);
    viewport->horizontal = newVector(viewport->width, 0, 0);
    viewport->vertical = newVector(0, viewport->height, 0);
    viewport->lowerLeftCorner = (
        vectorDiff(
            vectorDiff(
                vectorDiff(
                    (tVector*)viewport->origin,
                    vectorScalar(viewport->horizontal, 0.5)
                ),
                vectorScalar(viewport->vertical, 0.5)
            ),
            newVector(0, 0, viewport->focalLeght)
        )
    );
    return(viewport);
}
