//SCRIVERE IN UN FILE E POI LEGGERE DA TALE FILE
//SCRIVO UNA SEQUENZA DI INTERI NEL FILE, UN INTERO su ogni riga.
//DOPODICHE' LI LEGGO E LI STAMPO A VIDEO
#include <stdio.h>
#define MAXLEN 20

void scriviSuFile(FILE *fp);
void leggiDaFile(FILE *fp);

int main(){
	FILE *fp;
	int n,i,k;
	char nomeFile[MAXLEN];
	printf("Dammi il nomme del file:");
	scanf("%s",nomeFile);
	fp=fopen(nomeFile,"w"); //APRO IN SCRITTURA. Se esiste lo cancello. Se non esiste lo 
				//creo nuovo
//	fp=fopen(nomeFile,"a");//APRO IN SCRITTURA. Se esiste non lo cancello. 
				//Se non esiste lo creo nuovo
				//Scrivo a partire dalla fine del file
	if (fp!=NULL) {
		scriviSuFile(fp);
		//rewind(fp);
		fprintf(fp," \n %d \n ",100);
		fclose(fp);
	
		fp=fopen(nomeFile,"r");
		if (fp!=NULL) {
			leggiDaFile(fp);
			fclose(fp);
		}
		else printf("Non sono riuscito ad aprire il file in lettura\n");
	}
	else {
		printf("Problema apertura file in scrittura!\n");
	}


		
}
//SUPPONGO CHE IL CONTROLLO SU fp !=NULL sia già stato fatto
void scriviSuFile(FILE *fp){
		int i,n,k;
		printf("Quanti interi vuoi scrivere?");
		scanf("%d",&n);
		for (i=0;i<n;++i) {
			printf("Dammi il valore da scivere su file:");
			scanf("%d",&k);
			fprintf(fp,"%d ",k);
		}

}


void leggiDaFile(FILE *fp){
	int k;
	while (fscanf(fp,"%d",&k)>0) 
		printf("%d\n",k);

}

