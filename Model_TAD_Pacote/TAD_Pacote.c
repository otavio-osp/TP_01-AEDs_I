#include "TAD_Pacote.h"

void inicializar_pacote(Pacote *pacote, char conteudo[50], char destinatario[50], int peso, int distancia){
    strcpy(pacote->conteudo, conteudo);
    strcpy(pacote->destinatario, destinatario);
    pacote->peso = peso;
    pacote->distancia = distancia;
}

void set_conteudo(Pacote *pacote, char conteudo[50]){
    strcpy(pacote->conteudo, conteudo);
}

void set_destinatario(Pacote *pacote, char destinatario[50]){
    strcpy(pacote->destinatario, destinatario);
}

void set_peso(Pacote *pacote, int peso){
    pacote->peso = peso;
}

void set_distancia_endereco(Pacote *pacote, int distancia){
    pacote->distancia = distancia;
}

const char *get_conteudo(const Pacote *pacote){
    return pacote->conteudo;
}

const char *get_destinatario(const Pacote *pacote){
    return pacote->destinatario;
}

int get_peso(const Pacote *pacote){
    return pacote->peso;
}

int get_distancia_endereco(const Pacote *pacote){
    return pacote->distancia;
}
