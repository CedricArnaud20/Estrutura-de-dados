#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Definido como sera executado a sequencia 
int fiboR(int n){
	if (n == 1)
		return 0;
	else{
		if(n == 2)
			return 1;
		else
			return fiboR(n - 1)	+ fiboR(n - 2);
	}	
}
int main () {
	
	int n = 9; //variavel a ser iniciada na contagem
	time_t Tin, Tfn; //variavel para obter o tempo de execução
	
	Tin = time(NULL);
	printf("Imprimindo sequencia de Fibonacci recursivo %d\n", fiboR(n));  // impriindo resultado 
	Tfn = time(NULL);
	printf("\tTempo em segundos : %fn\n\n", difftime(Tin, Tfn)); // imprimindo tempode execução
	return 0;
}

