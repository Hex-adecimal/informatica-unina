//SCHEDARIO
#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 1000
#define MAXS 20

struct schedaPersona {
	char cognome[MAXS];
	char nome[MAXS];
	char luogoDiNascita[MAXS];
	int eta;
	float reddito;
};

int inseriscoPersona(struct schedaPersona **schedario, int n);
int eliminaPersona(struct schedaPersona **schedario,int n, int i);
void modificaPersona(struct schedaPersona **schedario,int n, int i);
int trovaPersoneCognome(struct schedaPersona **schedario,int n,char *cog);
void stampaArray(struct schedaPersona **schedario,int n);
int main() {
	int flag;
	struct schedaPersona *schedario[MAXLEN]; //Array di puntatori a struct schedaPersona
				
	int nPersone=0; int i;
	char cog[MAXS];
	for (i=0;i<MAXLEN;++i) schedario[i]=NULL;
	do {
		printf("Cosa vuoi fare? 0: esci, 1: inserisci, 2: elmina 3:modifica 4:stampa");
		scanf("%d",&flag);
		switch (flag) {
			case 1: nPersone=inseriscoPersona(schedario,nPersone);
				break;
			case 2: printf("Dammi il cognome della persona da eliminare");
				scanf("%s",cog);
				i=trovaPersoneCognome(schedario,nPersone,cog); 
				if (i>=0)
					nPersone=eliminaPersona(schedario,nPersone,i);
				break;
			case 3:
				printf("Dammi il cognome della persona da modificare");
				scanf("%s",cog);
				i=trovaPersoneCognome(schedario,nPersone,cog); 
				if (i>=0)
					modificaPersona(schedario,nPersone,i);
				break;
			case 4: stampaArray(schedario,nPersone);	
		}
	} while (flag>0);	
return 0;
}

struct schedaPersona *creoPersona();
int inseriscoPersona(struct schedaPersona **schedario, int n){
	schedario[n]=creoPersona();
	n=n+1;
	return n;
}

struct schedaPersona *creoPersona(){
	struct schedaPersona *s=(struct schedaPersona *)malloc(sizeof(struct schedaPersona));
	printf("Dammi il cognome:");
	scanf("%s",s->cognome);
	printf("Dammi il nome:");
	scanf("%s",s->nome);
	printf("Dammi l'eta':");
	scanf("%d",&(s->eta));
	printf("Dammi il luogo di nascita:");
	scanf("%s",s->luogoDiNascita);
	printf("Dammi il reddito:");
	scanf("%f",&(s->reddito));		
	return s;
}

int eliminaPersona(struct schedaPersona **schedario,int n, int i){
	return n;
}
void modificaPersona(struct schedaPersona **schedario,int n, int i){
}

int trovaPersoneCognome(struct schedaPersona **schedario,int n,char *cog){
	return n;
}
void stampaArray(struct schedaPersona **schedario,int n){
	int i;
	for (i=0;i<n;++i) {
		printf("Cognome:%s Nome:%s Eta:%d Luogo:%s Reddito:%f\n",schedario[i]->cognome, schedario[i]->nome,schedario[i]->eta,schedario[i]->luogoDiNascita,schedario[i]->reddito);
	}
	
}
