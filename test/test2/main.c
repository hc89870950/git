#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main(){
	float h,w;
	printf("high:");
	scanf("%f",&h);
//	printf("ttt:%f\n",h);
	printf("weight:");
	scanf("%f",&w);
//	printf("kkk:%f\n",w);
	hello(h);
	hello2(w);
	bmi(h,w);
}
