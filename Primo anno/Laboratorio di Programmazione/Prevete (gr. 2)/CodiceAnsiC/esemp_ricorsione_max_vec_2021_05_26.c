//Dato un array di n elementi interi, calcolare il massimo
#include <stdio.h>
#define MAXELEM 50
int riempiArray(int a[]);
int calcolaMassimo(int a[], int n);
int calcolaMassimo2(int a[], int n);

int main() {
	int a[MAXELEM];
	int n,m,m2;
	n=riempiArray(a);
	if (n>0) {
		m=calcolaMassimo(a,n);
		m2=calcolaMassimo2(a,n);
	
		
	printf("Il massimo e':%d %d\n",m,m2);
	}
	else printf("Non ho elementi!\n");
	return 0;
}

int riempiArray(int a[]){
	int n,i;
	printf("Dammi il numero di elementi:");
	scanf("%d",&n);
	for (i=0;i<n;++i) {
		printf("Dammi a[%d]=",i);
		scanf("%d",&a[i]);
	}
	return n;
}
//PRECONDIZIONE: n>0
//a è l'array, n è il numero di elementi nell'array
int calcolaMassimo(int a[], int n){
	int m;
	if (n==1) {
		m=a[0];
	}
	else {
		//SUPPONGO di Avere la soluzione per lo stesso problema
		//ma con un elemento in meno,  P(n-1)
		//Ad esempio, tolgo l'ultimo elemento
		m=calcolaMassimo(a,n-1);
		//m è il massimo tra tutti gli elementi, eccetto l'ultimo a[n-1]
		//Quindi prendo m e costruisco la soluzione per P(n)
		if (a[n-1]>m) m=a[n-1];
		//Questo m è il massimo tra tutti gli elementi!!!!!
	}
	return m;
}
//PRECONDIZIONE: n>0
//a è l'array, n è il numero di elementi nell'array
int calcolaMassimo2(int a[], int n){
	int m;
	if (n==1) m=a[0];
	else {
		//SUPPONGO di Avere la soluzione per lo stesso problema
		//ma con un elemento in meno,  P(n-1)
		//Ad esempio, tolgo il primo elemento
		m=calcolaMassimo2(&a[1],n-1);
		//m è il massimo tra tutti gli elementi, eccetto il primo
		//Quindi prendo m e costruisco la soluzione per P(n)
		if (a[0]>m) m=a[0];
		//Questo m è il massimo tra tutti gli elementi!!!!!
	}
	return m;
}
