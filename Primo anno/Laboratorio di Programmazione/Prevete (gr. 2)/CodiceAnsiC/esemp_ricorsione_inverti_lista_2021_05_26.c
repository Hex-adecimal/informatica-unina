// Data una lista semplicemente concatenata di interi, voglio invertirla, cioè
//il primo elemento diventa l'ultimo, il secondo il penultimo e così via. 

#include <stdio.h>
#include <stdlib.h>
struct elem {
	int k;
	struct elem *next;
};

struct elem *riempiLista();
struct elem *cancellaMinoriDik(struct elem *top,int k);
struct elem *cancellaElementok(struct elem *top,int k);
struct elem *invertiLista(struct elem *top);

void stampaLista(struct elem *top);
int main(){
	struct elem *top;
	int k;
	top=riempiLista();
	stampaLista(top);
	printf("Dammi k:");
	scanf("%d",&k);
	top=cancellaMinoriDik(top,k);
	stampaLista(top);
return 0;
}
struct elem *riempiLista(){
	struct elem *top=NULL;
	return top;
}
//P(n)=Eliminare da un lista semplicemente concatenata di dimensione n,
// tutti gli elementi mionori di un dato k

struct elem *cancellaMinoriDik(struct elem *top,int k){
	//CASO BASE, top==NULL, implicito
	struct elem *tmp;
	if (top!=NULL) {
		//ASSUMMO DI SAPER RISOLVERE IL PROBLEMA P(n-1), cioè
		//P(n)=Eliminare da un lista semplicemente concatenata di dimensione n-1,
		// tutti gli elementi mionori di un dato k
		//tmp mantiene la soluzione, cioè sarà il puntatore alla testa della
		//lista in cui sono stati eliminati gli elementi minori di k, 
		//ecceto la testa iniziale (top)
		tmp=cancellaMinoriDik(top->next,k);
		//ADESSO COSTRUISCO LA SOLUZIONE PER P(n)
		if (top->k<k) {
			free(top);
			top=tmp;
			}
		else top->next=tmp;
	}	
	return top;
}
void stampaLista(struct elem *top){
}

//P(n)= Data una lista di interi semplicemente concatenata e senza ripetizioni,
// con n elementi, Elimino un elemento di valore k, se esiste

struct elem *cancellaElementok(struct elem *top,int k){
	struct elem *tmp;
	//Passo base, top==NULL, implicito
	
	if (top!=NULL) {
		//Se è in testa devo solo cancellare la testa e non devo fare più nulla,
		// perchè è una lista SENZA ripetizioni 
		if (top->k==k) {
			tmp=top->next;
			free(top);
			top=tmp;
		}
		else {
			//SUPPPONGO DI SAPER RISOLVERE IL PROBLEMA P(n-1) e mettere
			//la soluzione in tmp;
			tmp=cancellaElementok(tmp->next,k);
			//COSTRUISCO LA SOLUZIONE PER P(n);
			top->next=tmp;
		}
	}
	return top;
}
// P(n)=Data una lista semplicemente concatenata di n interi, voglio invertirla

struct elem *invertiLista(struct elem *top){
	//caso base implicito (top==NULL)
	struct elem *tmp,*curr;
	if (top!=NULL) {
		//Assumo che tmp contenga la soluzione per la lista senza la testa,
		//cioè la soluzione del problema P(n-1)=Data una lista semplicemente //
		//concatenata di n-1 interi, voglio invertirla 
		tmp=invertiLista(top->next);
		//COSTRUISCO LA SOLUZIONE PER P(n)
		if (tmp!=NULL) {
			curr=tmp;
			while (curr->next!=NULL) curr=curr->next;
			curr->next=top;
			top->next=NULL;
			top=tmp;
		}
	}
	return top;
}
