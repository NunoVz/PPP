#include "header.h"

int main() {
    char texto[MAX_TEXTO];
    //Ler o texto e inserir numa variavel
    ler_texto(texto);
    char* palavratemp;
    //delimiters
    const char s[]=".,:;/()!?-_' '\"\n\r";
    palavratemp = strtok (texto,s);
    //iniciar a lista
    lista l = iniciar();

    //dividir o texto em palavras
    while (palavratemp != NULL){
        //inserir na lista
        colocar_ordenado(&l,palavratemp);
        palavratemp = strtok (NULL, s);}
    //Imprime a lista
    print(&l);
}
