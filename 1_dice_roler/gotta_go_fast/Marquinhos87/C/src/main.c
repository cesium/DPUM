#include "diceroler.h"

int main(int c,char** v){
	srand(time(NULL));
	char* l=NULL;
	size_t s=0;
	ssize_t r;
	if(c==1){
	    while((r=getline(&l,&s,stdin))>=1)
	    	if(strlen(l)<=3) printf("Invalid String Format\n");
		    else if(strcmp(l,"exit\n")==0) return 0;
		    else{
		    	int z=calc(l);
		    	if(z==1) printf("Invalid String Format\n");
			}
	}
	else{
		FILE* f=fopen(v[1],"r");
		if(f==NULL) exit(1);
		while((r=getline(&l,&s,f))!=-1)
			if(strlen(l)<=3) printf("Invalid String Format\n");
		    else if(strcmp(l,"exit\n")==0) return 0;
		    else{
		    	int z=calc(l);
		    	if(z==1) printf("Invalid String Format\n");
			}
	}
	return 0;
}