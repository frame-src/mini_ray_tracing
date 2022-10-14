#include "../inc/image.h"

tSphere *sphereInit(tPoint* center, double radius){
    tSphere *sphere;
    sphere = malloc(sizeof(tSphere));
    if(!sphere)
        return NULL;
    sphere->center = center;
    sphere->radius = radius;
    return sphere;
}