#include <stdio.h>
#include <stdlib.h>
//SUPPONIAMO DI VOLER RISOLVERE IL SEGUENTE PROBLEMA:
// Eliminare un elenento da una lista semplicemente concatenata di valore k, se esiste.
//VERSIONE 2 di questo problema: la lista ncontiene ripetizioni. Ogni valore i può essere //
// presente più volte. 
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
struct elem *eliminaKConRipetizioni(struct elem *top,int k);

//Funzione che richiama altre funzioni già realizzate
struct elem *eliminaKConRipetizioni_2(struct elem *top,int k);
void stampaLista(struct elem *top);
int main(){
	int k;
	struct elem *top; //NON E' CREATA LA LISTA
	top=riempiLista();
	printf("Dammi l'elemento da cancellare:");
	scanf("%d",&k);
	//top=eliminaKConRipetizioni(top,k);
	top=eliminaKConRipetizioni_2(top,k);

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
struct elem *eliminaKConRipetizioni(struct elem *top,int k){
	struct elem *pre=NULL, *curr,*tmp;
	curr=top;
	while (curr!=NULL) {
		if (curr->k == k) {
			if (pre==NULL) { //ELEMENTO DA ELIMINARE E' IN TESTA
				tmp=curr;
				curr=curr->next;
				top=curr; //UNICO CASO IN CUI CAMBIA IL TOP DELLA LISTA
				free(tmp);
			}
			else {
				pre->next=curr->next;
				free(curr);
				curr=pre->next;
			}
		} 
		else {
		    pre=curr;
		    curr=curr->next;
		}
	}
	return top;
}


//Funzione che richiama altre funzioni già realizzate
struct elem *eliminaKConRipetizioni_2(struct elem *top,int k){
	struct elem *pre;
	int flag=1;
	while (top !=NULL && flag==1) {
		pre=cercaElemento(top,k); //QUI RICERCO SEMPRE DA TOP, E' DISPENDIOSO!!!
					  // COME MODIFICARE???
					  //ESERCIZIO DA FARE A CASA
		if (pre==NULL)
			top=eliminaElem(top,pre);
		else if (pre->next!=NULL)  top=eliminaElem(top,pre);
		else flag=0; //NON TROVO ELEMENTI, ESCO DA WHILE!!!!	
	}
	return top;
}

void stampaLista(struct elem *top){
	while (top!=NULL) {
		printf("%d -->",top->k);
		top=top->next;
	}
	printf("NULL\n");
}
