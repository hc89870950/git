#include <stdio.h>
#include <stdlib.h>

int bmi(float h,float w){
        float sh=(h/100.0) *(h/100.0);
        float bmi= w/sh;
        printf("bmi:%.2f\n",bmi);
        printf("haha");
}

