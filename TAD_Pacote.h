#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{

    char conteudo[50];
    char destinatario[50];
    float peso;
    float distancia;

}pacote;

pacote inicializar_pacote(pacote *pacote, char conteudo[50], char destinatario[50], float peso, float distancia);

void set_conteudo(pacote *pacote, char conteudo[50]);
void set_destinatario(pacote *pacote, char destinatario[50]);
void set_peso(pacote *pacote, float peso);
void set_distancia_endereco(pacote *pacote, float distancia);

char get_conteudo(pacote *pacote);
char get_destinatario(pacote *pacote);
float get_peso(pacote *pacote);
float get_distancia_endereco(pacote *pacote);
