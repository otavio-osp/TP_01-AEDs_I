#include "TAD_Lista_Pacotes.h"

void iniciar_lista_vazia (Lista_pacote *lista)
{
    lista-> primeiro = (Celula*) malloc(sizeof(Celula));
    lista-> ultimo = lista-> primeiro;
    lista-> primeiro-> prox = NULL;
}

int ler_lista_vazia (Lista_pacote *lista){
    return (lista-> primeiro == lista-> ultimo);
}

int inserir_pacote_final (Lista_pacote *lista, Item * p_item)
{
    lista-> ultimo-> prox = (Celula*) malloc(sizeof(Celula));
    lista-> ultimo = lista-> ultimo-> prox;
    lista-> ultimo-> item = *p_item;
    lista-> ultimo-> prox = NULL;
}

int remover_pacote_inicio (Lista_pacote *lista, Item * p_item)
{
 Celula * aux;
 if (ler_lista_vazia(lista))
 return 0;
 *p_item = lista-> primeiro-> prox-> item;
 aux = lista-> primeiro;
 lista-> primeiro = lista-> primeiro-> prox;
 free(aux);
 return 1;
}

void imprime_lista (Lista_pacote *lista)
{
    Celula * aux;
    aux = lista-> primeiro-> prox;
 while (aux != NULL)
 {
 printf("%d\n", aux-> item.chave);
 aux = aux-> prox;
 }
}