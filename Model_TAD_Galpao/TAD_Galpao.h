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

void inicializar_galpao(Galpao *galpao);
void receber_pacote_galpao(Galpao *galpao, Pacote *pacote);
void carregamento_galpao(Galpao *galpao, Drone *drone);
void imprimi_galpao(Galpao *galpao);

#endif