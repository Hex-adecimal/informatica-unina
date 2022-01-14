/*
 fatttorian di n, con n >=0, che in genere è indicato con n! risulta essere
 n!= 1 se n==0, oppure n!=n * (n-1)! altrimenti
*/

#include <stdio.h>
#define MAXLEN 10
int fatt(int n);
//Funzione fattoriale di debug
int fatt_debug(int n);
int main() {
	int n,res;
	printf("Dammi un numero intero maggiore o uguale a zero:");
	scanf("%d",&n);
	//res=fatt(n);
	res=fatt_debug(n);
	printf("Fattoriale uguale a: %d\n",res);
	return 0;
}

int fatt(int n){
	int res=1;
	int res_piu_piccolo;
	if (n==0) //Passo base: risolvo il problema direttamente e 
		  // "facilmente"
		res=1; 
	else   //Passo ricorsivo
		{
		//Prendo la soluzione dello stesso problema, ma di
		// dimensioni più piccole, cioè n-1
		res_piu_piccolo=fatt(n-1);
		//res_piu_piccolo è il fattoriale di (n-1), cioè il //
		// prodotto (n-1)*(n-2)*.....*1
 		// Risolvo il problema con dimensione n, sulla base
		// (usando) la soluzione del problema più piccolo
		res= n *res_piu_piccolo; //QUesta è la chiave della 
					 // ricorsione!!!!!!!!!!  
		//res= n*(n-1)*(n-2)*.....*1, quindi 
		//res e' il fattoriale di n			 
		}
return res;
}		

//Altro esempio:

int massimoR(int a[],int n) {
	int res=0;
	int max;
	if (n=1) res=a[0];
	else
	{
		max=massimoR(a,n-1);
		if (a[n-1]>max) res=a[n-1]; 
			else res=max;
	}
	
return res;	
}


int fatt_debug(int n){
	int res=1;
	int ferma; //Variabile di appogio
	if (n==0){ //Passo base: risolvo il problema direttamente e 
		  // "facilmente"
		res=1;
		printf("CASO BASE n:%d  res:%d \n",n,res);
		printf("Vai avanti?");
		scanf("%d",&ferma);
	}  
	else   //Passo ricorsivo
	{
	printf("CASO ricorsivo prima della chiamata ricorsiva n:%d  res:%d \n",n,res);
	printf("Vai avanti?");
	scanf("%d",&ferma);	
	res= n *  fatt_debug(n-1);
	printf("CASO ricorsivo dopo la chiamata ricorsiva n:%d  res:%d \n",n,res);
	printf("Vai avanti?");
	scanf("%d",&ferma);

	}	
return res;
}		


