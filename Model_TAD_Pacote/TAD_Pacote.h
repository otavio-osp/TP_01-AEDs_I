#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TAD_PACOTE_H
#define TAD_PACOTE_H


typedef struct{

    char conteudo[50];
    char destinatario[50];
    int peso;
    int distancia;

}Pacote;

//Inicialização do TAD Pacote
void inicializar_pacote(Pacote *pacote, char conteudo[50], char destinatario[50], int peso, int distancia);

//Atribuições de valores
void set_conteudo(Pacote *pacote, char conteudo[50]);
void set_destinatario(Pacote *pacote, char destinatario[50]);
void set_peso(Pacote *pacote, int peso);
void set_distancia_endereco(Pacote *pacote, int distancia);

//Obtenções de valores
char get_conteudo(Pacote *pacote);
char get_destinatario(Pacote *pacote);
int get_peso(Pacote *pacote);
int get_distancia_endereco(Pacote *pacote);

#endif