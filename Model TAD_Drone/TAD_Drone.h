#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Model TAD_Lista_Pacote/TAD_Lista_Pacotes.h"

#ifndef TAD_DRONE_H
#define TAD_DRONE_H

typedef struct
{
    
int peso_max;
int peso_carregado;
int distancia_total;
Lista_pacote lista_de_entrega;

}Drone;

// Inicia os valores do drone para não ter lixo de memoria,
// também inicializamos o valor maximo que ele consegue carregar.
Drone inicializar_drone (Drone *drone, int peso);

// Adiciona o pacote na lista, armazenando dentro do drone,
int carregamento_drone(Drone *drone, Pacote pacote);

// Retira da lista do drone as entregas a medida que as entregas vao sendo feitas
// e incrementa a distancia percorrida 
void faz_entrega(Drone *drone);

// imprime as informações dos pacotes que o drone esta carregando
void imprime_drone (Drone *drone);

#endif