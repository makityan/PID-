#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "global.h"

#define N 100
int main(void){
	
	double e[N];
	int i;
//	double K_p,K_i,K_d;
	double r;
	double u[N];	
//	double w[N];
//	double a[N];
//	double b;
	double INT[N];
//	double dx=0.01;
//	double d=exp;

	srand((unsigned)time(NULL));
	FILE *p;

	p=fopen("PID.xls","w");
	if(p==NULL){
		printf("Can't open file.xls\n");
		exit(1);
	}

	r=100;
	e[0]=r;
//	b=exp(-pow(i,2)/10)+10;
	INT[0]=0;
//	b=exp*sin(i);
	
	fprintf(p,"e(t),u(t),r=100,K_p=%6.4f,K_i=%6.4f,K_d=%6.4f\n",K_p,K_i,K_d);
//	fprintf(p,"K_p=%6.4f,K_i=%6.4f,K_d=%6.4f\n",K_p,K_i,K_d);
	for(i=0;i<N/2;i++){
		if(i>0){
			INT[i]=INT[i-1]+(e[i]+e[i-1])/2;
			u[i]=K_p*e[i]+K_i*INT[i]+K_d*((e[i]-e[i-1])/1);
		}else{
			u[i]=K_p*e[i];
		}
		
/*		if(u[i]>30){
			u[i]=30;
		}*/

//		e[i+1]=e[i]-u[i]+exp(-pow(i,2)/100)+10;
//		e[i+1]=e[i]-u[i]+rand()%100;
		e[i+1]=e[i]-u[i]+10;//exp(sin(i/100));
//		printf("%6.5f,%d\n",r-e[i],rand()%100);
		printf("%6.5f,%f\n",r-e[i],u[i]);
		fprintf(p,"%f,%f,%d\n",r-e[i],u[i],100);
	}
	
	fclose(p);
	printf("Exelにファイルをかきだしました。\n");
	printf("Exel内でPIDを作成してください。\n");
	return 0;
}
