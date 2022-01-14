//SCRIVERE IN UN FILE E POI LEGGERE DA TALE FILE
//SCRIVO UNA SEQUENZA DI INTERI NEL FILE, UN INTERO su ogni riga.
//DOPODICHE' LI LEGGO E LI STAMPO A VIDEO
#include <stdio.h>
#define MAXLEN 20



int main(){
	FILE *fp;
	int n,i,k;
	char nomeFile[MAXLEN];
	printf("Dammi il nomme del file:");
	scanf("%s",nomeFile);
	//fp=fopen(nomeFile,"w"); //APRO IN SCRITTURA. Se esiste lo cancello. Se non esiste lo 
				//creo nuovo
	fp=fopen(nomeFile,"a");//APRO IN SCRITTURA. Se esiste non lo cancello. 
				//Se non esiste lo creo nuovo
				//Scrivo a partire dalla fine del file
	if (fp!=NULL) {
		printf("Quanti interi vuoi scrivere?");
		scanf("%d",&n);
		for (i=0;i<n;++i) {
			printf("Dammi il valore da scivere su file:");
			scanf("%d",&k);
			fprintf(fp,"%d ",k);
		}
		
		fclose(fp);
	
		fp=fopen(nomeFile,"r");
		if (fp!=NULL) {
			while (fscanf(fp,"%d",&k)>0) 
				printf("%d\n",k);
			fclose(fp);
		}
		else printf("Non sono riuscito ad aprire il file in lettura\n");
	}
	else {
		printf("Problema apertura file in scrittura!\n");
	}


		
}
