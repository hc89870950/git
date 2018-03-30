#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main(){
        float h,w;
        printf("input your height:");
        scanf("%f",&h);
//      printf("ttt:%f\n",h);
        printf("input your weight:");
        scanf("%f",&w);
//      printf("kkk:%f\n",w);
        height(h);
        weight(w);
        bmi(h,w);
}
