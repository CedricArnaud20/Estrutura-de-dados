/*
    Grupo:
    4 periodo Eng de Software
        
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int uid;
    int pri;
    struct no *proximo;
}No;

void inserir_com_prioridade(No **fila, int num, int pri){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->uid = num;
        novo->pri = pri;
        novo->proximo = NULL;
        if(*fila == NULL)
            *fila = novo;
        else{
            // Ã© prioridade?
            if(pri >= 1){
                if((*fila)->pri != 1){ 
                    novo->proximo = *fila; 
                    *fila = novo;
                }
                else{
                    aux = *fila;
                    while(aux->proximo && aux->proximo->pri >= 1)
                        aux = aux->proximo;
                    novo->proximo = aux->proximo; 
                    aux->proximo = novo;
                }
            }
            else{
                aux = *fila;
                while(aux->proximo)
                    aux = aux->proximo;
                aux->proximo = novo;
            }
        }
    }
    else
        printf("\nErro ao alocar memoria.\n");
}

No* remover_da_fila(No **fila){
    No *remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = remover->proximo;
    }
    else
        printf("\tFila vazia\n");
    return remover;
}

void imprimir(No *fila){
    printf("\t------- FILA --------\n\t");
    while(fila){
        printf("%d /", fila->uid);
        fila = fila->proximo;
    }
    printf("\n\t------- FIM FILA --------\n");
}

int main(){
    No *r, *fila = NULL;
    int opcao, uid;
    int pri;

    do{
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Digite o UID do processo:");
            scanf("%d", &uid);
            printf("Digite 1 caso o processo tenha prioridade:");
            scanf("%d", &pri);
            inserir_com_prioridade(&fila, uid, pri);
            break;
        case 2:
            r = remover_da_fila(&fila);
            if(r){
                printf("Removido: %d\n", r->uid);
                free(r);
            }
            break;
        case 3:
            imprimir(fila);
            break;
        
        default:
            if(opcao != 0)
                printf("\nOpcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}
