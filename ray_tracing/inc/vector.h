#ifndef VECTOR_H
#define VECTOR_H


#include <math.h>
#include <stdio.h>
#include "image.h"

typedef struct sVector{
    double  p0;  //x
    double  p1;  //y
    double  p2;  //z
}       tVector;

/*  OPERATIONS  */
double     vectorDotProduct( tVector *v1, tVector *v2);
tVector    *vectorCrossProduct (tVector *v1, tVector *v2);
tVector    *vectorDiff(tVector *v1, tVector *v2);
tVector    *vectorSumm( tVector *v1, tVector *v2);
/* VECTOR UTILS */
tVector    *newVector(double x, double y, double z);
tVector    *vectorScalar(tVector *v1, double S);
tVector    *versor(tVector *v);
double     modul(tVector *v1);
/* VECTOR PRINTS */

#endif