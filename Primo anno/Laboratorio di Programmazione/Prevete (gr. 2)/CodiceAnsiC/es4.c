#include <stdio.h>
//Il fattoriale di un numero intero n non negativo, si scrive n! e si legge “n fattoriale” ed è definito come: n*(n-1)*...*1 quando n è maggiore o uguale ad 1, mentre se n è uguale a 0 è pari a 1. Scrivere un programma che legga un numero intero non negativo e stampi il suo fattoriale.

int riceviInput();
int fattoriale(int);
int main() {
	int n=0,res=0;
	//FASE IN CUI PRENDO LE INFORMAZIONI
 	//printf("Dammi il valore di n:");
	//scanf("%d",&n);
	n=riceviInput();
	//FASE IN CUI RISOLVO IL PROBLEMA
	res=fattoriale(n);

	//FASE IN CUI DO LA SOLUZIONE ALL'ESTERNO
	printf("Il fattoriale di n=%d e' = %d\n",n,res);
	return 0;
}
int riceviInput(){
	int n;
	do {
	  printf("Dammi il valore di n maggiore o uguale a 0:");
	  scanf("%d",&n);			
	} while (n<0);
	return n;
}
//PRE-CONDIZIONE: n>=0 
int fattoriale(int n){
	int fatt=1;
	
	for (fatt=1; n>1;n=n-1) fatt=n*fatt;		
	//if (n>0) fatt=n*fattoriale(n-1);
	return fatt;
}
