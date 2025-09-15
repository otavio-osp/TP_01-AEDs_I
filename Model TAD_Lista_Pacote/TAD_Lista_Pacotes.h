#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Model TAD_Pacote/TAD_Pacote.h"

#ifndef TAD_LISTA_PACOTES_H
#define TAD_LISTA_PACOTES_H

#define maxtam 100

typedef struct
{

Pacote pacotes[maxtam];
int inicio, final;

}Lista_pacote;

//irá inicializar a lista vazia, retirando o lixo de memoria
void iniciar_lista_vazia (Lista_pacote *lista);

//Esta função irá inserir um pacote adicional ao final da lista
void inserir_pacote_final (Lista_pacote *lista, Pacote pacote);

//Esta função irá remover o pacote que esta no inicio da lista
void remover_pacote_inicio (Lista_pacote *lista);

//devera imprimir os dados dos pacotes que estão presentes na lista
void imprime_lista (Lista_pacote *lista);

#endif