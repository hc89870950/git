#include <stdio.h>
#include <stdlib.h>
#include "head.h"

#include <dlfcn.h>
int main(){
        float h,w;
        printf("輸入身高:");
        scanf("%f",&h);
//      printf("ttt:%f\n",h);
        printf("輸入體重:");
        scanf("%f",&w);
//      printf("kkk:%f\n",w);
        height(h);
        weight(w);
        bmi(h,w);
}

