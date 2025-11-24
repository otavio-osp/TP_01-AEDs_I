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
    
    double tempo_total;
    int minutos, segundos, milissegundos, num_comparacoes = 0, mov_itens = 0, troca = 0;

    Pacote pacote;
    Celula *aux_i, *aux_j;

    clock_t inicio, fim;
    inicio = clock();

    aux_i = lista->primeiro->prox;
    while (aux_i != NULL){
        troca = 0;

        // Reseta o aux_j para o inicio
        aux_j = lista->primeiro->prox;
        while (aux_j != NULL){
            num_comparacoes++;
            if(aux_j->prox != NULL && get_prioridade(&aux_j->pacote) < get_prioridade(&aux_j->prox->pacote)){
                mov_itens++;
                pacote = aux_j->prox->pacote;
                aux_j->prox->pacote = aux_j->pacote;
                aux_j->pacote = pacote;
                troca = 1;
            }
            aux_j = aux_j-> prox;
        }
        if (troca == 0){
            break;
        }

        aux_i = aux_i-> prox;
    }

    fim = clock();
    tempo_total = (double)(fim - inicio) / CLOCKS_PER_SEC;

    minutos = (int)tempo_total / 60;
    segundos = (int)tempo_total % 60;
    milissegundos = (int)((tempo_total - (int)tempo_total) * 100000);
    
    printf("\n-----------------------------------------\n");
    printf("\nDados BubbleSort: \n");
    printf("\nNumero de comparacoes: %d, Numero de movimentos: %d\n", num_comparacoes, mov_itens);
    printf("\nTempo de execucao: %dmin, %dsec e %dms\n", minutos, segundos, milissegundos);
    printf("\n-----------------------------------------\n");

}

void ShellSort(Lista_pacote *lista, int n){
    double tempo_total;
    int minutos, segundos, milissegundos, num_comparacoes = 0, mov_itens = 0, cnt = 0, k = 0, h = 1;
    Pacote pacote;
    Celula *menor, *maior, *segura_posicao_menor, *segura_posicao_maior, *ultima_comparacao;

    clock_t inicio, fim;
    inicio = clock();

    do h = h * 3 + 1; while (h < n);

    //Vamos andando conforme h, porem em subgrupos
    do{
        // inicia o menor e maior como inicial
        h = h/3;
        menor = lista->primeiro->prox; maior = lista->primeiro->prox;

        // Faz andar de h em h
        cnt = 0; while (maior != NULL && cnt < h){maior = maior->prox;cnt++; }
        
        while (maior != NULL){

            // Segura as posições para usarmos depois
            segura_posicao_menor = menor; segura_posicao_maior = maior;
            num_comparacoes++; 
            // Enquanto aquele não for a maior prioridade ele muda
            while (menor != NULL && maior != NULL && get_prioridade(&menor->pacote) < get_prioridade(&maior->pacote)){
                // Conta quantos movimentos foram necessarios para ordenar
                mov_itens++;
                // Troca as posições 
                pacote = maior->pacote; maior->pacote = menor->pacote; menor->pacote = pacote;
                // Como a verificação trocou os valores estamos consertando
                maior = menor;
                // Resetamos a lista pois com lista encadeada não tem como retroceder indice
                menor = lista->primeiro->prox;
                // Descobre a posição onde estava o menor caso, para começar a contagem de h em h posteriormente
                int pos_index = 0, pos_inicial = 0;
                while (menor != NULL && menor != segura_posicao_menor) {pos_index++;menor = menor->prox;}
                if (menor != NULL) {     //Verificamos se o h não é zero pq isso quebra a logica
                    pos_inicial = pos_index % (h==0?1:h);
                } else {
                    pos_inicial = 0;
                }
                // Resetamos novamente para agora sim fazer ela começar do primeiro elemento
                menor = lista->primeiro->prox;

                // Agora andamos pos_inicial passos para achar o primeiro elemento do subgrupo
                cnt = 0;
                while (menor != NULL && cnt < pos_inicial){menor = menor->prox;cnt++;}
                // Usado para verificar o ultimo elemento dentro de um determinado subgrupo
                ultima_comparacao = NULL;
                while (menor != NULL && menor != maior){
                    // Guardamos o primeiro elemento daquele subgrupo / o ultimo antes do maior
                    ultima_comparacao = menor;

                    // Rodamos ate encontrar o maior (andando de 1 em 1 mas com limite h)
                    cnt = 0;
                    while (menor != NULL && menor != maior && cnt < h){ menor = menor->prox;cnt++;}
                    
                    if (menor == NULL) break;
                }

                if (ultima_comparacao != NULL){
                    menor = ultima_comparacao;
                } else {
                    //volta ao início do subgrupo
                    menor = lista->primeiro->prox;
                    cnt = 0;
                    while (menor != NULL && cnt < pos_inicial){
                        menor = menor->prox;
                        cnt++;
                    }
                }
                // Se encontrarmos o maior antes do tamanho de h quer dizer que ele ja esta ordenado dentro dessa fase de h
                if (cnt < h){
                    break;
                }
                num_comparacoes++;
            } 
            
            // restaurar posições guardadas (como antes)
            menor = segura_posicao_menor; maior = segura_posicao_maior;
            
            // Proximo caso (avançar ponteiros um nó à frente como antes)
            if (maior != NULL){maior = maior->prox;}
            if (menor != NULL){menor = menor->prox;}
            k++;

        
        } 

    } while (h != 1);
    
    fim = clock();
    tempo_total = (double)(fim - inicio) / CLOCKS_PER_SEC;
    
    minutos = (int)tempo_total / 60;
    segundos = (int)tempo_total % 60;
    milissegundos = (int)((tempo_total - (int)tempo_total) * 100000);
    
    printf("\n-----------------------------------------\n");
    printf("\nDados ShellSort: \n");
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
