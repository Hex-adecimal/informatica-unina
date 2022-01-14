/*
Scrivere un programma che memorizzi in un array n numeri interi. Dopodichè
verifichi se l’elemento con indice i risulti sempre uguale alla somma degli
elementi con indici i-1 e i-2, più k. k è un valore ottenuto da tastiera. Se gli
elementi di indici i-1 e i-2 non esistono si assumono uguale a zero. Esempio:
k=1 [1 2 4 7 12]
k=3 [3 6 12 21 36]
*/
#include <stdio.h>

#define MAXLEN 100

int leggiNumeri(int a[]);
int verificaCondizione(int a[],int k,int n);
void stampa(int res);

int main(){
	int n,res,k;
	int a[MAXLEN];
	n=leggiNumeri(a);
	printf("Dammi k:");
	scanf("%d",&k);
	res=verificaCondizione(a,k,n);
	stampa(res);
return 0;
}

int leggiNumeri(int a[]){
	int flag=0, n=0;
	do {
		printf("vuoi inserire un altro numero? (SI=1,NO=0)");
		scanf("%d",&flag);
		//n < MAXLEN && flag==1 
		if (flag==1 && n < MAXLEN) {
			printf("Inserisci numero:");
			scanf("%d",&a[n]);
			++n;
		}
	} while (flag==1);
return n;
}

int verificaCondizione(int a[],int k,int n){
	int res=1,i=0, somma=0;
	while (res==1 && i<n) {
		if (i <1) somma=k;
		else if (i<2) somma=a[0]+k;
			else somma=a[i-1] + a[i-2] +k;
		
		if (a[i] != somma)
			res=0;
		else ++i;	
	}
	return res;
}
void stampa(int res){
	if (res==1) printf("Condizione verificata!!!\n");
	else printf("Condizione NON verificata!!\n");
}

