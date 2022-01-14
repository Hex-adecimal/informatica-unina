//ESEMPIO DI SVILUPPO DI UN PROGRAMMA IN PIU' FILE: File di dicharazione funzioni,ed
//eventualmente #define (header file), e file di definizione di funzioni
// Qui e' riportato un esempio semplice costituito da un unico header file ed un unico
//file di definizione di funzioni: 
// Il file header e' "matriciDinamiche.h", 
// Il file di definizione delle funzioni e': libMatriciDinamiche.c, di cui deve essere creato
// l'object file libMatriciDinamiche.o tramite il comando gcc -c libMatriciDinamiche.c
//COMPILARE CON: gcc esempioPropriaLibreria.c libMatriciDinamiche.o -o esempioPropriaLibreria
//PER ULTERIORI APPROFONDIMENTI VEDERE: https://www.cs.dartmouth.edu/~campbell/cs50/buildlib.html

#include <stdio.h>
#include "matriciDinamiche.h"
int main(){
	int r,c;
	int **M1,**M2,*M3;
	printf("Dammi r e c:");
	scanf("%d %d",&r,&c);
	M1=creaMatriceDinamica1(r,c);
	M2=creaMatriceDinamica2(r,c);
	M3=creaMatriceDinamica3(r,c);
	//ALTRO CODICE
	liberaMatriceDinamica1(M1,r);
	liberaMatriceDinamica2(M2);
	liberaMatriceDinamica3(M3);
return 0;
}
