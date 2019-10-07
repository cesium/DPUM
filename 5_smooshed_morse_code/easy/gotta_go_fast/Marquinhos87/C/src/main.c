#include "morse.h"

int main(int c,char** v){
	char* l=NULL;
	size_t s=0;
	ssize_t r;
	if(c==1){
	    while((r=getline(&l,&s,stdin))>=1)
	    	if(strlen(l)<=1) printf("Invalid String Format\n");
		    else{
		    	int z=translate(l);
		    	if(z==1) printf("Invalid String Format\n");
			}
	}
	else{
		FILE* f=fopen(v[1],"r");
		if(f==NULL) exit(1);
		while((r=getline(&l,&s,f))!=-1)
			if(strlen(l)<=1) printf("Invalid String Format\n");
		    else{
		    	int z=translate(l);
		    	if(z==1) printf("Invalid String Format\n");
			}
	}
	return 0;
}