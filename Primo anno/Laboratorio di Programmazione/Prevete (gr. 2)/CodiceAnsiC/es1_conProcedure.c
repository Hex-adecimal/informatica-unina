#include <stdio.h> /*header file: aggiungo, includo, il file di testo stdio.h all'inizio
			di questo file*/
/*Versione Procedurale di tipo top-down*/
struct risAndRes {
	int ris;
	int res;
	float pippo;
}; //Ricordo che sto definendo la struttura ma NON sto creando alcuna variabile!!!!
int leggiNumero();
struct risAndRes estraiPrimaCifra(int);
void stampa(int,int);
int main() {
	int x=0,c=0;
	struct risAndRes ss; //Creo la variabile ss di tipo "struct risAndRes"
	x = leggiNumero();
	do {	
		ss= estraiPrimaCifra(x);
		stampa(c,ss.res); 
		x=ss.ris;
		++c;	
	} while(x!=0);
return 0;
}

int leggiNumero(){
	int x;

	printf("**********************\n");
	printf("Dammi un numero intero:");
	scanf("%d",&x);

	return x;	
}
struct risAndRes estraiPrimaCifra(int x){
	struct risAndRes tmp;

	tmp.ris=x/10;
	tmp.res=x%10;

	return tmp;
}

void stampa(int conta, int cifra){

	printf("cifra corrispondente a 10 elevoto a%d =%d\n",conta,cifra);
}
