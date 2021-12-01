#include <stdio.h>
#include <stdlib.h>
#include <time.h>



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
	
	int n = 9;
	time_t Tin, Tfn;
	
	Tin = time(NULL);
	printf("Imprimindo sequencia de Fibonacci recursivo %d\n", fiboR(n));
	Tfn = time(NULL);
	printf("\tTempo em segundos : %fn\n\n", difftime(Tin, Tfn));
	return 0;
}

