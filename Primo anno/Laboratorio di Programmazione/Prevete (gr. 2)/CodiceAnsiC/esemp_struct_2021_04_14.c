//Lezione Lab Prog Gr. 2B del 2021.04.14
#include <stdio.h>
#define MAXLEN 10
//NON HO DEFINITO NESSUNA VARIABILE, MA HO ASSOCIATO ALL'IDENTIFICATORE miaStruc
// (si può scegliare qualunque nome all'interno di quelli ammissibili)
// UNA struct come quella definita
struct miaStruct {
	int n; //Capo della struct: nome: n tipo: int 
	char c[MAXLEN];//Capo della struct: nome: c tipo: stringa
	float x; //Capo della struct: nome: x tipo: float
};

void stampaMiaStruct( struct miaStruct ss);
struct miaStruct riempiMiaStruct();
int main(){
	struct miaStruct rr; //QUI e' definita la variabile rr di tipo struct miaStruct
	rr=riempiMiaStruct();

	stampaMiaStruct(rr); //ANCHE IN QUESTO CASO PASSAGGIO PER VALORE
	struct miaStruct rr2;//QUi ho definito un' altra variable di tipo struct
	rr2=riempiMiaStruct();

	stampaMiaStruct(rr2); //ANCHE IN QUESTO CASO PASSAGGIO PER VALORE	
return 0;
}
//ANCHE IN QUESTO CASO PASSAGGIO PER VALORE:
//E' CREATO IL PARAMETRO FORMALE ss (che è una struct miaStruct)
// Al parametro formale è assegnato il valore del parametro attuale (ad esempio rr del main),
// cioè ai campi di ss sono assegnati i valori dei rispettivi campi del parametro attuale,
// ad esempio queli di rr
void stampaMiaStruct( struct miaStruct ss){
	printf("c: %s x: %f n:%d\n",ss.c,ss.x,ss.n);
}

struct miaStruct riempiMiaStruct(){
	struct miaStruct ss; //Varialie struct locale alla funzione
	printf("Dammi carattere, intero, float:");
	scanf("%s %d %f",ss.c,&(ss.n),&(ss.x));
	return ss;
}
/*
int main() {
	struct {
		int n; //Capo della struct: nome: n tipo: int 
		char c;//Capo della struct: nome: c tipo: char
		float x; //Capo della struct: nome: x tipo: float
	} rr; //rr è una variabile "composita", che e' costituita da più variabili,
		// dette campi della struct
	//Posso accedere ai campi della struct tramite l'operatore '.' 
	rr.n=0;
	rr.c='a';
	rr.x=23.5;
	//SCRIVO ALTRO CODICE
	//SE VOLGIO UNA ALTRA VARIABILE COME rr, devo replicare il codice
	printf("%c %f %d\n",rr.c,rr.x,rr.n);
return 0;
}
*/

/*
void prova() {
	//SE VOLGIO UNA ALTRA VARIABILE COME rr, devo replicare il codice

	struct {
		int n; //Capo della struct: nome: n tipo: int 
		char c;//Capo della struct: nome: c tipo: char
		float x; //Capo della struct: nome: x tipo: float
	} xx; //xx è una variabile "composita", che e' costituita da più variabili,
	
}
*/
