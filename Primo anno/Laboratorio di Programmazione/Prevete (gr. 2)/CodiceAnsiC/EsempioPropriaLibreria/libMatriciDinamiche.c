#include <stdlib.h>
#include "matriciDinamiche.h"

int **creaMatriceDinamica1(int r,int c){
	int i;
	int **M;
	M= (int **) malloc(r*sizeof(int *));
	for (i=0;i<r;++i) M[i]= (int *)malloc(c*sizeof(int));
	// In maniera equivalente, con l'unica differenza che inizializzo a zero
	// tutti gli elementi:
	//for (i=0;i<r;++i) A[i]= (int *)calloc(c,sizeof(int));
	return M;
}

int **creaMatriceDinamica2(int r,int c){
	int i;
	int *V= (int *)malloc(r*c*sizeof(int));
	// In maniera equivalente, con l'unica differenza che inizializzo a zero
	// tutti gli elementi:
	// int *V= (int *)calloc(r*c,sizeof(int));
	int **M=(int **) malloc(r*sizeof(int *));
	for (i=0;i<r;++i) M[i]= &V[i*c];
	return M;
}
int *creaMatriceDinamica3(int r,int c){
	int i;
	int *M= (int *)malloc(r*c*sizeof(int));
	// In maniera equivalente, con l'unica differenza che inizializzo a zero
	// tutti gli elementi:
	// int *M= (int *)calloc(r*c,sizeof(int));
	return M;
}

void liberaMatriceDinamica1(int **M, int r){
	int i;
	for (i=0;i<r;++i) free(M[i]);
	free(M);
}

void liberaMatriceDinamica2(int **M){
	int i;
	free(M[0]);
	free(M);
}
void liberaMatriceDinamica3(int *M){
	free(M);
}

