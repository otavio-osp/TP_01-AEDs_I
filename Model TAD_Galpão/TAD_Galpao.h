#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_Lista_Pacotes.h"
#include "TAD_Drone.h"

typedef struct
{

lista_pacote lista_de_pacotes;

}galpao;

void inicializar_galpao (galpao *galpao, lista_pacote lista);

void receber_pacote(galpao *galpao, pacote pacote);
void carregamento (galpao *galpao, drone *drone);
void imprimi_galpao(galpao *galpao);