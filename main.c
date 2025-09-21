#include "Model_TAD_Pacote/TAD_Pacote.h"
#include "Model_TAD_Lista_Pacote/TAD_Lista_Pacotes.h"
#include "Model_TAD_Drone/TAD_Drone.h"
#include "Model_TAD_Galpao/TAD_Galpao.h"

int main(){
    // Declaração de variiaveis
    int peso_max_drone, quantidade_pacotes;
    Galpao galpao;
    Drone drone;

    // Manipulação de arquivos
    FILE *file = fopen("teste1.txt", "r");
    fscanf(file, "%d", &peso_max_drone);
    fscanf(file, "%d", &quantidade_pacotes);
    
    // inicializando galpão e drone
    inicializar_galpao(&galpao);
    inicializar_drone(&drone, peso_max_drone);
    
    // Peenximento do galpão com pacotes lidos em arquivo
    for (int i = 0; i < quantidade_pacotes; i++){
        Pacote pacote;
        fscanf(file, "%s %s %d %d", pacote.conteudo, pacote.destinatario, &pacote.peso, &pacote.distancia);
        // Recebimento do pacotes
        receber_pacote_galpao(&galpao, &pacote);
    }
    
    //Sistema de Gerenciamento de Entregas
    carregamento_galpao(&galpao, &drone);

    fclose(file);

    return 0;
}