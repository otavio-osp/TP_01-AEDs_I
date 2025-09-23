#include "Model_TAD_Pacote/TAD_Pacote.h"
#include "Model_TAD_Lista_Pacote/TAD_Lista_Pacotes.h"
#include "Model_TAD_Drone/TAD_Drone.h"
#include "Model_TAD_Galpao/TAD_Galpao.h"



int main(){
    // Declaração de variaveis
    int peso_max_drone = 0, quantidade_pacotes = 0, escolha = 0;

    //iniciaização de galpao
    Galpao galpao;
    inicializar_galpao(&galpao);

    Drone drone;

    // Escolha manual ou por arquivo
    printf("Escolha a forma de entrada de dados\n[1] Manual\n[2] Arquivo\n");
    //scanf("%d", &escolha);
    escolha = 2;

    switch (escolha){
        case 1: {// caso seja escolhido manual
            printf("Digite o peso maximo do drone: ");
            scanf("%d", &peso_max_drone);
            
            printf("Digite a quantidade de pacotes: ");
            scanf("%d", &quantidade_pacotes);
            
            // Inicializando drone
            inicializar_drone(&drone, peso_max_drone);
            
            // Preenchimento do galpão com pacotes de forma manual
            for (int i = 0; i < quantidade_pacotes; i++) {
                Pacote pacote;
                
                printf("\nPacote %d:\n", i+1);
                printf("Conteudo: ");
                scanf("%s", pacote.conteudo);
                printf("Destinatario: ");
                scanf("%s", pacote.destinatario);
                printf("Peso: ");
                scanf("%d", &pacote.peso);
                printf("Distancia: ");
                scanf("%d", &pacote.distancia);
                
                // Recebimento dos pacotes
                receber_pacote_galpao(&galpao, pacote);
            }
            
            //Sistema de Gerenciamento de Entregas
            carregamento_galpao(&galpao, &drone);
            break;
        }
        case 2: {// Caso seja escolhido entrada por arquivo
            char arquivo[20];

            printf("\nDigite o nome do arquivo desejado:\n(teste1.txt ou teste2.txt)\n");
            //scanf("%s", arquivo);
            strcpy(arquivo, "teste1.txt");

            // Manipulação de arquivos
            FILE *file = fopen(arquivo, "r");
            if(file == NULL){
                printf("Arquivo não identificado\n");
                return 0;
            }

            // Os 2 primeiros valores serão para inicialização de drones e preenchimento dos pacotes
            fscanf(file, "%d", &peso_max_drone);
            fscanf(file, "%d", &quantidade_pacotes);
            
            // inicializando drone
            inicializar_drone(&drone, peso_max_drone);
            
            // Preenchimento do galpão com pacotes lidos em arquivo
            for (int i = 0; i < quantidade_pacotes; i++){
                Pacote pacote;
                //modificar isso para utilizar os sets e get
                fscanf(file, "%s %s %d %d", pacote.conteudo, pacote.destinatario, &pacote.peso, &pacote.distancia);
                // Recebimento do pacotes
                receber_pacote_galpao(&galpao, pacote);
            }
            
            //Sistema de Gerenciamento de Entregas
            carregamento_galpao(&galpao, &drone);
        
            fclose(file);
            break;
        }
        default: {
            printf("Escolha não identificada\n");
            return 1;
    }
    }
    return 0;
}