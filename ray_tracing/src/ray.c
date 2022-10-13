#include "image.h"

void originInit(tVector *origin, tVector *coordinates){
    origin->p0 = coordinates->p0;
    origin->p1 = coordinates->p1;
    origin->p2 = coordinates->p2;
}
void directionInit(tVector *direction, tVector *coordinates){
    direction->p0 = coordinates->p0;
    direction->p1 = coordinates->p1;
    direction->p2 = coordinates->p2;
}
//𝐏(𝑡)=𝐀+𝑡𝐛;
tRgb *rayColor(tRay *ray){
    tVector *versore;
    double  t;

    versore = newVector((versor(v))->p0,
                        (versor(v))->p1,
                        (versor(v))->p2);
    t = 0.5*(versore->p1 + 1.0);
    tVector()
}