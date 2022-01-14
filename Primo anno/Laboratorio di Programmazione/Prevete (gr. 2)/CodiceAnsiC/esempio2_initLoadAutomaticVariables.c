//Importanza della inizializzazione di una variabile.
//Verifica sperimentale che le variabile automatiche sono caricate in memoria
//quando il loader carica il programma in memoria 
#include <stdio.h> /*header file: aggiungo, includo, il file di testo stdio.h all'inizio
			di questo file*/
void fun(int);

int main() {
	int x;
	printf("Dammi x:");
	scanf("%d",&x); //x=1, x=2
	fun(x);
	printf("Dammi x:"); 
	scanf("%d",&x);//x=2, x=1
	fun(x);
return 0;
}


void fun(int x){
//La variabile a non e' inizializzata!!!
	int a;
	printf("indirizzo a:%p", &a);
	if (x==1) a=10; else a=a+1;
		printf("a:%d\n",a); //x=1,Stampo 10, x=2,Stampo 11
				    //x=2, Stampo ???, x=1, Stampo 10
}
