#include "TAD_Drone.h"

drone inicializar_drone (drone *drone, float peso){
    drone->peso_max = peso;
    drone->peso_carregado = 0;
    drone->distancia_total = 0;

}

void carregamento (drone *drone, float peso, float distancia, lista_pacote lista){
drone->peso_carregado += peso;
drone->distancia_total += distancia;
drone->lista_de_entrega = lista;
}

void faz_entrega(drone *drone){
    //?????
}

void imprime_drone (drone *drone){
    printf("%f", drone->peso_max);
    printf("%f", drone->peso_carregado);
    printf("%f", drone->distancia_total);
    printf("%s", drone->lista_de_entrega); // posivel necessidade de mudança no tipo de dado que será impresso 
}