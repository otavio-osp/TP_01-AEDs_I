#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Model TAD_Lista_Pacote/TAD_Lista_Pacotes.h"

#ifndef TAD_DRONE_H
#define TAD_DRONE_H

typedef struct
{
    
float peso_max;
float peso_carregado;
float distancia_total;
lista_pacote lista_de_entrega;

}drone;

drone inicializar_drone (drone *drone, float peso);

void carregamento(drone *drone, float peso, float distancia, lista_pacote lista);
void faz_entrega(drone *drone);
void imprime_drone (drone *drone);

#endif