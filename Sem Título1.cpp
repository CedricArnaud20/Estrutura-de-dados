#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#define DIM 10
    int main()
{
    int x[DIM];
    int i, j, temp;
    /* Leitura do Vetor */
        for (i = 0; i<DIM; i++)
        {
        	x[i]=rand ()%DIM;
           //printf("Digite um numero\t:");
       // scanf("%d",&x[i]);
        }
        
     // listagem antes de ordenar
	 
	 printf("Numeros digitado \n");
	 
	 	printf("\n\n");
	 
	 for(i=0; i<DIM; i++) {
		printf("%d ", x[i]);
	 }  
	 
	 printf("\n\n");
        
    //ordenando o vetor

    for (i=0;i<DIM; i++) {
        for(j=i+1;j<DIM;j++)
        {
            if (x[i]>x[j])
            {
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }
    }
    /* Impressão do Vetor Ordenado */
    printf("\n");
    printf("Vetor em ordem crescente: \n");
        for(i=0;i<DIM;i++)
            printf(" %d",x[i]);
     printf("\n");
}
