#include "stair.h"

int verify(char* l){
	for(int i=0;l[i]!='\0' || l[i]!='\n';i++)
		if(!isdigit(l[i])) return 1;
	return 0;
}

void prt(int tam){
	for(int i=0;i<tam;i++){
		for(int j=tam-i-1;j>0;j--)
			printf(" ");
		for(int k=i+1;k>0;k--)
			printf("#");
		printf("\n");
	}
}

int stair(char* l){
	int len = strlen(l);
	if(verify(l)) {
		int tam = atoi(l);
		if(tam>100 || tam<1) return 1;
		prt(tam);
	}
	else return 1;
	return 0;
}