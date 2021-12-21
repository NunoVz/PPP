#include <stdbool.h>
#include <stdio.h>

void matrizfuncao(int comp,int lag,int matriz[lag][comp]){
    //valores do ret
    int compR=comp-4;
    int lagR=lag-4;
    //Calculo do centro da tela(Se algum comprimento da tela for par o "centro" vai ser uma aproximação pois estamos a trabalhar com numeros inteiros
    int centrox=comp/2, centroy=lag/2,iniciox,fimx,inicioy,fimy;
    //Calculos de onde o ret vai começar e onde vai acabar.. https://imgur.com/DS3Npzf
    iniciox=centrox-(compR-1)/2;
    fimx=centrox+(compR-1)/2;
    inicioy=centroy-(lagR-1)/2;
    fimy=centroy+(lagR-1)/2;
    //no caso de ser par temos que adcionar mais um ao ret pois ao fazer divisoes com int casas decimais são perdidas
    if(!(compR%2)){iniciox--;}
    if(!(lagR%2)){inicioy--;}
    for (int i = lag-1; i >= 0; --i) {
        for (int j = 0; j < comp; ++j) {
            if ((iniciox<=j && fimx>=j) && (inicioy<=i && fimy>=i))
                //Em função das cordenadas da matriz se o ret ocupar o espaço a esse ponto será atribuido um 0
                matriz[i][j]=0;
            else
                //Se não é atribuido um 1
                matriz[i][j]=1;

        }
    }
}
//Verificar se a tela esta dentro dos valores especificados no enunciado
bool verificartela(int x){
    return (x>=10 && x<=20);
}
//Caso deseje ver a matriz bidimensional
bool verificarimprimirtela(int x){
    return (x==1||x==0);
}

void converte(int lag,int comp,int matriz[lag][comp]){
    for (int i = lag-1; i >= 0; --i ){
        for (int j = 0; j < comp; ++j) {
            //Se for 0 significa que a figura esta ocupada logo B
            if(matriz[i][j]==0)
                printf("B ");
                //Se for 1 e atrás de si ou a frente for um 0 significa que esta adjacente logo [, a ultima condição faz com que os valores i j não ultrapassem os defenidos na matriz
            else if(matriz[i][j]==1 && (matriz[i][j+1]==0||matriz[i][j-1]==0) && (((j<comp&&j>0)&&i<lag-1)))
                printf("[ ");
                //So sobra os espaços(1), logo ^
            else
                printf("^ ");

        }
        printf("\n");
    }


}