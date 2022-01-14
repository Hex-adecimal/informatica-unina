#include <stdio.h>
#define MAXLEN 100

void mergeSort(int A[], int n);


int main() {
	int V[MAXLEN];
	int n,i;
	printf("Quanti numeri:");
	scanf("%d",&n);
	for (i=0;i<n;++i) {
		printf("Dammi V[%d]=",i);
		scanf("%d",&V[i]);
	}
	mergeSort(V,n);
	for (i=0;i<n;++i) {
		printf("V[%d]=%d\n",i,V[i]);
	}
	
return 0;
}

void merge(int V[],int centro,int n);

void mergeSort(int V[], int n){
	//CASO BASE n=1, IMPLICITO
	if (n>1) {
		//DIVIDO IL PROBLEMA IN SOTTOPROBLEMI
		int centro=n/2;
		//TROVO LE SOLUZIONI DEI SOTTOPROBLEMI
		mergeSort(V, centro);
		mergeSort(&V[centro], n-centro);
		//COMBINO LE SOLUZIONI TROVATE
		merge(V,centro,n);
	}
}
void merge(int V[],int centro,int n){
	int *A, *B;
	int C[MAXLEN];
	int m1,m2; //m1 e m2 le dimensioni dei due vettori già ordinati
	m1=centro;
	m2=n-centro;
	int i=0,j=0,k=0;
	//I DUE ARRRAY A e B GIA' ORDINATI
	A=&V[0];
	B=&V[centro];
	
	while (i<m1 && j < m2) {
		if (A[i] < B[j]) {
			C[k]=A[i];
			i=i+1;
		}
		else {
			C[k]=B[j];
			j=j+1;
		}
		k=k+1;
	}
	//AL TERMINE DEL PRECEDENTE WHILE HO: O i>=m1 e j>=m2, OPPURE SOLO UNO E' maggiore 
	//O UGUALE 
	while ( i < m1) {
		C[k]=A[i];
		k=k+1;
		i=i+1;
	}
	
	while ( j < m2) {
		C[k]=B[j];
		k=k+1;
		j=j+1;
	}
	
	for (i=0;i<n;++i) V[i]=C[i];	
}

