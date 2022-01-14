//Una variabile e' sempre definita da: un tipo, nome, un valore ed un indirizzo di memoria
#include <stdio.h> /*header file: aggiungo, includo, il file di testo stdio.h all'inizio
			di questo file*/
void fun(int);
int main() {
	int x=0;
	printf("x address: %p x value=%d\n",&x, x);
	//p --> x
	int *p=&x;
	printf("p address: %p p value=%p\n",&p, p);

	printf("Dammi x:");
	scanf("%d",&x);
	if (x>0) {
		int x=0;
		printf("Indirizzo nuovo x:%p\n",&x);
		//Ho nascosto l'accesso alla variabile x definita precedentemente
		*p=10;
	}
	printf("x address: %p x value=%d\n",&x, x);
return 0;
}

