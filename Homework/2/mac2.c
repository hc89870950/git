#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	FILE *fp =fopen("./macin.txt","r");
	FILE *fo =fopen("./macout.txt","w");
	if (fp  == NULL ){
		printf("open file error\n");
	}

	char mac[18]={};
	char key=':';
	int j,k;
	while(fgets(mac, sizeof(mac), fp) != NULL){
        	char command[82]="echo admin";
        	char ssl[45]=" | openssl md5 | cut -c11-32 >> ./macout.txt";
		//delete ':' 
		for(j=k=0; mac[j];j++){
		  if(mac[j]!=key)  mac[k++]=mac[j];
		}
		mac[k]='\0';
		
		//combine admin
		strncat(command,mac,sizeof(mac));
		strncat(command,ssl,sizeof(ssl));
		//printf("%s\n",command);
		system(command);
	}

	fclose(fp);
	fclose(fo);
	system("cat ./macout.txt");
	return 0;
}
