#include "TAD_Drone.h"

void inicializar_drone (Drone *drone, int peso){
    drone->peso_max = peso;
    drone->peso_carregado = 0;
    drone->distancia_total = 0;
    Lista_pacote lista;
    iniciar_lista_vazia(&lista);
    drone->lista_de_entrega = lista;
}


int carga_suportada(Drone *drone, int peso){
    if ((drone->peso_carregado + peso) > drone->peso_max){
        printf("\nDrone esta cheio e pronto para a entrega!\n");
        printf("\n-----------------------------------------\n" ); 
        return 0;
    }
    return 1;
}

// antes de ser chamada deve ser verificado se a carga é suportada
int carregamento_drone(Drone *drone, Pacote pacote){
    //Adiciona o pacote no drone
    inserir_pacote_final(&drone->lista_de_entrega, &pacote);

    //Adiciona o peso do pacote ao drone
    drone->peso_carregado += pacote.peso;
    
    return 1;
}

void faz_entrega(Drone *drone){
    // Utilizado para marcar posição atual do drone em relação a ultima entrega/galpao
    int posicao_atual = 0;
           // Enquanto o drone ainda tiver entregas para fazer
    while (!ler_lista_vazia(&drone->lista_de_entrega))
    {   
        // Remove o pacote do drone, para realizar entrega
        Pacote pacote;
        remover_pacote_inicio(&drone->lista_de_entrega, &pacote);
        
        // Distancia que o drone percorre partindo da base ou da última entrega para a próxima
        posicao_atual = pacote.distancia - posicao_atual;
        
        // Somamos o modulo, pois, ele pode percorrer direções opostas à ultima entrega/galpão
        drone->distancia_total += (posicao_atual < 0) ? -(posicao_atual) : posicao_atual;

        // Atualiza a posição do drone de acordo com a entrega realizada
        posicao_atual = pacote.distancia;

        // Imprime qual foi a entrega realizada
        imprime_drone(*drone, pacote);
    }
    
    // O drone retorna para o galpão ao final do percurso
    drone->distancia_total += posicao_atual;
    //todas as entregas foram realizadas
    drone->peso_carregado = 0;

    printf("\nVoltando para o galpao!\n" );
    
}

void imprime_drone(Drone drone, Pacote pacote){
    printf("O conteudo da entrega: %s\n", get_conteudo(&pacote)); 
    printf("Foi enviado para: %s\n", get_destinatario(&pacote));
    printf("Percorreu esta distancia: %d\n", get_distancia_endereco(&pacote));
    printf("O drone percorreu ate entao: %.0f\n", drone.distancia_total); 
    printf("-----------------------------------------\n" ); 
}