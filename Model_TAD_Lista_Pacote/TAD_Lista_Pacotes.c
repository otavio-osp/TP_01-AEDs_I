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

void ShellSort(Lista_pacote *lista){
    clock_t inicio, fim;
    double tempo_total;
    int minutos, segundos, milissegundos;
    
    inicio = clock();
    int num_comparacoes = 0, mov_itens = 0;

    /*
    Implementação a ser feita aqui
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    */
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
    printf("\n");
    while (aux != NULL)
    {
        printf("%s , ", get_destinatario(&aux->pacote));
        printf(" %d   | ", get_prioridade(&aux->pacote));
        
        aux = aux-> prox;
    }
    printf("\n----------------------------------\n\n");
}
