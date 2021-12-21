#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define TAMLISTA 3000
#define MAX_WORD 128
#define MAX_TEXTO 3001

bool ler_texto(char *ptexto);// Função fornecida no e-mail
void strtobase_u8(char *dest, const char *orig); // Biblioteca de funções para processar multibyte characters em C, v2 2021-03-19 João Gabriel Silva

typedef struct Sno {
    char palavra [MAX_WORD];
    int oco;
    int no_seguinte;
    bool ocupado;
} no;

typedef struct Slista {
    no lista[TAMLISTA];
    int entrada;
    int fim;
} lista;

lista iniciar();

bool ocorrencias(lista* l, char* n);
//Funções que se encarragam dos ponteiros entre nodes
bool colocar_fim(lista * l,int ind);
bool colocar_inicio(lista * l,int ind);
bool colocar_entre(lista * l, char* n,int ind);
//Função que se encarrega de definir as variaveis dentro do node e dizer onde é que deve ser introduzida
bool colocar_ordenado(lista * l, char* n);


bool print(lista* pf);

#endif //HEADER_H
