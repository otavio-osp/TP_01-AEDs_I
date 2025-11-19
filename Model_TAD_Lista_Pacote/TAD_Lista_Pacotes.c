#include "TAD_Lista_Pacotes.h"

void iniciar_lista_vazia (Lista_pacote *lista){
    lista->primeiro = (Celula*) malloc(sizeof(Celula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
}

int lista_eh_vazia (Lista_pacote *lista){
    return (lista->primeiro == lista->ultimo);
}

void BubbleSort(Lista_pacote *lista){
    clock_t inicio, fim;
    double tempo_total;
    int minutos, segundos, milissegundos;
    
    inicio = clock();

    int num_comparacoes = 0, mov_itens = 0;

    int troca = 0;
    Pacote pacote;
    Celula *aux_i, *aux_j;
    aux_i = lista->primeiro->prox;
    while (aux_i != NULL){
        troca = 0;

        // Reseta o aux_j para o inicio
        aux_j = lista->primeiro->prox;
        while (aux_j != NULL){
            /*if (aux_j->prox != NULL ){
            printf("%s , ", get_destinatario(&aux_j->pacote));
            printf(" %d < ", get_prioridade(&aux_j->pacote));

            printf("%s , ", get_destinatario(&aux_j->prox->pacote));
            printf(" %d   \n", get_prioridade(&aux_j->prox->pacote));
            }*/
            num_comparacoes++;
            if(aux_j->prox != NULL && get_prioridade(&aux_j->pacote) < get_prioridade(&aux_j->prox->pacote)){
                mov_itens++;
                pacote = aux_j->prox->pacote;
                aux_j->prox->pacote = aux_j->pacote;
                aux_j->pacote = pacote;
                troca = 1;
                //imprimi_testes(lista);
            }
            aux_j = aux_j-> prox;
        }
        //imprimi_testes(lista);
        if (troca == 0){
            break;
        }

        aux_i = aux_i-> prox;
    }

    fim = clock();
    tempo_total = (double)(fim - inicio) / CLOCKS_PER_SEC;

    minutos = (int)tempo_total / 60;
    segundos = (int)tempo_total % 60;
    milissegundos = (int)((tempo_total - (int)tempo_total) * 1000);
    
    printf("\n-----------------------------------------\n");
    printf("\nNumero de comparacoes: %d, Numero de movimentos: %d\n", num_comparacoes, mov_itens);
    printf("\nTempo de execucao: %dmin, %dsec e %dms\n", minutos, segundos, milissegundos);
    printf("\n-----------------------------------------\n");

}

void ShellSort(Lista_pacote *lista, int n){
    clock_t inicio, fim;
    double tempo_total;
    int minutos, segundos, milissegundos;
    
    inicio = clock();
    int num_comparacoes = 0, mov_itens = 0;

    int cnt = 0, k = 0, h = 1;
    Pacote pacote;
    Celula *menor, *maior, *segura_posicao_menor, *segura_posicao_maior, *ultima_comparacao;
    

    do h = h * 3 + 1; while (h < n);

    //Vamos andando conforme h, porem em subgrupos
    do{
        //inicia o menor e maior como inicial
        h = h/3;menor = lista->primeiro->prox;maior = lista->primeiro->prox;

        // Faz andar de h em h
        cnt = 0; while (maior != NULL && cnt < h){maior = maior->prox;cnt++; }
        
        while (maior != NULL){

            // Printa a pergunta no debug
            if (maior != NULL){printf("%s , %d < %s ,  %d ", get_destinatario(&menor->pacote), get_prioridade(&menor->pacote), get_destinatario(&maior->pacote), get_prioridade(&maior->pacote));}
            
            // Segura as posições para usarmos depois
            segura_posicao_menor = menor; segura_posicao_maior = maior;

            // Conta o numero de comparações feitas.
            num_comparacoes++;
            // Enquanto aquele não for a maior prioridade ele muda
            printf("%d ", num_comparacoes);
            while(get_prioridade(&menor->pacote) < get_prioridade(&maior->pacote)){
                //printf("Verdadeiro Vamos trocar e verificar se tem outro menor");
                // Conta quantos movimentos foram necessarios para ordenar
                mov_itens++;
                
                // Troca as posições 
                pacote = maior->pacote; maior->pacote = menor->pacote; menor->pacote = pacote;
                //imprimi_testes(lista);
                
                // Como a verificação trocou os valores estamos consertando
                maior = menor;

                // Resetamos a lista pois com lista encadeada não tem como retroceder indice
                menor = lista->primeiro->prox;

                // Vamos começar no primeiro item daquele subgrupo
                cnt = 0;
                while (menor != NULL && cnt < k%h){menor = menor->prox;cnt++;}

                // Imprime informações
                //if (menor != NULL){printf("\n Comecando dessa pessoa: %s , %d Vamos andar de %d \n", get_destinatario(&menor->pacote), get_prioridade(&menor->pacote), h);}

                // Usado para verificar o ultimo elemento dentro de um determinado subgrupo
                while (menor != maior){
                    
                    // Guardamos o primeiro elemento daquele subgrupo / o ultimo antes do maior
                    ultima_comparacao = menor;

                    // Rodamos ate encontrar o maior
                    cnt = 0;
                    while (menor != NULL && menor != maior && cnt < h){
                        menor = menor->prox;
                        cnt++;
                        //if (maior != NULL){
                        //    printf("\n%s , %d == %s ,  %d\n\n", get_destinatario(&menor->pacote), get_prioridade(&menor->pacote), get_destinatario(&maior->pacote), get_prioridade(&maior->pacote));
                        //}   
                        }
                    
                }

                menor = ultima_comparacao;

                // Se encontrarmos o maior antes do tamanho de h quer dizer que ele ja esta ordenado dentro dessa fase de h
                //if (maior != NULL){printf("\n%d < %d \n", cnt, h);}
                if (cnt<h){
                    break;
                }
                
                //if (maior != NULL){printf("\n%s , %d < %s ,  %d   \n", get_destinatario(&menor->pacote), get_prioridade(&menor->pacote), get_destinatario(&maior->pacote), get_prioridade(&maior->pacote));}
            }
            
            menor = segura_posicao_menor; maior = segura_posicao_maior;
            
            // Proximo caso
            if (maior != NULL){maior = maior->prox;}
            if (menor != NULL){menor = menor->prox;}
            k++;

            imprimi_testes(lista);
        }
        //printf("Saiu do primeiro while");
        //imprimi_testes(lista);
    } while (h != 1);
    
    
    
    fim = clock();
    tempo_total = (double)(fim - inicio) / CLOCKS_PER_SEC;
    
    minutos = (int)tempo_total / 60;
    segundos = (int)tempo_total % 60;
    milissegundos = (int)((tempo_total - (int)tempo_total) * 1000);
    
    printf("\n-----------------------------------------\n");
    printf("\nNumero de comparacoes: %d, Numero de movimentos: %d\n", num_comparacoes, mov_itens);
    printf("\nTempo de execucao: %dmin, %dsec e %dms\n", minutos, segundos, milissegundos);
    printf("\n-----------------------------------------\n");

}

void inserir_pacote_final (Lista_pacote *lista, Pacote *pacote){
    lista->ultimo->prox = (Celula*) malloc(sizeof(Celula));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->pacote = *pacote;
    lista->ultimo->prox = NULL;
}

//Recebe a lista a ter seu item removido e devolve esse item atravez do parametro pacote
int remover_pacote_inicio (Lista_pacote *lista, Pacote * pacote){
 Celula * aux;
 if (lista_eh_vazia(lista)){return 0;}
 *pacote = lista->primeiro->prox->pacote;
 aux = lista->primeiro;
 lista->primeiro = lista->primeiro->prox;
 free(aux);
 return 1;
}

void imprime_lista (Lista_pacote *lista){
    Celula * aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        printf("Conteudo: %s\n", get_conteudo(&aux->pacote));
        printf("Destinatario: %s\n", get_destinatario(& aux->pacote));
        printf("Distancia: %d\n",get_distancia_endereco(&aux->pacote));
        printf("Peso: %d\n", get_peso(&aux->pacote));
        printf("----------------------------------/n/n");
        aux = aux-> prox;
    }
}

void imprimi_testes(Lista_pacote *lista){
    Celula * aux;
    aux = lista->primeiro->prox;
    printf("\n\n");
    while (aux != NULL)
    {
        printf("%s , ", get_destinatario(&aux->pacote));
        printf(" %d | ", get_prioridade(&aux->pacote));
        
        aux = aux-> prox;
    }
    printf("\n-----------------------------------------------------------------------------------------------------------------------------------------\n\n");
}
