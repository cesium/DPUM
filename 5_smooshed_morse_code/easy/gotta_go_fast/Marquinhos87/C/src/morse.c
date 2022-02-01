#include "morse.h"

char* translateChar(char c) {
	if(c=='A' || c=='a') return ".-";
	if(c=='B' || c=='b') return "-...";
	if(c=='C' || c=='c') return "-.-.";
	if(c=='D' || c=='d') return "-..";
	if(c=='E' || c=='e') return ".";
	if(c=='F' || c=='f') return "..-.";
	if(c=='G' || c=='g') return "--.";
	if(c=='H' || c=='h') return "....";
	if(c=='I' || c=='i') return "..";
	if(c=='J' || c=='j') return ".---";
	if(c=='K' || c=='k') return "-.-";
	if(c=='L' || c=='l') return ".-..";
	if(c=='M' || c=='m') return "--";
	if(c=='N' || c=='n') return "-.";
	if(c=='O' || c=='o') return "---";
	if(c=='P' || c=='p') return ".--.";
	if(c=='Q' || c=='q') return "--.-";
	if(c=='R' || c=='r') return ".-.";
	if(c=='S' || c=='s') return "...";
	if(c=='T' || c=='t') return "-";
	if(c=='U' || c=='u') return "..-";
	if(c=='V' || c=='v') return "...-";
	if(c=='W' || c=='w') return ".--";
	if(c=='X' || c=='x') return "-..-";
	if(c=='Y' || c=='y') return "-.--";
	if(c=='Z' || c=='z') return "--..";
	if(c=='1') return ".----";
	if(c=='2') return "..---";
	if(c=='3') return "...--";
	if(c=='4') return "....-";
	if(c=='5') return ".....";
	if(c=='6') return "-....";
	if(c=='7') return "--...";
	if(c=='8') return "---..";
	if(c=='9') return "----.";
	if(c=='0') return "-----";
	if(c=='\n') return "";
	return NULL;
}

void prt(char* l,char** ls,int n){
	printf("\"%s\"=>",l);
	for(int i=0;i<n;i++) printf("%s",ls[i]);
	printf("\n");
}

int translate(char* l){
	int len = strlen(l);
	char** letras = malloc(sizeof(char*)*len);
	for(int i=0;i<len;i++){
		letras[i] = malloc(sizeof(char)*6);
		letras[i] = translateChar(l[i]);
		if(letras[i] == NULL) return 1;
	}
	l[len-1] = '\0';
	prt(l,letras,len);
	return 0;
}