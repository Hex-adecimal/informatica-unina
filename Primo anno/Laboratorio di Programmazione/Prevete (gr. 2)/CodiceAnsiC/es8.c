//Scrivere un programma che riceva in input una stringa e stampi a video 
//la lunghezza della stringa.
#include <stdio.h>
#define MAXLEN 100
int lenStr(char str[]);

int main() {
	char s[MAXLEN];
	
	int len;
	printf("Dammi una stringa:");
	scanf("%s",s);
	len=lenStr(s);
	printf("Lunghezza stringa:%d\n",len);
return 0;
}

//PRECONDIZIONE: str deve essere una stringa, cioe' array di caratteri 
//con carattere di fine stringhe
int lenStr(char str[]){
	int len=0;
	while (str[len]!='\0') len=len+1;
	return len;
}

