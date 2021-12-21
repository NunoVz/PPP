#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

lista iniciar(){
    lista l={.entrada=0, .fim=0};
    for (int i = 0; i < TAMLISTA; ++i) {
        l.lista[i].ocupado= false;
        l.lista[i].no_seguinte= -1;
    }
    return l;
}
//Função que encontra nodes vazios
static int encontrar_no_vazio(lista *l){
    for (int i = 0; i < TAMLISTA; ++i) {
        if (l->lista[i].ocupado== false)
            return i;
    }
    return -1;
}

bool colocar_fim(lista * l,int ind) {

    l->lista[l->fim].no_seguinte=ind;
    l->lista[ind].no_seguinte= l->entrada;
    l->fim=ind;
    return true;
}

bool colocar_inicio(lista * l, int ind) {

    l->lista[ind].no_seguinte= l->entrada;
    l->entrada=ind;
    return true;
}
bool colocar_entre(lista * l, char* n, int ind) {
    //Vai verificar se a palavra seguinte tem prioridade sobre a palavra atua, se tiver a palavra é adcionada antes da palavra seguinte
    int no= l->entrada,noseguinte;
    char plvrseguinte[MAX_WORD];
    do{
        noseguinte=l->lista[no].no_seguinte;
        strtobase_u8(plvrseguinte,l->lista[noseguinte].palavra);
        if((plvrseguinte[1] > n[1]) || ((plvrseguinte[1] == n[1]) && (plvrseguinte[0] > n[0])) ||((plvrseguinte[1] == n[1]) && (plvrseguinte[0] == n[0]) && (strlen(plvrseguinte)>strlen(n)))){
            l->lista[no].no_seguinte=ind;
            l->lista[ind].no_seguinte=noseguinte;
            return true;
        }no=l->lista[no].no_seguinte;
    }while(no!=l->lista[l->fim].no_seguinte);
    return false;
}

bool colocar_ordenado(lista * l, char* n){
    //Ja existe?
    if(!ocorrencias(l,n)){return false;}

    //variaveis
    char word[MAX_WORD];
    char ultimaplvr[MAX_WORD];
    char primeiraplvr[MAX_WORD];
    //Ha nos disponiveis?
    int ind= encontrar_no_vazio(l);
    if(ind==-1) return false;

    //inserir a palavra no no
    strcpy(l->lista[ind].palavra, n);
    l->lista[ind].oco=1;
    l->lista[ind].ocupado= true;
    //simplifica e retira chars UTF8
    strtobase_u8(word,n);
    strtobase_u8(ultimaplvr,l->lista[l->fim].palavra);
    strtobase_u8(primeiraplvr,l->lista[l->entrada].palavra);
    //Onde colocar?
    //Fim?
    if((word[1] > ultimaplvr[1]) || ((word[1] == ultimaplvr[1]) && (word[0] > ultimaplvr[0])) ||((word[1] == ultimaplvr[1]) && (word[0] == ultimaplvr[0]) && (strlen(word)>strlen(ultimaplvr)))){return colocar_fim(l,ind);}
    //Inicio?
    else if((word[1] < primeiraplvr[1]) || ((word[1] == primeiraplvr[1]) && (word[0] < primeiraplvr[0])) ||((word[1] == primeiraplvr[1]) && (word[0] == primeiraplvr[0]) && (strlen(word)<strlen(primeiraplvr)))){return colocar_inicio(l,ind);}
    //Entre?
    else  return colocar_entre(l,word,ind);

}
bool ocorrencias(lista* l, char* n) {
    int no=l->entrada;
    do{
        if (!strcmp(l->lista[no].palavra, n)){l->lista[no].oco++;return false;}
        no=l->lista[no].no_seguinte;
    }while(no!=l->fim);if (!strcmp(l->lista[no].palavra, n)){l->lista[no].oco++;return false;}
    return true;
}

int maior(lista* l) {
    int no= l->entrada;
    if(l->lista[no].ocupado==false)return false;
    int maior=0,maiorind;
    do{
        if(l->lista[no].oco>maior){maior=l->lista[no].oco;maiorind=no;}
        no=l->lista[no].no_seguinte;
    }while(no!=l->fim);if(l->lista[no].oco>maior){maiorind=no;}
    return maiorind;

}
bool print(lista* l) {
    int no= l->entrada;
    if(l->lista[no].ocupado==false)return false;
    char word[MAX_WORD];
    strtobase_u8(word,l->lista[maior(l)].palavra);
    int ocoX=l->lista[maior(l)].oco;
    int espaco=85-(int)strlen(word);
    do{
        for (int i = 0; i < (l->lista[no].oco*espaco)/ocoX; ++i)printf(" ");printf("%s\n",l->lista[no].palavra);
        no=l->lista[no].no_seguinte;
    }while(no!=l->fim);for (int i = 0; i < (l->lista[no].oco*espaco)/ocoX; ++i)printf(" ");printf("%s\n",l->lista[no].palavra);
    return true;

}


