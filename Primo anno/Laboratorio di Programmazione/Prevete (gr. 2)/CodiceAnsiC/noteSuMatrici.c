/*Alcune note sulla creazione di matrici in maniera automatica e dinamica*/
#include <stdio.h>
#include <stdlib.h> //Da includere se uso malloc o calloc
#define MAXR 10
#define MAXC 10
//Creazione matrici dinamiche (tre modi diversi)
int **creaMatriceDinamica1(int r,int c);
int **creaMatriceDinamica2(int r,int c);
int *creaMatriceDinamica3(int r,int c);

//Esempio riempimento matrice automatica
void riempiMatrice(int M[][MAXC], int *pr,int *pc);
//Esempio riempimento matrice dinamica
void riempiMatriceDinamica1(int **M, int maxR,int maxC,int *pr,int *pc);
void riempiMatriceDinamica2(int **M, int maxR,int maxC,int *pr,int *pc);
void riempiMatriceDinamica3(int *M, int maxR,int maxC,int *pr,int *pc);

//Esempio stampa di una matrice automatica
void stampaMatrice(int M[][MAXC], int r,int c);
//Esempio stampa di una matrice dinamica (tre modi diversi, uno per ogni tipo di matrice)
void stampaMatriceDinamica1(int **M, int r,int c);
void stampaMatriceDinamica2(int **M,int r,int c);
void stampaMatriceDinamica3(int *M,int r,int c);

//Liberare memoria per una matrice dinamica (tre modi diversi, uno per ogni tipo di matrice)
void liberaMatriceDinamica1(int **M, int r);
void liberaMatriceDinamica2(int **M);
void liberaMatriceDinamica3(int *M);


int main(){
	int r,c,maxR,maxC;
	int M[MAXR][MAXC]; //CREAZIONE MATRICE IN MEMORIA AUTOMATICA
	int **M1,**M2;
	int *M3;
	/* //PER CAPIRE COME E' ORGANIZZATO M
	//UN UNICO ARRAY di rxc elementi. M definito come un 
	//puntatore ad una array di MAXC elementi
	for (r=0;r<MAXR;++r)
		printf("r=%d M value:%p &M[r][0]=%p M[r]=%p \n",r, M, &M[r][0],M[r]);
	//Con l'algebra dei puntatori mi sposto di MAXC blocchi alla volta
	for (r=0;r<MAXR;++r)
		printf("%p %p\n", M+r,&M[r][0]);

			/*
			*/
	printf("Matrice memoria automatica:\n");
	riempiMatrice(M, &r,&c); //r e c manterranno le effettive dimensioni della matrice
	stampaMatrice(M,r,c);
	printf("Dammi i valori di maxR e maxC per le matrici dinamiche:");
	scanf("%d %d",&maxR,&maxC);

	printf("Matrice memoria dinamica 1\n");
	M1=creaMatriceDinamica1(maxR,maxC);
	riempiMatriceDinamica1(M1,maxR,maxC,&r,&c);
	stampaMatriceDinamica1(M1,r,c);
	liberaMatriceDinamica1(M1, r);

	printf("Matrice memoria dinamica 2\n");	
	M2=creaMatriceDinamica2(maxR,maxC);
	riempiMatriceDinamica2(M2, maxR,maxC,&r,&c);
	stampaMatriceDinamica2(M2,r,c);
	liberaMatriceDinamica2(M2);

	printf("Matrice memoria dinamica 3\n");	
	M3=creaMatriceDinamica3(maxR,maxC);
	riempiMatriceDinamica3(M3, maxR,maxC,&r,&c);
	stampaMatriceDinamica3(M3,r,c);
	liberaMatriceDinamica3(M3);

	
return 0;
}

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

void riempiMatrice(int M[][MAXC], int *pr,int *pc){
	int r,c,i,j;
	printf("Quante righe vuoi inserire? (max r:%d):",MAXR);
	scanf("%d",&r);
	printf("Quante colonne vuoi inserire? (max c:%d)",MAXC);
	scanf("%d",&c);
	if (r>MAXR) r=MAXR;
	if (c>MAXC) c=MAXC;
	
	for (i=0;i<r;++i)
		for (j=0;j<c;++j) M[i][j]=i*c+j;
	*pr=r; // Con *pr accedo al contenuto della variabile puntata da pr
	*pc=c;
}
void riempiMatriceDinamica1(int **M, int maxR,int maxC,int *pr,int *pc){

	int r,c,i,j;
	printf("Quante righe vuoi inserire? (max r:%d):",maxR);
	scanf("%d",&r);
	printf("Quante colonne vuoi inserire? (max c:%d)",maxC);
	scanf("%d",&c);
	if (r>maxR) r=maxR;
	if (c>maxC) c=maxC;
	for (i=0;i<r;++i)
		for (j=0;j<c;++j)
			//M[i] e' un puntatore alla i-sima riga della matrice 
			//Puo' essere visto come il nome del array corrispondente alla i-sima riga
			M[i][j]=i*c+j;
	*pr=r;
	*pc=c;

}
void riempiMatriceDinamica2(int **M, int maxR,int maxC,int *pr,int *pc){
	int r,c,i,j;
	printf("Quante righe vuoi inserire? (max r:%d):",maxR);
	scanf("%d",&r);
	printf("Quante colonne vuoi inserire? (max c:%d)",maxC);
	scanf("%d",&c);
	if (r>maxR) r=maxR;
	if (c>maxC) c=maxC;
	for (i=0;i<r;++i)
		for (j=0;j<c;++j)
			M[i][j]=i*c+j;
	*pr=r;
	*pc=c;

}
void riempiMatriceDinamica3(int *M, int maxR,int maxC,int *pr,int *pc){
	int r,c,i,j;
	printf("Quante righe vuoi inserire? (max r:%d):",maxR);
	scanf("%d",&r);
	printf("Quante colonne vuoi inserire? (max c:%d)",maxC);
	scanf("%d",&c);
	if (r>maxR) r=maxR;
	if (c>maxC) c=maxC;
	for (i=0;i<r;++i)
		for (j=0;j<c;++j)
			M[i*c+j]=i*c+j;
	*pr=r;
	*pc=c;

}

void stampaMatrice(int M[][MAXC], int r,int c){
	int i,j;
	for (i=0;i<r;++i){
		printf("\n");	
		for (j=0;j<c;++j)
			printf("M[%d][%d]= %d ",i,j,M[i][j]);
	}
	printf("\n");		

}

void stampaMatriceDinamica1(int **M, int r,int c){
	int i,j;
	for (i=0;i<r;++i){
		printf("\n");	
		for (j=0;j<c;++j)
			printf("M[%d][%d]= %d ",i,j,M[i][j]);
	}
	printf("\n");		

}
void stampaMatriceDinamica2(int **M,int r,int c){
	int i,j;
	for (i=0;i<r;++i){
		printf("\n");	
		for (j=0;j<c;++j)
			printf("M[%d][%d]= %d ",i,j,M[i][j]);
	}
	printf("\n");		

}
void stampaMatriceDinamica3(int *M,int r,int c){
	int i,j;
	for (i=0;i<r;++i){
		printf("\n");	
		for (j=0;j<c;++j)
			printf("M[%d][%d]= %d ",i,j,M[i*c+j]);
	}
	printf("\n");		

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

