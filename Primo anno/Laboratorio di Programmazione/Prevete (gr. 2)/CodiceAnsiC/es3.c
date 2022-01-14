#include <stdio.h>

int verificaCodizione(int,int,int);
void stampa(int);
int main(){
	int verifica=0;
	int a,b,c;
	printf("Dammi tre interi positivi:");
	scanf("%d %d %d",&a,&b,&c);
	verifica=verificaCodizione(a,b,c);
	stampa(verifica);
return 0;
}

int verificaCodizione(int a,int b,int c){
	int ver=0;
	if (a*a == (b*b + c*c)) ver=1;
	else if (b*b== (a*a+c*c)) ver=1;
	else if  (c*c == (b*b+a*a)) ver=1;
	return ver;
}
void stampa(int verifica){
	if (verifica==1) printf("E' un triangolo rettangolo!\n");
	else printf("Non e' un triangolo rettangolo!\n");
}

