#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_Pacote.h"
#define maxtam 100

typedef struct
{
   
pacote pacotes[maxtam];
int inicio, final;

}lista_pacote;

void flvazia (lista_pacote *lista);
void insere (lista_pacote *lista, pacote pacote);
void remove (lista_pacote *lista);
void imprime_lista (lista_pacote *lista);