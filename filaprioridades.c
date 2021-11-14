#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


struct Aluno
{
    int ra;
    char nome[50];
};

struct Item
{
    aluno aluno;
    struct Item *proximo;
};

struct Fila
{
    Item *inicio;
    Item *fim;
};


void Inicializar(Fila **fila)
{
    // -> Recebe a fila por referencia
    //    para inicializá-la
    *fila = (Fila *) malloc(sizeof(Fila));
    (*fila)->inicio = NULL;
    (*fila)->fim = NULL;
}

int EstaVazia(Fila *fila)
{
    return fila->inicio == NULL;
}

void Inserir(Fila *fila, Aluno elemento)
{
    Item *novo;
    novo = (Item *)malloc(sizeof(Item));  

    // -> Verifica se a memória foi alocada com sucesso
    if (novo != NULL)
    {
        strcpy(novo->aluno.nome, elemento.nome);
        novo->aluno.ra = elemento.ra;
        novo->proximo = NULL;

        if(EstaVazia(fila))
        {
            // -> Primeiro Item da Fila.
            fila->inicio = novo;
            fila->fim = novo;
        }
        else
        {
            // -> Ultimo item da Fila
            fila->fim->proximo = novo;
            fila->fim=novo;
        }
    }
}

void Retirar(Fila *fila)
{
    Item *item;

    if(!EstaVazia(fila))
    {
        item = fila->inicio;
        fila->inicio = item->proximo;
        free(item);

        // -> Se a fila acabou devemos atualizar o final
        if (fila->inicio == NULL)
            fila->fim = NULL;
    }
}

void MostrarFila(Fila *fila)
{
    int i = 0;
    Item *item;
  
    printf("\n\n Listando...\n\n");
    printf("---------------------------------\n");

    if (EstaVazia(fila))
    {
        printf ("A Fila esta vazia!\n");
    }
    else
    {      
        item = fila->inicio;

        while(item != NULL)
        {
            i++;
            printf("[%i] -> %i - %s\n", i, item->aluno.ra, item->aluno.nome);
            item = item->proximo;
        }
    }

    printf("---------------------------------\n");
}


void Menu()
{
    printf( "Digite a sua escolha: \n"
        "    1 enfileirar elemento \n"
        "    2 retirar da fila \n"
        "    3 para finalizar \n"
        "? ");
}


void main()
{   
    Fila *fila = NULL;
    int opcao;
    Aluno aluno;

    Inicializar(&fila);
    Menu();
    scanf("%i", &opcao);

    while (opcao != 3)
    {

        switch (opcao)
        {
            case 1:
                printf( "Digite um RA: ");
                scanf("\n%i", &aluno.ra);

                printf( "Digite um Nome: ");
                scanf("\n%s", &aluno.nome);

                Inserir(fila, aluno);
                MostrarFila(fila);

                break;
            case 2:
                Retirar(fila);
                MostrarFila(fila);

                break;

            default:
                printf( "Escolha invalida.\n\n");
                Menu();
                break;
        }

        scanf("%i", &opcao);   
    }

    system("pause");
}
