/*Scrivere un programma che memorizzi in un array n numeri interi. Dopodichè
calcoli il valore medio ed elimini dall’array tutti gli elementi minori del valore
medio. Stampi a video l’array così ottenuto.*/
#include <stdio.h>
#define MAXLEN 100

int leggiNumeri(int a[]);
float valoreMedia(int a[], int n);
int eliminaElementi(int a[],int n, int m); 
void stampaElementi(int a[], int n);

int main(){
int a[MAXLEN];
int n;
float m;
n=leggiNumeri(a);
//n rappresenta il numero effettivo di elementi inseriti (presenti nell'array)
//MAXLEN e' la capacità massima dell'array.
m=valoreMedia(a, n);
n= eliminaElementi(a,n,m);
stampaElementi(a, n);

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

float valoreMedia(int a[], int n){
	float m=0;
	int i;
	for (i=0;i<n;++i) m += a[i];
	m=m/n;
	return m;
}
void shiftLeft(int a[],int n,int i);
int eliminaElementi(int a[],int n, int m){
	int i=0;
	while (i<n) {
		if (a[i]<m) {
			shiftLeft(a,n,i);
			n=n-1; // --n;
		}
		else ++i;
	}
	return n;
} 

void shiftLeft(int a[],int n,int i){
	int j;
	for (j=i; j < n-1;++j)
		a[j]=a[j+1];
}

void stampaElementi(int a[], int n){
	int i;
	for (i=0;i<n;++i)
		printf("a[%d]=%d\n",i,a[i]);
}

