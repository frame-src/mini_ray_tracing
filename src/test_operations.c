#include "../inc/image.h"

void printVector(tVector *v){
    printf("i:%f ", v->p0);
    printf("j:%f ", v->p1);
    printf("k:%f \n", v->p2);
}

int main (void){
    tVector *v;
    tVector *v1;

    v = newVector(1,1,1);
    v1 =  newVector(1,0,1);
    printf("vector DIFF \n");
    printVector(vectorDiff(v,v1));
    printf("vector SUMM \n");
    printVector(vectorSumm(v,v1));
    printf("vector CROSSPRODUCT\n");
    printVector(vectorCrossProduct(v,v1));
    printf("vector DOTPRODUCT\n");
    printf("%f", vectorDotProduct(v,v1));
}