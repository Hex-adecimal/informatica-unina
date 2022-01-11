#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char mat[12][100];
    int i, r;
	
    strcpy(mat[0], "I concetti di algoritmo, funzione calcolabile e parzialmente calcolabile.");
    strcpy(mat[1], "Funzioni primitive ricorsive. La minimalizzazione. Funzioni parziali ricorsive.");
    strcpy(mat[2], "Numerazioni di Goedel. Macchina universale. Tesi di Church-Turing.");
    strcpy(mat[3], "Indecidibilità. Insiemi ricorsivi e ricorsivamente numerabili.");
    strcpy(mat[4], "Macchine di Turing.");
    strcpy(mat[5], "Automi finiti e macchine sequenziali. Automi non deterministici.");
    strcpy(mat[6], "Linguaggi regolari. Espressioni regolari.");
    strcpy(mat[7], "Pumping lemma per i linguaggi regolari.");
    strcpy(mat[8], "Grammatiche e linguaggi indipendenti dal contesto. Forma normale di Chomsky.");
    strcpy(mat[9], "Automi a pila. Corrispondenza tra macchine e grammatiche.");
    strcpy(mat[10], "Pumping lemma per i linguaggi indipendenti dal contesto.");
    strcpy(mat[11], "La gerarchia di Chomsky.");
    
    printf("1 Si 0 No\n");
    printf("Iniziare ?:");
    scanf("%d", &i);
    
    while(i == 1)
    {
    	srand(time(0));
	    r = rand() % 12;
	    puts(mat[r]);
	    
	    printf("Continuare ?:");
    	scanf("%d", &i);
	}
    
    return 0;
}
