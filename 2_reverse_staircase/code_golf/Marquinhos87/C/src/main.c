#include "stair.h"

int main(int c,char** v){
	if(c==1){
	    printf("ERROR: Iniciate like that 'stairCase n', where n is the number of stairs\n");
	}
	else{
		int z=stair(v[1]);
		if(z==1) printf("Invalid Number\n");
	}
	return 0;
}