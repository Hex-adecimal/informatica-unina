#include <stdio.h>
#define MAXLEN 50
int main(){
char nomeFile[MAXLEN],c;


FILE *fp; //fp è il puntatore ad una stream, ma lo stream non e' creato
//Quando creo (apro) lo stream devo specificare se apro in lettura, 
// scrittura o entrambe le cose
//VEDIAMO PRIMA in lettura:
printf("Dammi il nome del file da leggere:");
scanf("%s",nomeFile); 
//fscanf(stdin,"%s",nomeFile); 
fp=fopen(nomeFile,"r");
if (fp!=NULL) {//Ho trovato il file da leggere e creato lo stream
	//Leggo carattere per carattere 
	while (fscanf(fp,"%c",&c)>0) {
		printf("%c",c);
		}
	//ALLA FINE DI TUTTE LE OPERAZIONI, DEVO CHIUDERE LO tream
	fclose(fp);	
}
else { //NON HO TROVATO IL FILE DA LEGGERE O C'E' STATO UN ERRORE IN 
       //APERTURA
       printf("FILE NON TROVATO!!");
}
return 0;
}
