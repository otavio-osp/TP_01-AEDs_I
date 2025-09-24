#include "TAD_Galpao.h"
#include "../Model_TAD_Lista_Pacote/TAD_Lista_Pacotes.h"
#include "../Model_TAD_Drone/TAD_Drone.h"

// Vamos iniciar a lista e chamamos a funcao inicializar lista vazia
void inicializar_galpao(Galpao *galpao){
    Lista_pacote lista;
    iniciar_lista_vazia(&lista);
    galpao->lista_de_pacotes = lista;
}

void receber_pacote_galpao(Galpao *galpao, Pacote pacote){

    // Vai organizando os pacotes, por ordem de chegada, a medida que vai chegando pacotes
    inserir_pacote_final(&galpao->lista_de_pacotes, &pacote);
    
}

void carregamento_galpao(Galpao *galpao, Drone *drone){
    // Enquanto tiver item no galpão
    int num_viagem = 1;
    while (!ler_lista_vazia(&galpao->lista_de_pacotes))
    {        
        printf("\nCarregando drone com os pacotes!\n" );

        // Enquanto o drone suportar carga e tiver itens 
        while (!ler_lista_vazia(&galpao->lista_de_pacotes) && carga_suportada(drone, galpao->lista_de_pacotes.primeiro->prox->pacote.peso))
        {   // Retira o pacote do galpao
            Pacote pacote;
            remover_pacote_inicio(&galpao->lista_de_pacotes, &pacote);
            
            // Insere o pacote no drone
            carregamento_drone(drone, pacote);            
        }
        // Mostra o numero da viagem
        printf("\n-----------------------------------------\n");
        printf("\nViagem: %d\n", num_viagem++);
        // Realiza as entregas dos pacotes
        faz_entrega(drone);
    }
    printf("\nTodas as entregas realizadas!\n" );
    printf("Total de Quilometros Percorridos no Dia: %.0fKm", drone->distancia_total);
}

void imprimi_galpao(Galpao *galpao){
    //apenas teste para para de dar erro
    printf(galpao->lista_de_pacotes.primeiro->pacote.conteudo);
}
