/*
Ho una lista , un puntatore ad un nodo e  voglio spostarlo In testa.
*/
#include <stdio.h>
#include <stdlib.h>
struct elem {
	int k;
	struct elem *next;
};

struct elem *newElem(int k);
struct elem *insInCodaR(struct elem *top, int k);
struct elem *insInOrdineR(struct elem *top, int k);
struct elem *insInOrdine(struct elem *top, int k);
struct elem *spostoElemInTesta(struct elem *top, struct elem *p);
void stampaLista(struct elem *top);
void stampaListaR1(struct elem *top);
void stampaListaR2(struct elem *top);


int main(){
	int n,i,k;
	struct elem *top=NULL;
	printf("Quanti elementi vuoi inserire:");
	scanf("%d",&n);
	for (i=0;i<n;++i) {
		printf("Dammi l'elemento da inserire:");
		scanf("%d",&k);
		top=insInOrdineR(top,k);
	}
	stampaListaR1(top);
	stampaListaR2(top);
return 0;
}

//P(n)= Ho una lista di n elementi ed un puntatore p ad un
//elemento e voglio mettere p in testa
struct elem *spostoElemInTesta(struct elem *top, struct elem *p){
	//P(n=0)
	struct elem *tmp;
	if (top!=NULL && p!=NULL) {
		if (p!= top) {
			//Soluzione per P(n-1)
			tmp= spostoElemInTesta(top->next,p);
			//Assumo che p è in testa alla nuova lista
			//tmp
			//Allora trovo soluzione per P(n)
			top->next=tmp->next;
			tmp->next=top;
			top=tmp;
		}
	} 
	
	
	
	return top;
}

struct elem *newElem(int k){
	struct elem *nuovo=NULL;
	nuovo=(struct elem *)malloc(sizeof(struct elem));
	nuovo->k=k;
	nuovo->next=NULL;
	return nuovo;
}

//Il problem P(n)= "Inserire il valore k in coda ad un lista di n elementi"
struct elem *insInOrdineR(struct elem *top, int k){
	// P(n) =Ho una lista ordinata (crescente) di n elementi e voglio
	// inserire un elemento k in modo tale che
	//la lista resti ordinata (sempre crescente).

	struct elem *tmp;
	//P(n=0)
	if (top==NULL) {
		top=newElem(k);
	} else {
		if (k< top->k) {
			//Risolvo banalmente senza chiamata
			//ricorsiva
			tmp=newElem(k);
			tmp->next=top;
			top=tmp;
		} else
		{
		//Problema P(n-1) lo so risovere:
		tmp=insInOrdineR(top->next,k);
		//Data la soluzione per P(n-1) risolvo per P(n)
		//Adesso, quindi, assumo che k è stato messo
		//nella posizione corretta nella lista senza il top,
		//cioe' top->next
		//Quindi:
		top->next=tmp;
		}
	}
	return top;
}
struct elem *insInOrdine(struct elem *top, int k){
	struct elem *nuovo=newElem(k);
	struct elem *prec,*curr;
	curr=top;
	prec=NULL;
	while (curr!=NULL && curr->k < k){
		prec=curr;
		curr=curr->next;
	}
	if (curr==NULL) {
		if (prec!=NULL) 
			prec->next=nuovo;
		else top=nuovo; 
	}
	else {
		if (prec!=NULL) {
			nuovo->next=curr;
			prec->next=nuovo;
		}
		else {
			nuovo->next=curr;
			top=nuovo;
		}
	}
	
	return top;
}

struct elem *insInCodaR(struct elem *top, int k){
	struct elem *tmp;
	//PASSO BASE (CASO SEMPLICE) n=0, corrisponde top==NULL
	if (top==NULL) {
		top=newElem(k);
	}
	//CASO RICORSIVO	
	else { //QUI sono con un problema ad n elementi (n non lo conosco,
		// so solo che n>0
		//Problema P(n-1)="Inserire Il valore k in coda ad una lista di n-1 elementi", assumo di saperlo risolvere
		tmp=insInCodaR(top->next,k);
		//All'uscita di questa chiamata ho inserito l'elemento
		//k in coda nella lista senza il primo elemento
		//Tale nuova lista è in tmp
		//Data la soluzione (tmp) per il problema con n-1 elementi
		//Risolvo il problema con n elementi:
		top->next=tmp; 
		///Piu' semplicemente:
		//top->next=insInCoda(top->next,k);
	}
	
	return top;
}
void stampaLista(struct elem *top){
	while (top) {
		printf("%d -->",top->k);
		top=top->next;
	}
	printf("NULL\n");
}

void stampaListaR1(struct elem *top){
	if (top==NULL) {
		printf("NULL\n");
	}
	else {
		printf("%d -->", top->k);
		stampaListaR1(top->next);
	}
}
void stampaListaR2(struct elem *top){
	if (top==NULL) {
		printf("NULL ");
	}
	else {
		stampaListaR2(top->next);
		printf("<-- %d ", top->k);
		
	}

}

