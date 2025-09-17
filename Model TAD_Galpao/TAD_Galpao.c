#include "TAD_Galpao.h"

// Vamos iniciar a lista e chamamos a funcao inicializar lista vazia
void inicializar_galpao (Galpao *galpao){
    Lista_pacote lista;
    iniciar_lista_vazia(&lista);
    galpao->lista_de_pacotes = lista;
}

void receber_pacote_galpao(Galpao *galpao, Pacote *pacote){

    inserir_pacote_final(&galpao->lista_de_pacotes, pacote);
    
}

void carregamento_galpao(Galpao *galpao, Drone *drone){
    
    // verifica se consegue carregar o drone com o pacote 
    while (carregamento_drone(&drone, galpao->lista_de_pacotes.primeiro->pacote))
    {   // Remover o pacote da lista do galpao
        remover_pacote_inicio(&galpao->lista_de_pacotes, &galpao->lista_de_pacotes.primeiro->prox->pacote);
    }
    //Fazer o tratamento das excessoes
}

void imprimi_galpao(Galpao *galpao){

}
