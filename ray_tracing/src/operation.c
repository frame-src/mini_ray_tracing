#include "../inc/vector.h"

/*  NEW VECTORE MALLOC  */
tVector    *newVector(double x, double y, double z){
    tVector    *new;

    new = (tVector *)malloc(sizeof(*new));
        if(!new)
            return (NULL);
    new->p0 = x;
    new->p1 = y;
    new->p2 = z;
    return (new);
}

/*  SUMM OF TWO VECTORS  */
tVector    *vectorSumm(tVector *v1, tVector *v2){
    tVector    *new;

    new = newVector(v1->p0 + v2->p0, \
                     v1->p1 + v2->p1, \
                     v1->p2 + v2->p2 );
    return new;
}

/*  DIFFERENCE OF TWO VECTORS  */
tVector    *vectorDiff(tVector *v1, tVector *v2){
    tVector    *new;

    new = newVector(v1->p0 - v2->p0, \
                     v1->p1 - v2->p1, \
                     v1->p2 - v2->p2 );
    return new;
}

/*  SCALAR PRODUCT  */
double  vectorDotProduct( tVector *v1, tVector *v2){
    double dotProduct;

    dotProduct =   ( v1->p0 * v2->p0 + \
                     v1->p1 * v2->p1 + \
                     v1->p2 * v2->p2 );
    return dotProduct;
}

/*  CROSS PRODUCT
    i       j       k
    v1->p0  v1->p1  v1->p2   
    v2->p0  v2->p1  v2->p2 
*/
tVector    *vectorCrossProduct (tVector *v1, tVector *v2){
    tVector    *crossProduct;

    crossProduct = newVector(((v1->p1 * v2->p2) - (v1->p2 * v2->p1)), \
                             ((v1->p2 * v2->p0) - (v1->p0 * v2->p2)), \
                             ((v1->p0 * v2->p1) - (v1->p1 * v2->p0)));
    return crossProduct;
}

/*  SCALAR * VECTOR  */
tVector    *vectorScalar( tVector *v1, double S){
    tVector    *new;

    if(!v1)
        return (NULL);
    new = newVector( v1->p0 * S, \
                     v1->p1 * S, \
                     v1->p2 * S );
    return new;
}

/*  VERSOR  */
tVector    *versor (tVector *v){
    tVector    *new;
    double     lenght;

    lenght = modul(v);
    new = newVector((v->p0)/lenght, (v->p1)/lenght, (v->p2)/lenght);
    return      new;
}
// tVector *square_root(tVector *v){
//     tVector    *new;

//     if(!(v->p0 >= 0 && v->p1 >= 0 && v->p2 >= 0))
//         return NULL;
//     new = (tVector *)malloc(sizeof(*new));
//     if(!new)
//         return (NULL);
//     new->p0 = sqrt(v->p0);
//     new->p1 = sqrt(v->p1);
//     new->p2 = sqrt(v->p2);
//     return (new);
// }

/*  MODUL OF A VECTOR  */
double  modul( tVector *v1){
    return(vectorDotProduct(v1, v1));
}