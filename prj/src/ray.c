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
    tVector *N;
    tSphere *sphere;
    
    sphere = sphereInit((tPoint *)newVector(0, 0, -1), 0.5);
    t = hitSphere(sphere, ray);
    ray->rect = (tPoint *)vectorSumm((tVector *)ray->origin, vectorScalar((tVector *)ray->direction, t));
    if (t > 0){
        N = versor(vectorDiff((tVector*)ray->rect, newVector(0,0,-1)));
        return((tRgb *)(vectorScalar(newVector(N->p0 + 1, N->p1 + 1, N->p2 + 1), 0.5)));
    }
    N = versor((tVector *)ray->direction);
    startColor = (tRgb *)newVector(1.0, 1.0, 1.0);
    endColor = (tRgb *)newVector(0.7, 0.1, 1);
    t = (0.5)*((N)->p1 + 1.0);
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
