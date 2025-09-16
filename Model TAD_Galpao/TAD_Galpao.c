#include "TAD_Galpao.h"
#include "../Model TAD_Lista_Pacote/TAD_Lista_Pacotes.h"
#include "../Model TAD_Drone/TAD_Drone.h"

void inicializar_galpao (Galpao *galpao, Lista_pacote lista){
    // DEBUG Muito provavel que isso mude, é apenas para ter uma ideia
    galpao->lista_de_pacotes = lista;
    
}

void receber_pacote(Galpao *galpao, Pacote pacote){
    
    inserir_pacote_final(&galpao->lista_de_pacotes, pacote);


}

void carregamento_galpao(Galpao *galpao, Drone *drone){
    // Remover o pacote da lista do galpao
    //jogar o pacote no drone
    //carregamento(&drone, Pacote *pacote)
    

    //Fazer o tratamento das excessoes

}

void imprimi_galpao(Galpao *galpao){

}
