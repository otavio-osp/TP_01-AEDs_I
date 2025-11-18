#include <stdio.h>
#include <stdlib.h>
#include "../Model_TAD_Lista_Pacote/TAD_Lista_Pacotes.h"
#include "../Model_TAD_Drone/TAD_Drone.h"

#ifndef TAD_GALPAO_H
#define TAD_GALPAO_H


typedef struct
{

Lista_pacote lista_de_pacotes;

}Galpao;

// Inicializa uma lista vazia no galpao
void inicializar_galpao(Galpao *galpao);
// Guarda os pacotes recebidos no galpao
void receber_pacote_galpao(Galpao *galpao, Pacote pacote);
// Insere os pacotes da lista do galpao no drone
void carregamento_galpao_BubbleSort(Galpao *galpao, Drone *drone);
// Impressão dos pacotes a serem entregues no dia
void carregamento_galpao_ShellSort(Galpao *galpao, Drone *drone);

void imprimi_galpao(Lista_pacote *lista);

#endif