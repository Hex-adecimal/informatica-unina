//Lezione Lab Prog Gr. 2B del 2021.04.14
#include <stdio.h>
#include <stdlib.h> //necessario per utilizzo malloc, calloc e free
//SUPPONIAMO DI VOLER RIEMPIRE E STAMPARE UN ARRAY CREATO CON MEMORIA DINAMICA


//FUNZIONE RESTITUISCE L'ARRAY CREATO DINAMICAMENTE, CIOE' RESTITUISCE L'INDIRIZZO
//DI MEMORIA DEL PRIMO ELEMENTO (QUESTO E' BENE FARLO SOLO PER MEMORIA ALLOCATA
//DINAMICAMENTE)
//HA COME ARGOMENTO l'indirizzo di memoria di una variabile in cui mettero
//il valore delle dimensioni dell'array creato dinamicamente
int *riempiArrayDinamico(int *pn);

//Dato l'array A di dimensioni n, stampo l'array
void stampaArray(int *A,int n);

//Libero la memoria per l'array allocato dinamicamente
void liberaArray(int *A);

int main(){
	int *V; //Puntatore ad un intero
	int n;  // n variabile che mantiene l'informazione 
		//sulle dimensioni dell'array elementi 
	V=riempiArrayDinamico(&n);
	if (V!=NULL) {
		stampaArray(V,n); //Stampo array
		liberaArray(V); //Libero la memoria creata dinamicamente
		}
		else printf("ARRAY NON CREATO PER MEMORIA INSUFFICIENTE!!!");
return 0;
}

int *riempiArrayDinamico(int *pn){
	int n,i;
	//size_t dipende dal sistema operativo e versione c, 
	//in genere definito come unsigned int
	//void* calloc (size_t num, size_t size); Alloco num elementi di dimensione size byte.
	//					  Memoria contigua e azzero la memoria allocata
	//void* malloc (size_t size);		Alloco size byte (memoria contigua)
	printf("Quanti elementi vuoi inserire?");
	scanf("%d",&n);
	//int *A=(int *)calloc(n,sizeof(int)); //int *A=(int *)calloc(n,sizeof(n))
	//UNA ALTERNATIVA
	int *A= (int *) malloc(n*sizeof(int)); //Con malloc devo stare attento alla
						//inizializzazione, perche' non ho una
						//inizializzazione a zero "automatica"
	if (A!=NULL) {
		for (i=0;i<n;++i) {
		printf("dammi A[%d]=",i);
		scanf("%d",&A[i]);
		}
		n=0;
	}
	*pn=n;    // Accedo al contenuto presente nell'indirizzo di memoria mantenut in pn
		  // e gli assegno il valore di n
	return A; //Restituisco il valore contenuto in A
}
void stampaArray(int *A,int n){
	int i;
	for (i=0;i<n;++i)
		printf("A[%d]=%d\n",i,A[i]);

}
void liberaArray(int *A){
	//void free(void *ptr)
	free(A);
}


