#include "diceroler.h"

int getD(char* l){
	char* a= malloc(sizeof(char)*strlen(l));
	for(;l[x]!='d';x++)
		if(isdigit(l[x]))
			a[x]=l[x];
		else return 0;
	if(x==0) return 0;
	a[x]='\0';
	x++;
	return atoi(a);
}

int getF(char* l){
	char* a= malloc(sizeof(char)*strlen(l));
	int i;
	for(i=0;l[x]!='\n';i++,x++)
		if(isdigit(l[x]))
			a[i]=l[x];
		else return 0;
	a[i]='\0';
	return atoi(a);
}

int* genV(int d,int f){
	int* v=malloc(sizeof(int)*d);
	for(int i=0;i<d;i++) v[i]=rand()%f+1;
	return v;
}

void prt(int d,int v,int* vs){
	printf("%d:",v);
	for(int i = 0 ; i < d;i++) printf(" %d",vs[i]);
	printf("\n");
}

int sum(int d,int* v){
	int r=0;
	for(int i=0;i<d;i++) r+=v[i];
	return r;
}

int calc(char* l){
	x = 0;
	int d = getD(l);
	int f = getF(l);
	if(d<1 || d>100 || f<2 || f>100) return 1;
	int* v = genV(d,f);
	prt(d,sum(d,v),v);
	return 0;
}