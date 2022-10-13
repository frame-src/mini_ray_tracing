#include "../inc/image.h"

void rayOriginInit(tPoint *origin, tPoint *coordinates){
    origin->x = coordinates->x;
    origin->y = coordinates->y;
    origin->z = coordinates->z;
}
void rayDirectionInit(tVector *direction, tVector *coordinates){
    direction->p0 = coordinates->p0;
    direction->p1 = coordinates->p1;
    direction->p2 = coordinates->p2;
}
//𝐏(𝑡)=𝐀+𝑡𝐛;
tRgb *rayColor(tRay *ray){
    tVector *u;
    double  t;
    tRgb    *color;

    u = newVector(  (versor((tVector *)ray->direction))->p0,
                    (versor((tVector *)ray->direction))->p1,
                    (versor((tVector *)ray->direction))->p2);
    t = (1/2)*(u->p1 + 1.0);
    color = (tRgb *)vectorSumm(
                        vectorScalar((tVector *)color{->r = 1.0,->g = 1.0, ->b = 1.0},(1.0 - t)),
                        vectorScalar((tVector *)color{->r 0.5,->g 0.7,->b 1.0}, t)
                    );
    return (color);
}
