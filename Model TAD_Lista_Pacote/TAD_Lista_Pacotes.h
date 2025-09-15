#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Model TAD_Pacote/TAD_Pacote.h"

#ifndef TAD_LISTA_PACOTES_H
#define TAD_LISTA_PACOTES_H

#define maxtam 100

typedef struct
{
   
pacote pacotes[maxtam];
int inicio, final;

}lista_pacote;

void flvazia (lista_pacote *lista);
void insere (lista_pacote *lista, pacote pacote);
void remover (lista_pacote *lista);
void imprime_lista (lista_pacote *lista);

#endif