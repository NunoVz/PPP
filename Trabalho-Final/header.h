
#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void strtobase_u8(char *dest, const char *orig);
struct posicoes {
    struct posicoes *next;
    int pos;
};
struct node{
    char key[30];
    struct posicoes *tail;
    struct node *left, *right;
};
typedef struct {
    char word[1024];
    int posi;
}Data;
struct node* newNode(char* item,int number);
void byte_palavra(struct node* node, char* key, int k, FILE* ficheiro);
int compara(char*plvr1, char* plvrArvore);
void mostra_contexto(int posicao,FILE* ficheiro);
struct node* insert(struct node* node, char* key, int number);


#endif //HEADER_H
