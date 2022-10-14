#include "../inc/image.h"

double hitSphere(tSphere *sphere, tRay *ray) {
    tVector *OC = vectorDiff((tVector *)ray->origin, (tVector *)sphere->center);
    double A = vectorDotProduct((tVector*)ray->direction, (tVector *)ray->direction);
    double B = 2.0 * vectorDotProduct(OC, (tVector *)ray->direction);
    double C = vectorDotProduct(OC, OC) - (sphere->radius)*(sphere->radius);
    double discriminant = B*B - 4*A*C;
    if(discriminant < 0)
        return (-1.0);
    return (-B - sqrt(discriminant))/(2.0*A);
}