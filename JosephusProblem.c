//Autor: José Antônio Alves De Freitas Filho
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct lista_jogadores
{
    char nome[31];
    struct lista_jogadores *next;
    struct lista_jogadores *tail;
    struct lista_jogadores *head;    
    
}list;

list *aloca()
{
    return malloc(sizeof(list));
}

void new_name(list *head, int i,int fim)
{
    list *aux, *novo;
    char nome[31];
    aux = head;
    while( aux->next != NULL)
    {
        aux = aux->next; //vai procurar para achar o ultimo no
    }

    scanf("%s",nome);
    getchar();
    novo = aloca();
    strcpy(novo->nome, nome );
    if(i==0)
    {
        novo -> next = NULL;
        aux -> head = novo;
        aux->next = novo;

    }
    else
    {
        novo -> next = NULL;
        aux -> next = novo;
    }
    if(i==fim)
    {
        aux-> tail = novo;
    }
    
}
void exclui_nome(list *swap, list *swap2)
{
    swap = swap2->next; //swap 2 é armazenado anteriormente para não quebrar a lista
    swap2->next = swap->next;//swap next é atruido ao swap2 para pular um item da lista
    free(swap);
}
//função para caso o nome excluído seja o head
void if_excluded_head(list *atual, list *inicio)
{
        if(atual == inicio->head)
    {
        inicio->head = inicio->head->next;
        if(inicio->head==NULL)//esse caso é para quando a head
        {
            inicio->head = inicio->head->next;

        }
    }
}


char *procura_nome(int *size, int num_escolhido, list *head)
{
    list *aux, *swap, *inicio, *swap2;
    int i;
    inicio = aux = head;

while(1)
{
    for(i=0 ; i<num_escolhido; i++)
    {
        if((aux -> next == NULL))
        {                
            aux-> next = inicio->head;
        
        }
        if(aux->next == inicio->tail)
        {
            aux-> next = inicio->head;   
        }
        else
        {
            swap2 = aux;
            aux = aux-> next;
        }
    }

    if(*size==1){ 
        return aux->nome;
    } 
    if_excluded_head(aux,inicio);

    exclui_nome(swap,swap2);

    --(*size);
    }
}

int main()
{
    list *JOGADOR;
    int qtd_jogadores, num_escolhido;
    int i;
    JOGADOR = aloca();
    JOGADOR -> next = NULL;

    scanf("%d %d",&qtd_jogadores, &num_escolhido);
    getchar();

    for(i=0; i<qtd_jogadores; i++)
    {
        new_name(JOGADOR, i,qtd_jogadores-1);
    }

    printf("%s\n",procura_nome(&qtd_jogadores,num_escolhido, JOGADOR));
    free(JOGADOR);
    return 0;
}
