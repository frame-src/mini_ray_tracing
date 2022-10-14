#include "../inc/image.h"

tPoint   *rayOriginInit(tPoint *coordinates){
    tPoint *origin;
    origin = malloc(sizeof(tPoint));
    origin->x = coordinates->x;
    origin->y = coordinates->y;
    origin->z = coordinates->z;
    return origin;
}
void    rayDirectionInit(tVector *direction, tVector *coordinates){
    direction->p0 = coordinates->p0;
    direction->p1 = coordinates->p1;
    direction->p2 = coordinates->p2;
}
//𝐏(𝑡)=𝐀+𝑡𝐛;
tRgb    *rayColor(tRay *ray){
    double  t;
    tRgb    *startColor;
    tRgb    *endColor;
    tVector *unit;

    unit = versor((tVector *)ray->direction);
    // printf("t %f %f %f \n", ray->direction->p0, ray->direction->p1, ray->direction->p2);
    // printf("t %f %f %f \n", unit->p0, unit->p1, unit->p2);
    startColor = (tRgb *)newVector(1.0, 1.0, 1.0);
    endColor = (tRgb *)newVector(0.5, 0.7, 1.0);
    t = (0.5)*((unit)->p1 + 1.0);
    endColor = (tRgb *)vectorSumm(
                        vectorScalar((tVector *)startColor,(1.0 - t)),
                        vectorScalar((tVector *)endColor, t)
                    );
    return (endColor);
}
/* lower_left_corner + u*horizontal + v*vertical - origin */
tVector *directionCoordinatesCalculation(tViewport *viewport, double u, double v){
    tVector *direction;
    tVector *tmp;

    tmp = vectorScalar((viewport->horizontal), u);
    direction = vectorSumm(viewport->lowerLeftCorner,tmp);
    free (tmp);
    tmp = vectorScalar((viewport->vertical), v);
    direction = vectorSumm(direction,tmp);
    free (tmp);
    direction = vectorDiff(direction, (tVector *)viewport->origin);
    return direction;
}

tRay    *rayInit( tViewport *viewport, tVector *direction){
    tRay    *ray;
    ray = malloc(sizeof(tRay));
    if(!ray)
        return NULL;
    ray->origin = viewport->origin;
    ray->direction = direction;
    return ray;
}
