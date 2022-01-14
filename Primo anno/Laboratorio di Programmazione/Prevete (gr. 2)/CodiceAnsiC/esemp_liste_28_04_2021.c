#include <stdio.h>
#include <stdlib.h>
//SUPPONIAMO DI VOLER RISOLVERE IL SEGUENTE PROBLEMA:
// Eliminare un elenento da una lista semplicemente concatenata di valore k, se esiste.
//VERSIONE 1 di questo problema: la lista non contiene ripetizioni. Ogni valore i è presente 
//una sola volta nella lista: top--> 23 --> 18 --> 30 -->NULL 
// (E NON COSI': top --> 23 -->18-->23-->8-->NULL (in questo caso 23 si ripete) 
struct elem {
	int k;
	struct elem *next;
};

//Funzioni di servizio (precedentemente create)*****
struct elem *insElemInTesta(struct elem *top,int k);

struct elem *insElemInCoda(struct elem *top,int k);

struct elem *insElemInMezzo(struct elem *top,struct elem *pre,int k);
struct elem *eliminaLista(struct elem *top);
struct elem *cercaElemento(struct elem *top,int k);
//In effetti serve solo il precedente!!
//PRE-CONDIZIONE: l'elemento da eliminare sia sempre diverso da NULL
struct elem *eliminaElem(struct elem *top, struct elem *pre);
//*******************************
struct elem *riempiLista();
struct elem *eliminaKSenzaRipetizioni(struct elem *top,int k);
void stampaLista(struct elem *top);
int main(){
	int k;
	struct elem *top; //NON E' CREATA LA LISTA
	top=riempiLista();
	printf("Dammi l'elemento da cancellare:");
	scanf("%d",&k);
	top=eliminaKSenzaRipetizioni(top,k);
	stampaLista(top);
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
	struct elem *pre=NULL, *curr=top;
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
struct elem *riempiLista(){
	struct elem *top=NULL;
	int n,i,k;
	printf("Quanti elementi vuoi inserire?");
	scanf("%d",&n);
	for (i=0;i<n;++i) {
		printf("Dammi l'elemento %d:",i+1);
		scanf("%d",&k);
		top=insElemInTesta(top,k);
	}
	return top;
}
struct elem *eliminaKSenzaRipetizioni(struct elem *top,int k){
	struct elem *pre=NULL,*tmp;
	if (top!=NULL) {
		pre=cercaElemento(top,k);
		if (pre==NULL) {
			tmp=top;
			top=top->next;
			free(tmp);
		}
		else if (pre->next!=NULL) {
				//tmp è il nodo da eliminare
				tmp=pre->next;
				pre->next=tmp->next;
				free(tmp);
			}

	}
	/*VERSIONE CON CHIAMATA DI SOTTOFUNZIONE
	if (top!=NULL) {
		pre=cercaElemento(top,k);
		if (pre==NULL) top=eliminaElem(top,pre);
		else if (pre->next!=NULL)  top=eliminaElem(top,pre);
	}

	*/
	return top;
}
void stampaLista(struct elem *top){
	while (top!=NULL) {
		printf("%d -->",top->k);
		top=top->next;
	}
	printf("NULL\n");
}
