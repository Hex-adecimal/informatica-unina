/*
Scrivere un programma che riceva in input due stringhe s1 e s2 e stampi a video se la stringa s1 è una sottostringa di s2 sono oppure no. Ad esempio se s1=”ala” e s2=”calamaro” allora s1 è una sottostringa di s2. Se s1=”ala” e s2= “calma”, allora s1 non è una sottoscritta di s2.
*/
#include <stdio.h>
#define MAXSTR 100  //Lunghezza massima di una stringa

//DICHIARO LE FUNZIONI CHE MI SERVONO NEL MAIN (PROTOTIPI)
void leggiStringhe(char s1[],char s2[]); //Leggo i dati
int verificaSottostringa(char s1[],char s2[]); //Operazioni da svolgere
void stampaRisultato(int ris,char s1[],char s2[]); //Stampo il risultato
int main(){
	char s1[MAXSTR], s2[MAXSTR]; //STUTTURE DATI DOVE MEMORIZZARE I DATI
	int ris=0;
	printf("PARAMETRO ATTUALE: Indirizzo di memoria di s1=%p e suo valore=%p\n", &s1,s1);
	leggiStringhe(s1,s2); //Leggo i dati
	ris=verificaSottostringa(s1,s2); //Operazioni da svolgere
	printf("Indirizzo memoria di ris del main (parametro attuale):%p\n",&ris);
	stampaRisultato(ris,s1,s2); //Stampo il risultato
return 0;
}

void leggiStringhe(char s1[],char s2[]){
	printf("Dammi la prima stringa:");
	scanf("%s",s1); //scanf("%s",&s1[0]);
	printf("Dammi la seconda stringa:");
	scanf("%s",s2); //scanf("%s",&s1[0]);
}

//VERIFICO SE E' UNA SOTTOSTRINGA A PARTIRE DALLA CONDIZIONE CHE IL CARATTERE
//PRECEDENTE E' UGUALE
int subStr(char s1[],char s2[],int c1,int c2){
	//s1="ala" s2="camalaro"
	int ris=0;
	
	//CONFRONO SE IN SEQUENZA I CARATTERI SONO TUTTI UGUALI
	while ((s1[c1]!='\0' && s2[c2]!='\0') && (s2[c2]==s1[c1])) {
			++c1;
			++c2;
	}
	//S1 e' una sottostringa se sono arrivato alla fine di S1
	if (s1[c1]=='\0') ris=1;		
	 
	return ris;
}

int verificaSottostringa(char s1[],char s2[]){
	int ris=0;
	int c1=0,c2=0;
	while ( ris==0 && s2[c2]!='\0'){
		while (s2[c2]!='\0' && s1[c1]!=s2[c2]) ++c2;
		if (s2[c2]!='\0') ris= subStr(s1,s2,c1+1,c2+1);
		++c2;
	}
	return ris;
}


void stampaRisultato(int ris,char s1[],char s2[]){
	printf("La stringa: %s\n",s1);
	if (ris==1) printf("E' sottostringa della\n");
	else printf("NON e' sottostringa della\n");
	printf("stringa: %s\n",s2);
}
