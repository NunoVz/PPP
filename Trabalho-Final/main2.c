#include "header.h"
int main(int argc,char *argv[]){
    FILE *ficheiro = NULL; char ficheiro_nome[1000];
    while (ficheiro == NULL) {
        if (argc == 2) {
            strcpy(ficheiro_nome,argv[1]);
            ficheiro = fopen(ficheiro_nome, "r");
        } else {
            printf("Indique o nome do ficheiro: ");
            scanf("%s", ficheiro_nome);
            ficheiro = fopen(ficheiro_nome, "r");
        }
        if (ficheiro == NULL) {
            printf("Erro!! volte a indicar o nome do ficheiro: ");
            scanf("%s", ficheiro_nome);
            ficheiro = fopen(ficheiro_nome, "r");
        }
    }

    struct node* node = NULL;
    char ficheiroBIN[1024]="pal_";
    int len = strlen(ficheiro_nome);
    ficheiro_nome[len-4] = '\0';
    strcat(ficheiroBIN,ficheiro_nome);strcat(ficheiroBIN,".bin");
    FILE *fIn=fopen(ficheiroBIN,"rb");
    Data d;
    while (fread(&d, sizeof(Data), 1, fIn)) {node=insert(node, d.word,d.posi);}
    fclose(fIn);

    while (1){
        char chave;int k;
        printf("\n------------------------------ ");
        printf("\n|1-> Procurar por palavra    |");
        printf("\n|2-> Procurar gama de palavra|");
        printf("\n|3-> Sair                    |");
        printf("\n------------------------------\n.....\n ");
        scanf("%d",&k);
        if(k==3){
            printf("\nPrograma vai ser terminado\n");fclose(fIn);fclose(ficheiro);return 0;}

        printf("\nIntroduza a palavra: ");
        scanf("%s",&chave);

        byte_palavra(node,&chave,k,ficheiro);

    }
}