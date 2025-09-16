#include "TAD_Drone.h"

Drone inicializar_drone (Drone *drone, float peso){
    drone->peso_max = peso;
    drone->peso_carregado = 0;
    drone->distancia_total = 0;
}

void carregamento (Drone *drone, Pacote pacote){

    //verifica se o drone suporta a carga
    if ((drone->peso_carregado + pacote.peso) > drone->peso_max){
        printf("Carga não suportada!");
        return;
    }
    drone->peso_carregado += pacote.peso;
    drone->distancia_total += pacote.distancia;
    //drone->lista_de_entrega = lista;

}

void faz_entrega(Drone *drone){
    //?????
    //acredito que é aqui onde deveria ser calculado a distancia total
}

void imprime_drone (Drone *drone){
    printf("%f", drone->peso_max);
    printf("%f", drone->peso_carregado);
    printf("%f", drone->distancia_total);
    printf("%s", drone->lista_de_entrega); // posivel necessidade de mudança no tipo de dado que será impresso 
}