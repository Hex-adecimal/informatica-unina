#include <stdio.h> /*header file: aggiungo, includo, il file di testo stdio.h all'inizio
			di questo file*/
/*Versione Procedurale di tipo top-down*/
struct risAndRes {
	int ris;
	int res;
	float pippo;
}; //Ricordo che sto definendo la struttura ma NON sto creando alcuna variabile!!!!
int leggiNumero();
int leggiCifra();
int verificaCifra(int,int);
void stampa(int);
int main() {
	int x=0,cifra, presente=0;
	struct risAndRes ss; //Creo la variabile ss di tipo "struct risAndRes"
	x = leggiNumero();
	cifra=leggiCifra();
	presente=verificaCifra(x,cifra);
	stampa(presente); 
return 0;
}
int leggiCifra(){
	int x;
	printf("Dammi la cifra da trovare:");
	scanf("%d",&x);
	return x;
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

int verificaCifra(int x,int cifra){
	int presente=0;
	struct risAndRes ss;
	do {	
		ss= estraiPrimaCifra(x);
		if (cifra== ss.res) presente=1;
		x=ss.ris;
	} while(x!=0 && presente==0);
	
	return presente;
}
void stampa(int presente){
	if (presente==1)
		printf("La cifra e' presente");
		else
		printf("La cifra non e' presente");
}
