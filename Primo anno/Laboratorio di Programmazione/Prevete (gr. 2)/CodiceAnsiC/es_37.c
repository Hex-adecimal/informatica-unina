/*
Si supponga che in un file di testo siano memorizzati i valori di una matrice di interi di dimensione mxn, rispettando il seguente formato: sulla prima riga sono presenti i numeri m ed n, sulle successive m righe ci sono gli n numeri di ciascuna riga. Ad esempio:
2 3
12 0 -1
9 -8 5
Si scriva una funzione che legga tale file ed inserisca i valori presenti nel file in una matrice M creata dinamicamente. Scrivere un main che: 1) Chieda il nome del file di testo. 2) Legga il file, se esiste, e crei opportunamente la matrice M. 3) Stampi a video la matrice M ottenuta. 
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 50
int **leggiMatrice(FILE *fp,int *pm,int *pn);
void stampaMatrice(int **M,int m,int n);
void liberaMatrice(int **M, int m);
int main() {
	FILE *fp;
	char nomeFile[MAXLEN];
	int m=0,n=0;
	int **M;
	printf("Dammi il nome del file:");
	scanf("%s",nomeFile);
	fp=fopen(nomeFile,"r");
	if (fp!=NULL) {
		M=leggiMatrice(fp,&m,&n);
		if (M!=NULL) {
			stampaMatrice(M,m,n);	
			liberaMatrice(M,m);
		}
		fclose(fp);
	}
	else printf("Problemi con il file %s nella apertura in lettura!\n",nomeFile);
	
return 0;
}

int **leggiMatrice(FILE *fp,int *pm,int *pn){
	int **M=NULL,m=0,n=0,i,j,k;
	if (fscanf(fp,"%d %d",&m,&n)==2) {
		M =  (int **)malloc(m*sizeof(int *)); //alloco array di m puntatori
		for (i=0;i<m;++i)
			M[i]= (int *)malloc(n*sizeof(int)); //alloco array di n interi
		for (i=0;i<m;++i)
			for (j=0;j<n;++j){	
				fscanf(fp,"%d",&k);
				M[i][j]=k;	
				}
		*pm=m;
		*pn=n;
	}
	return M;
}
void stampaMatrice(int **M,int m,int n){
	int i,j;
	for (i=0;i<m;++i) {
		for (j=0;j<n;++j)
			printf("%d ",M[i][j]);
		printf("\n");
	}
}
void liberaMatrice(int **M, int m){
	int i;
	for (i=0;i<m;++i) free(M[i]);
	free(M);
}	
