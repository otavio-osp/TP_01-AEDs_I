#include "Model TAD_Pacote/TAD_Pacote.h"
#include "Model TAD_Lista_Pacote/TAD_Lista_Pacotes.h"
#include "Model TAD_Drone/TAD_Drone.h"
#include "Model TAD_Galpao/TAD_Galpao.h"

int main(){
//Sistema de Gerenciamento de Entregas


    Galpao galpao1;
    //para implementar a inicialização precisamos fazer o model TAD_Lista_Pacotes.c
    inicializar_galpao(&galpao1);

    Drone drone1;
    inicializar_drone(&drone1, 10);

    Pacote pacote1;
    inicializar_pacote(&pacote1, "Remedio", "joao", 2, 10);

    Pacote pacote2;
    inicializar_pacote(&pacote1, "Comida", "]feien", 1, 20);

    Pacote pacote3;
    inicializar_pacote(&pacote1, "poapp", "ossa", 2, 10);

    // - Recebimento
    //para implementar receber
    receber_pacote_galpao(&galpao1, pacote1);
    receber_pacote_galpao(&galpao1, pacote2);
    receber_pacote_galpao(&galpao1, pacote3);

    carregamento_galpao(&galpao1, &drone1);


    printf("hello world");
    return 0;
}