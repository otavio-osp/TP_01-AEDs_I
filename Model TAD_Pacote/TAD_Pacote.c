#include "TAD_Pacote.h"

pacote inicializar_pacote(pacote *pacote, char conteudo[50], char destinatario[50], float peso, float distancia){
    strcpy(pacote->conteudo, conteudo);
    strcpy(pacote->destinatario, destinatario);
    pacote->peso = peso;
    pacote->distancia = distancia;
}

void set_conteudo(pacote *pacote, char conteudo[50]){
    strcpy(pacote->conteudo, conteudo);
}

void set_destinatario(pacote *pacote, char destinatario[50]){
    strcpy(pacote->destinatario, destinatario);
}

void set_peso(pacote *pacote, float peso){
    pacote->peso = peso;
}

void set_distancia_endereco(pacote *pacote, float distancia){
    pacote->distancia = distancia;
}

char get_conteudo(pacote *pacote){
    return pacote->conteudo;
}

char get_destinatario(pacote *pacote){
    return pacote->destinatario;
}

float get_peso(pacote *pacote){
    return pacote->peso;
}

float get_distancia_endereco(pacote *pacote){
    pacote->distancia;
}
