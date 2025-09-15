#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Model TAD_Lista_Pacote/TAD_Lista_Pacotes.h"
#include "../Model TAD_Drone/TAD_Drone.h"

#ifndef TAD_GALPAO_H
#define TAD_GALPAO_H


typedef struct
{

lista_pacote lista_de_pacotes;

}galpao;

void inicializar_galpao (galpao *galpao, lista_pacote lista);

void receber_pacote(galpao *galpao, pacote pacote);
void carregamento_galpao(galpao *galpao, drone *drone);
void imprimi_galpao(galpao *galpao);

#endif