#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TAD_PACOTE_H
#define TAD_PACOTE_H


typedef struct{

    char conteudo[50];
    char destinatario[50];
    float peso;
    float distancia;

}Pacote;

//Inicialização do TAD Pacote
void inicializar_pacote(Pacote *pacote, char conteudo[50], char destinatario[50], float peso, float distancia);

//Atribuições de valores
void set_conteudo(Pacote *pacote, char conteudo[50]);
void set_destinatario(Pacote *pacote, char destinatario[50]);
void set_peso(Pacote *pacote, float peso);
void set_distancia_endereco(Pacote *pacote, float distancia);

//Obtenções de valores
char get_conteudo(Pacote *pacote);
char get_destinatario(Pacote *pacote);
float get_peso(Pacote *pacote);
float get_distancia_endereco(Pacote *pacote);

#endif