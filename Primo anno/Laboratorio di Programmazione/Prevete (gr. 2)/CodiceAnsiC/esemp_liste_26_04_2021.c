#include <stdio.h>
#include <stdlib.h>

struct elem {
	int k;
	struct elem *next;
};

struct elem *insElemInTesta(struct elem *top,int k);
struct elem *insElemInCoda(struct elem *top,int k);
struct elem *insElemInMezzo(struct elem *top,struct elem *pre,int k);
struct elem *eliminaLista(struct elem *top);
struct elem *cercaElemento(struct elem *top,int k);
//In effetti serve solo il precedente!!
struct elem *eliminaElem(struct elem *top, struct elem *pre);

int main(){
	int k;
	struct elem *top; //NON E' CREATA LA LISTA
	
	top=NULL; //CREO UNA LISTA NULLA, VUOTA!!!!!
	
	top=insElemInTesta(top,k); //QUI, CON L'ASSEGNAZIONE, CAMBIA EFFETTIVAMENTE IL TOP
				   //	DELLA LISTA
	top=insElemInCoda(top,k); //SE CAMBIA IL TOP, VIENE CAMBIATO QUI!!! 
	
	top=eliminaLista(top);
	
return 0;
}
//PRE-CONDIZIONE: l'elemento da eliminare sia sempre diverso da NULL
struct elem *eliminaElem(struct elem *top, struct elem *pre){
	struct elem *c;
	if (pre==NULL) {
		c=top;
		top=top->next;
		free(c);
	} else {
		c= pre->next;
		pre->next=c->next;
		free(c);
	}
	return top;
}

struct elem *nuovoElemento(int k){
	struct elem *nuovo= (struct elem *)malloc(sizeof(struct elem));
	nuovo->k=k;
	nuovo->next=NULL;
	return nuovo;
}
struct elem *insElemInTesta(struct elem *top,int k){
	struct elem *nuovo= nuovoElemento(k);
	nuovo->next=top;
	return nuovo;
}
struct elem *insElemInCoda(struct elem *top,int k){
	struct elem *nuovo= nuovoElemento(k);
	if (top==NULL) return nuovo;
	struct elem *curr=top;
	while (curr->next!=NULL) curr=curr->next; //SEMPRE SICURO CHE curr E' DIVERSO DA NULL
	curr->next=nuovo;
	return top;
}
//pre è l'analogo dell'indice negli array
struct elem *insElemInMezzo(struct elem *top,struct elem *pre,int k){
	struct elem *nuovo= nuovoElemento(k);
	if (pre==NULL) {
		nuovo->next=top;
		top=nuovo;
	}
	else {
		nuovo->next=pre->next;
		pre->next=nuovo;
	}
	return top;
}
struct elem *eliminaLista(struct elem *top){
	struct elem *c;
	while (top != NULL){
		c=top;
		top=c->next;
		free(c);		
	}
	return top;
}
// --Se il puntatore restituito punta a NULL, l'elemento cercato è in testa (la testa
//  potrebbe essere NULL)
// -- Se il puntatore restituito,p, è diverso da NULL, l'elemento cercato si trova come
//    next, p->next (p->next potrebbe essere NULL, se non trovo l'elemento)
struct elem *cercaElemento(struct elem *top,int k){
	struct elem *pre=NULL, curr=top;
	 //SCORRO LA LISTA SE SONO SU UN ELEMENTO DIVERSO DA NULL E NON HO
	// TROVATO k!!!
	while (curr !=NULL && curr->k!=k) {
		 pre=curr;
		 curr=curr->next;
	}
	/* COSI' NON VA BENE
	while (curr->k!=k && curr !=NULL ) {
		 pre=curr;
		 curr=curr->next;
	}
	*/
	return pre;
}

