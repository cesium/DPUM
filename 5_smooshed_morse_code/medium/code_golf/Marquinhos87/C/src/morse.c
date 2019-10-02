#include "morse.h"

char translateToChar4(char* c) {
	if(strcmp(c,"-...")) return 'b';
	if(strcmp(c,"-.-.")) return 'c';
	if(strcmp(c,"..-.")) return 'f';
	if(strcmp(c,"....")) return 'h';
	if(strcmp(c,".---")) return 'j';
	if(strcmp(c,".-..")) return 'l';
	if(strcmp(c,".--.")) return 'p';
	if(strcmp(c,"--.-")) return 'q';
	if(strcmp(c,"...-")) return 'v';
	if(strcmp(c,"-..-")) return 'x';
	if(strcmp(c,"-.--")) return 'y';
	if(strcmp(c,"--..")) return 'z';
	return '1';
}

char translateToChar3(char* c) {
	if(strcmp(c,"-..")) return 'd';
	if(strcmp(c,"--.")) return 'g';
	if(strcmp(c,"-.-")) return 'k';
	if(strcmp(c,"---")) return 'o';
	if(strcmp(c,".-.")) return 'r';
	if(strcmp(c,"...")) return 's';
	if(strcmp(c,"..-")) return 'u';
	if(strcmp(c,".--")) return 'w';
	return '1';
}

char translateToChar2(char* c) {
	if(strcmp(c,".-")) return 'a';
	if(strcmp(c,"..")) return 'i';
	if(strcmp(c,"--")) return 'm';
	if(strcmp(c,"-.")) return 'n';
	return '1';
}

char translateToChar1(char* c){
	if(strcmp(c,".")) return 'e';
	if(strcmp(c,"-")) return 't';
	return '1';
}

void prt(char* l,char* t){
	printf("\"%s\"=>%s\n",l,t);
}

int translate(char* l){
	char* res = malloc(sizeof(char)*27);
	char* aux = malloc(sizeof(char)*5);
	int x = 0;
	res[26] = '\0';
	for(int i = 0 ; i < 26 ; i++) {
		aux[0] = l[x]; aux[1] = l[x+1]; aux[2] = l[x+2]; aux[3] = l[x+3]; aux[4] = '\0';
		char c = translateToChar4(aux);
		printf("I=%d -> %s -> %c\n",i,aux,c);
		if (c=='1') {
			aux[0] = l[x]; aux[1] = l[x+1]; aux[2] = l[x+2]; aux[3] = '\0';
			char d = translateToChar3(aux);
			if (d=='1') {
				aux[0] = l[x]; aux[1] = l[x+1]; aux[2] = '\0';
				char e = translateToChar2(aux);
				if (e=='1') {
					aux[0] = l[x]; aux[1] = '\0';
					char f = translateToChar1(aux);
					if (f=='1') {
						return 1;
					}
					else {
						res[i] = c;
						x++;
					}
				}
				else {
					res[i] = c;
					x+=2;
				}
			}
			else {
				res[i] = c;
				x+=3;
			}
		}
		else {
			res[i] = c;
			x+=4;
		}
	}
	prt(l,res);
	return 0;
}