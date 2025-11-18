#include "Model_TAD_Pacote/TAD_Pacote.h"
#include "Model_TAD_Drone/TAD_Drone.h"
#include "Model_TAD_Galpao/TAD_Galpao.h"
#include <time.h>

int main(){

    //inicio do tempo de execução
    clock_t inicio, fim;
    double tempo_total;
    int minutos, segundos, milissegundos;
    
    inicio = clock();

    // Declaração de variaveis
    int peso_max_drone = 0, quantidade_pacotes = 0, escolha = 0;

    //iniciaização de galpao
    Galpao galpao_BubbleSort;
    inicializar_galpao(&galpao_BubbleSort);
    Galpao galpao_ShellSort;
    inicializar_galpao(&galpao_ShellSort);

    Drone drone;

    // Escolha manual ou por arquivo
    printf("Escolha a forma de entrada de dados\n[1] Manual\n[2] Arquivo\n");
    //scanf("%d", &escolha);
    escolha = 2;

    switch (escolha){
        case 1: {// caso seja escolhido manual
            printf("\nDigite o peso maximo do drone: ");
            scanf("%d", &peso_max_drone);
            
            printf("Digite a quantidade de pacotes: ");
            scanf("%d", &quantidade_pacotes);
            
            // Inicializando drone
            inicializar_drone(&drone, peso_max_drone);
            
            // Preenchimento do galpão com pacotes de forma manual
            for (int i = 0; i < quantidade_pacotes; i++) {
                Pacote pacote;
                
                char conteudo[50], destinatario[50];
                int peso  = 0, distancia = 0, prioridade = 0;

                printf("\nPacote %d:\n", i+1);
                printf("Conteudo: ");
                scanf("%s", conteudo);
                printf("Destinatario: ");
                scanf("%s", destinatario);
                printf("Peso: ");
                scanf("%d", &peso);
                printf("Distancia: ");
                scanf("%d", &distancia);
                printf("Prioridade: ");
                scanf("%d", &prioridade);

                // Inicializamos o pacote com os dados
                inicializar_pacote(&pacote, conteudo, destinatario, peso, distancia, prioridade);

                
                // Recebimento dos pacotes
                receber_pacote_galpao(&galpao_BubbleSort, pacote);
                // receber_pacote_galpao(&galpao_ShellSort, pacote);
            }
            
            // Sistema de Gerenciamento de Entregas
            carregamento_galpao_BubbleSort(&galpao_BubbleSort, &drone);
            // carregamento_galpao_ShellSort(&galpao_ShellSort, &drone);
            break;
        }
        case 2: {// Caso seja escolhido entrada por arquivo
            char arquivo[20];

            printf("\nDigite o nome do arquivo desejado:\n(teste1.txt ou teste2.txt)\n");
            //scanf("%s", arquivo);
            strcpy(arquivo, "testedebug.txt");

            // Manipulação de arquivos
            FILE *file = fopen(arquivo, "r");
            if(file == NULL){
                printf("Arquivo nao identificado\n");
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

                // Utilizando os sets
                char conteudo[50], destinatario[50];
                int peso  = 0, distancia = 0, prioridade = 0;
                fscanf(file, "%s %s %d %d %d", conteudo, destinatario, &peso, &distancia, &prioridade);

                //inicializamos o pacote com os dados
                inicializar_pacote(&pacote, conteudo, destinatario, peso, distancia, prioridade);

                // Recebimento do pacote por galpao
                receber_pacote_galpao(&galpao_BubbleSort, pacote);
                receber_pacote_galpao(&galpao_ShellSort, pacote);
            }
            
            // Sistema de Gerenciamento de Entregas
            carregamento_galpao_BubbleSort(&galpao_BubbleSort, &drone);
            // carregamento_galpao_ShellSort(&galpao_ShellSort, &drone);
        
            fclose(file);

            // Fim do tempo de execução
            fim = clock();
            tempo_total = (double)(fim - inicio) / CLOCKS_PER_SEC;
    
            minutos = (int)tempo_total / 60;
            segundos = (int)tempo_total % 60;
            milissegundos = (int)((tempo_total - (int)tempo_total) * 1000);
            
            printf("\n-----------------------------------------\n");
            printf("\nTempo de execucao: %dmin, %dsec e %dms\n", minutos, segundos, milissegundos);
            printf("\n-----------------------------------------\n");


            break;
        }
        default: {
            printf("Escolha nao identificada\n");
            return 1;
    }
    }
    return 0;
}