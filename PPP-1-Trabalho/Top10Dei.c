//A minha interpetação do problema:
//Gerar numa tela um retangulo numa matriz bidimensional int
//função validação 10<=x<=20 (Bool)!!
//Funçao para desenhar na tela ->0 se o desenho ocupar esta cordenada 1 se não ocupar
//Ret tem que estar centrado na tela
//Ret tem que estar a 2 espaços das bordas
//matriz[0][0]=canto inferior esquerdo
//função converte espaço->^,Ocupado->B, espaços com a figura adjacente->[
#include <stdbool.h>
#include <stdio.h>

void matrizfuncao(int comp,int lag,int matriz[lag][comp]);
bool verificartela(int x);
bool verificarimprimirtela(int x);
void converte(int lag,int comp,int matriz[lag][comp]);

int main() {
    int comp,lag,z;
    //Valores da tela
    printf("Insira os valores da tela (10>=Valor<=20)....");
    do{printf("\nComp:");scanf("%d",&comp);}while(!verificartela(comp));
    do{printf("\nLarg:");scanf("%d",&lag);}while(!verificartela(lag));

    int matriz[lag][comp];
    //Função matriz
    matrizfuncao(comp,lag,matriz);
    do{printf("\nDeseja ver a tela?(1-Sim|0-Não)-->");scanf("%d",&z);}while(!verificarimprimirtela(z));
    if (z==1){
        printf("\n---------------Matriz---------------\n");
        for (int i = lag-1; i >= 0; --i ){
            for (int j = 0; j < comp; ++j) {
                printf("%d ",matriz[i][j]);

            }
            printf("\n");
        }
        printf("\n\n---------------Figura---------------\n");
    }
    converte(lag,comp,matriz);

}